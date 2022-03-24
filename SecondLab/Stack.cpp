#include "Stack.h"
#include <iostream>


using namespace std;

/* ������������ */

Stack::Stack() : top(0), size(0) {} //����������� ��� ���������� (���. ������ �������������)

Stack::Stack(int size_st) : top(0)//����������� � ����������, ������ ������ � �������������� �������
{
	srand(time(NULL));
	for (int i = 0; i < size_st; i++)
		this->push(rand()%21+10);
}

Stack::~Stack()
{
	if ((top == 0) || (size == 0))
	{
		delete top; //������� �������
		size = 0; //������ �������
	}
	else
	{
		while (top->next != 0) //���� �� ������ �� �������� ���������
		{
			Unit* temp = top; //��������� ���������� �����, ����������� �� �������� �������
			top = temp->next; //������ ������� ��������� �� ��������� �� ��� �������,
			delete temp; //� ��������� - ��������
		}
		delete top; //������� �������
		size = 0; //������ �������
	}
}

Stack::Stack(const Stack& Stack_copy) : size(Stack_copy.size)
{
	int* buff = new int[Stack_copy.size]; //������ �������� ������, � ������� ����� ������� ���� ����� ������ �����
	Unit* el_stack = Stack_copy.top; //����� ����������-������� �������� �����

	for (int i = 0; i <= Stack_copy.size - 1; i++)
	{	//���� ������� �� ������ �� ����� �����
		buff[i] = el_stack->data; //������� � ������ �������� �� �����
		el_stack = el_stack->next; //������ ��������� �� ��������� ������� �����
	}

	for (int i = 0; i < Stack_copy.size; i++)
		this->push(buff[i]); //������ � ����� ���� �������� �� �������

	delete[] buff; //������� �����
}

/* ������ ������ ����� */

void Stack::push(int value)
{
	Unit* new_unit = new Unit; //�������������� ����� ���� ����� � �������� ��� ���� ������
	new_unit->next = top; //������ ����� ���� ���� ��������
	top = new_unit; //� ������� ��������� �� ����� ����
	top->data = value; //������ �������� � �������
	size++;
}

int Stack::pop()
{
	setlocale(LC_ALL, "Rus");

	if (!this)
	{
		cout << "���� ����, ������� ������." << endl;
	}

	Unit* temp = top; //��������� ����������-������� 
	int deldata = 0; //����� ��� ��������� �������

	deldata = top->data; //����������� �������� ���������� ��������
	top = top->next; //������� ������ ��� ����, ������� ��� ��� ��������
	delete temp; //������� ����������-�������
	size--;
	return deldata; //������� ��������� �������
}

void Stack::print()
{
	if (size == 0)
	{
		cout << "���� ����, �������� ������." << endl;
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
		cout << "���� ����, ���������� �������� ��������!" << endl;
	}
	else
	{
		while (tmp != nullptr)
		{
			tmp = tmp->next;
		}
	}
	int len = this->size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = this->pop();
	//������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
		switch (Var)
		{
		case 0:
			this->push(buff[i] * l); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
			break;
		case 1:
			this->push(buff[i] / l); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
			break;
		case 2:
			this->push(buff[i] + l); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
			break;
		case 3:
			this->push(buff[i] - l); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
			break;
		/*
		* case 4:
		* this->push(buff[i]);
		* l-=buff[i]
		* break;
		* ���� ����� ������ ������ ��� ������������� ��������
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
	//��� ��� ������� �������� ��� ����� �� ������ ������� �����, �� ��� ���-�� �������
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