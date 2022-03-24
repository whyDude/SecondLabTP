#include "Stack.h"
#include <iostream>


using namespace std;

/* КОНСТРУКТОРЫ */

Stack::Stack() : top(0), size(0) {} //конструктор без параметров (исп. список инициализации)

Stack::Stack(int size_st) : top(0)//конструктор с параметром, задает размер и инициализирует элемент
{
	srand(time(NULL));
	for (int i = 0; i < size_st; i++)
		this->push(rand()%21+10);
}

Stack::~Stack()
{
	if ((top == 0) || (size == 0))
	{
		delete top; //удаляем вершину
		size = 0; //размер нулевой
	}
	else
	{
		while (top->next != 0) //пока не дойдем до нулевого указателя
		{
			Unit* temp = top; //временная переменная юнита, присваиваем ей значение вершины
			top = temp->next; //теперь вершина указывает на следующий за ней элемент,
			delete temp; //а временную - удаляеям
		}
		delete top; //удаляем вершину
		size = 0; //размер нулевой
	}
}

Stack::Stack(const Stack& Stack_copy) : size(Stack_copy.size)
{
	int* buff = new int[Stack_copy.size]; //вводим буферный массив, в котором будем хранить наши числа нового стека
	Unit* el_stack = Stack_copy.top; //новая переменная-вершина будущего стека

	for (int i = 0; i <= Stack_copy.size - 1; i++)
	{	//пока счетчик не дойдет до конца стека
		buff[i] = el_stack->data; //заносим в массив значения из стека
		el_stack = el_stack->next; //ставим указатель на следующий элемент стека
	}

	for (int i = 0; i < Stack_copy.size; i++)
		this->push(buff[i]); //вносим в новый стек значения из массива

	delete[] buff; //удаляем буфер
}

/* МЕТОДЫ КЛАССА СТЕКА */

void Stack::push(int value)
{
	Unit* new_unit = new Unit; //инициализируем новый юнит стека и выделяем под него память
	new_unit->next = top; //теперь новый юнит стал вершиной
	top = new_unit; //и вершина указывает на новый юнит
	top->data = value; //вносим значение в вершину
	size++;
}

int Stack::pop()
{
	setlocale(LC_ALL, "Rus");

	if (!this)
	{
		cout << "Стек пуст, удалять нечего." << endl;
	}

	Unit* temp = top; //временная переменная-вершина 
	int deldata = 0; //место под удаленный элемент

	deldata = top->data; //присваиваем значение удаляемого элемента
	top = top->next; //вершина теперь тот юнит, который был под вершиной
	delete temp; //удаляем переменную-вершину
	size--;
	return deldata; //вернули удаленный элемент
}

void Stack::print()
{
	if (size == 0)
	{
		cout << "Стек пуст, выводить нечего." << endl;
		return;
	}
	else
	{
		Unit* temp = top;
		while (temp->next != nullptr)
		{
			cout << temp->data << " <-- ";
			temp = temp->next;
		}

		cout << temp->data << endl;
	}
}

Unit* Stack::get_top()
{
	return top;
}

int Stack::get_size() const
{
	return size;
}

void Stack::set_size(int& value)
{
	size = value;
}

Stack& Stack::operator *(int r) 
{
	return method(r, *this, 0);
}
Stack& Stack::operator /(int r)
{
	return method(r, *this, 1);
}
Stack& Stack::operator +(int r)
{
	return method(r, *this, 2);
}
Stack& Stack::operator -(int r)
{
	return method(r, *this, 3);
}
Stack& Stack::method(int l, Stack& r, int Var)
{
	Unit* tmp = this->top;

	if (size == 0)
	{
		cout << "Стек пуст, невозможно провести операцию!" << endl;
	}
	else
	{
		while (tmp != nullptr)
		{
			tmp = tmp->next;
		}
	}
	int len = this->size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop();
	//вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		switch (Var)
		{
		case 0:
			this->push(buff[i] * l); //в обратном порядке (как было до преобразования) заносим новые значения в стек
			break;
		case 1:
			this->push(buff[i] / l); //в обратном порядке (как было до преобразования) заносим новые значения в стек
			break;
		case 2:
			this->push(buff[i] + l); //в обратном порядке (как было до преобразования) заносим новые значения в стек
			break;
		case 3:
			this->push(buff[i] - l); //в обратном порядке (как было до преобразования) заносим новые значения в стек
			break;
		/*
		* case 4:
		* this->push(buff[i]);
		* l-=buff[i]
		* break;
		* тожу самое только другой тип возвращаемого значения
		*/
		}
		


	delete[] buff;
	return *this;


}

Stack& operator *(int l, Stack& r)
{
	return r * l;
}
Stack& operator /(int l, Stack& r)
{
	cout << "U can't  num / stack, stack returned, check Stack .cpp" << endl;
	return r;// check method()
	//Еще был вариант поделить все число на каждый элемент стека, но это как-то странно
}
Stack& operator +(int l, Stack& r)
{
	return r + l;
}
Stack& operator -(int l, Stack& r)
{
	cout << "U can't  do num - stack, stack returned, check Stack .cpp" << endl;
	return r;
}


Stack& Stack::operator *=(int r)
{
	return method(r, *this, 0);
}
Stack& Stack::operator /=(int r)
{
	return method(r, *this, 1);
}
Stack& Stack::operator +=(int r)
{
	return method(r, *this, 2);
}
Stack& Stack::operator -=(int r)
{
	return method(r, *this, 3);
}