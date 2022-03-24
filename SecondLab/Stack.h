#pragma once

typedef struct Unit
{
	int data;
	Unit* next;
} Unit; //������� �����

//Unit* top; //������� ����� 

class Stack
{
private:
	Unit* top = 0; //��������� �� ��������� ������� ����� - ������������������ �������
	int size = 0; //������ �����
public:
	//������������
	Stack(); //����������� ��� ����������
	explicit Stack(int size_st); //����� ����������� � ����������� (������ ������ �����)
	~Stack(); //����������
	Stack(const Stack& Stack_copy); //����������� �����������

	//������� �����
	void push(int value); //���������� �������� � ����
	int pop(); //���������� �������
	void print(); //����� ����� �� �����

	//������� � �������
	Unit* get_top(); //����� ������� �����
	void set_size(int& value); //��������� �������� � ����
	int get_size() const; //����� ������ �����
	Stack& method(int l, Stack& r, int Var);
	//������������� ���������
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
