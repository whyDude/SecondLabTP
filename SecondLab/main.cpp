
#include "Stack.h"
#include "Real.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int stack_size = 0, value = 0; //переменные размера стека и вводимых данных
	int flag = 1, c; 

	///////////////////////////////////////////////////////ЗАДАНИЕ №2

	cout << "Вас приветствует программа 2-ой лабораторной по ТП!" << endl;
	cout << "Задание №2 - Бинарные операции (Стек)\nВведите размер стека: ";
	cin >> stack_size;
	system("cls");

	Stack st;
	srand(time(NULL));
	for (int i = 0; i < stack_size; i++)
		st.push(rand() % 21 + 10);

	while (flag == 1)
	{
		cout << "Выберите, какие операции провести со стеком:" << endl;
		cout << "1 - Добавление нового элемента в стек" << endl;
		cout << "2 - Удаление элемента из стека" << endl;
		cout << "3 - Вывод стека на экран" << endl;
		cout << "4 - Оператор умножения (стек слева)" << endl;
		cout << "5 - Оператор умножения (стек справа)" << endl;
		cout << "6 - Оператор деления (стек слева)" << endl;
		cout << "7 - Оператор деления (стек справа)" << endl;
		cout << "8 - Оператор сложения (стек слева)" << endl;
		cout << "9 - Оператор сложения (стек справа)" << endl;
		cout << "10 - Оператор вычитания (стек слева)" << endl;
		cout << "11 - Оператор вычитания (стек справа)" << endl;
		cout << "12 - Остальные операторы в том же порядке (*=,/=,+=,-=)" << endl;
		cout << "0 - Переход ко второму заданию работы" << endl;
		cout << "--> ";
		cin >> c;

		switch (c)
		{
		case 1: //1 - Добавление нового элемента в стек
			system("cls");
			cout << "Введите значение: " << endl;
			cin >> value;
			st.push(value);
			cout << "Значение добавлено в стек\n " << endl;
			break;
		case 2: //2 - Удаление элемента из стека
			if (!st.get_size())
			{
				cout << "Стек пуст, извлекать нечего.\n " << endl;
				break;
			}
			else
			{
				system("cls");
				value = st.pop();
				cout << "Извлеченный элемент: " << value << endl;
			}
			break;
		case 3: //3 - Вывод стека на экран
			if (!st.get_size())
			{
				cout << "Стек пуст, выводить нечего.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				st.print();
				cout << "\n";
			}
			break;
		case 4: //4 - оператор умножения (стек слева)
			if (!st.get_size())
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "Введите число, на которое хотите умножить: ";
				cin >> value;
				st = st * value;
				cout << "Операция прошла успешно! Получившийся стек: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 5: //5 - оператор умножения (стек справа)
			if (!st.get_size())
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "Введите число, которое хотите умножить: ";
				cin >> value;
				st = value * st;
				cout << "Операция прошла успешно! Получившийся стек: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 6: //6 - оператор деления (стек слева)
			if (!st.get_size())
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "Введите число, на которое хотите поделить: ";
				cin >> value;
				st = st / value;
				cout << "Операция прошла успешно! Получившийся стек: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 7: //4 - оператор деления (стек справа)
			if (!st.get_size())
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "Введите число,  которое хотите поделить: ";
				cin >> value;
				st = value / st;
				st.print();
				cout << "\n";
			}
			break;
		case 8: //8- оператор сложения (стек слева)
			if (!st.get_size())
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "Введите число, с которым хотите сложить: ";
				cin >> value;
				st = st + value;
				cout << "Операция прошла успешно! Получившийся стек: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 9: //9 - оператор умножения (стек справа)
			if (!st.get_size())
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "Введите число, с которым хотите сложить: ";
				cin >> value;
				st = value + st;
				cout << "Операция прошла успешно! Получившийся стек: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 10: //10 - оператор вычитания (стек слева)
			if (!st.get_size())
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "Введите число, на которое хотите умножить: ";
				cin >> value;
				st = st - value;
				cout << "Операция прошла успешно! Получившийся стек: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 11: //10 - оператор вычитания (стек справа)
			if (!st.get_size())
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "Введите число, на которое хотите умножить: ";
				cin >> value;
				st = value - st;
				st.print();
				cout << "\n";
			}
			break;
		case 12: //12 - остальное (=)
			if (!st.get_size())
			{
				cout << "Стек пуст, невозможно провести операцию.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "Введите число, с которым хотите провести действия: ";
				cin >> value;
				st *= value;
				st.print();
				st /= value;
				st.print();
				st += value;
				st.print();
				st -= value;
				st.print();
				cout << "Операция прошла успешно!" << endl;
				cout << "\n";
			}
			break;
		case 0: //0 - Выход
			cout << "\n";
			flag = 0;
			break;
		default:
			cout << "\n";
			flag = 0;
			break;
		}
	}

	/////////////////////////////////////////////////////////ЗАДАНИЕ №1
	system("cls");

	float input_num1;
	Real num1, num2;
	num2 = 0;

	cout << "Задание №1 - Унарные операторы\n" << endl;
	flag = 1;
	cout << "Введите свое число:";
	cin >> input_num1;
	num1 = input_num1;
	while (flag == 1)
	{
		cout << "Выберите, какие операции провести с классом вещественных чисел:" << endl;
		cout << "1 - ++ префиксная (+=0.5)" << endl;
		cout << "2 - ++ постфиксная (+=2,5)" << endl;
		cout << "3 - -- префиксная (-=0.1)" << endl;
		cout << "4 - -- постфиксная (-=0,2)" << endl;
		cout << "0 - Выход" << endl;
		cout << "--> ";
		cin >> c;

		switch (c)
		{
		case 1: //1 - ++num
			system("cls");
			num2 = ++num1;
			cout << "num2 = " << num2.get_num() << ", num1 = " << num1.get_num() << endl;
			break;
		case 2: //2 -num++
			system("cls");
			num2 = num1++;
			cout << "num2 = " << num2.get_num() << ", num1 = " << num1.get_num() << endl;
			break;
		case 3: //3 - --num
			system("cls");
			num2 = --num1;
			cout << "num2 = " << num2.get_num() << ", num1 = " << num1.get_num() << endl;
			break;
		case 4: //4 - num--
			system("cls");
			num2 = num1--;
			cout << "num2 = " << num2.get_num() << ", num1 = " << num1.get_num() << endl;
			break;
		case 0: //0 - Выход
			cout << "\n";
			flag = 0;
			break;
		default:
			cout << "\n";
			flag = 0;
			break;
		}
	}

	return 0;
}

	
