#pragma once

typedef struct Unit
{
	int data;
	Unit* next;
} Unit; //элемент стека

//Unit* top; //вершина стека 

class Stack
{
private:
	Unit* top = 0; //указатель на начальный элемент стека - инициализированный элемент
	int size = 0; //размер стека
public:
	//конструкторы
	Stack(); //конструктор без параметров
	explicit Stack(int size_st); //явный конструктор с параметрами (задаем размер стека)
	~Stack(); //деструктор
	Stack(const Stack& Stack_copy); //конструктор копирования

	//функции стека
	void push(int value); //добавление элемента в стек
	int pop(); //извлечение вершины
	void print(); //вывод стека на экран

	//геттеры и сеттеры
	Unit* get_top(); //взять элемент стека
	void set_size(int& value); //поместить значение в стек
	int get_size() const; //взять размер стека
	Stack& method(int l, Stack& r, int Var);
	//перегруженные операторы
	Stack& operator *(int r); 
	friend Stack& operator *(int l, Stack& r);
	Stack& operator /(int r); 
	friend Stack& operator /(int l, Stack& r);
	Stack& operator +(int r);
	friend Stack& operator +(int l, Stack& r);
	Stack& operator -(int r);
	friend Stack& operator -(int l, Stack& r);
	Stack& operator *=(int r);
	Stack& operator /=(int r);
	Stack& operator +=(int r);
	Stack& operator -=(int r);
};
