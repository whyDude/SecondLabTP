
#include "Stack.h"
#include "Real.h"
#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int stack_size = 0, value = 0; //���������� ������� ����� � �������� ������
	int flag = 1, c; 

	///////////////////////////////////////////////////////������� �2

	cout << "��� ������������ ��������� 2-�� ������������ �� ��!" << endl;
	cout << "������� �2 - �������� �������� (����)\n������� ������ �����: ";
	cin >> stack_size;
	system("cls");

	Stack st;
	srand(time(NULL));
	for (int i = 0; i < stack_size; i++)
		st.push(rand() % 21 + 10);

	while (flag == 1)
	{
		cout << "��������, ����� �������� �������� �� ������:" << endl;
		cout << "1 - ���������� ������ �������� � ����" << endl;
		cout << "2 - �������� �������� �� �����" << endl;
		cout << "3 - ����� ����� �� �����" << endl;
		cout << "4 - �������� ��������� (���� �����)" << endl;
		cout << "5 - �������� ��������� (���� ������)" << endl;
		cout << "6 - �������� ������� (���� �����)" << endl;
		cout << "7 - �������� ������� (���� ������)" << endl;
		cout << "8 - �������� �������� (���� �����)" << endl;
		cout << "9 - �������� �������� (���� ������)" << endl;
		cout << "10 - �������� ��������� (���� �����)" << endl;
		cout << "11 - �������� ��������� (���� ������)" << endl;
		cout << "12 - ��������� ��������� � ��� �� ������� (*=,/=,+=,-=)" << endl;
		cout << "0 - ������� �� ������� ������� ������" << endl;
		cout << "--> ";
		cin >> c;

		switch (c)
		{
		case 1: //1 - ���������� ������ �������� � ����
			system("cls");
			cout << "������� ��������: " << endl;
			cin >> value;
			st.push(value);
			cout << "�������� ��������� � ����\n " << endl;
			break;
		case 2: //2 - �������� �������� �� �����
			if (!st.get_size())
			{
				cout << "���� ����, ��������� ������.\n " << endl;
				break;
			}
			else
			{
				system("cls");
				value = st.pop();
				cout << "����������� �������: " << value << endl;
			}
			break;
		case 3: //3 - ����� ����� �� �����
			if (!st.get_size())
			{
				cout << "���� ����, �������� ������.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				st.print();
				cout << "\n";
			}
			break;
		case 4: //4 - �������� ��������� (���� �����)
			if (!st.get_size())
			{
				cout << "���� ����, ���������� �������� ��������.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "������� �����, �� ������� ������ ��������: ";
				cin >> value;
				st = st * value;
				cout << "�������� ������ �������! ������������ ����: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 5: //5 - �������� ��������� (���� ������)
			if (!st.get_size())
			{
				cout << "���� ����, ���������� �������� ��������.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "������� �����, ������� ������ ��������: ";
				cin >> value;
				st = value * st;
				cout << "�������� ������ �������! ������������ ����: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 6: //6 - �������� ������� (���� �����)
			if (!st.get_size())
			{
				cout << "���� ����, ���������� �������� ��������.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "������� �����, �� ������� ������ ��������: ";
				cin >> value;
				st = st / value;
				cout << "�������� ������ �������! ������������ ����: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 7: //4 - �������� ������� (���� ������)
			if (!st.get_size())
			{
				cout << "���� ����, ���������� �������� ��������.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "������� �����,  ������� ������ ��������: ";
				cin >> value;
				st = value / st;
				st.print();
				cout << "\n";
			}
			break;
		case 8: //8- �������� �������� (���� �����)
			if (!st.get_size())
			{
				cout << "���� ����, ���������� �������� ��������.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "������� �����, � ������� ������ �������: ";
				cin >> value;
				st = st + value;
				cout << "�������� ������ �������! ������������ ����: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 9: //9 - �������� ��������� (���� ������)
			if (!st.get_size())
			{
				cout << "���� ����, ���������� �������� ��������.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "������� �����, � ������� ������ �������: ";
				cin >> value;
				st = value + st;
				cout << "�������� ������ �������! ������������ ����: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 10: //10 - �������� ��������� (���� �����)
			if (!st.get_size())
			{
				cout << "���� ����, ���������� �������� ��������.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "������� �����, �� ������� ������ ��������: ";
				cin >> value;
				st = st - value;
				cout << "�������� ������ �������! ������������ ����: " << endl;
				st.print();
				cout << "\n";
			}
			break;
		case 11: //10 - �������� ��������� (���� ������)
			if (!st.get_size())
			{
				cout << "���� ����, ���������� �������� ��������.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "������� �����, �� ������� ������ ��������: ";
				cin >> value;
				st = value - st;
				st.print();
				cout << "\n";
			}
			break;
		case 12: //12 - ��������� (=)
			if (!st.get_size())
			{
				cout << "���� ����, ���������� �������� ��������.\n" << endl;
				break;
			}
			else
			{
				system("cls");
				cout << "������� �����, � ������� ������ �������� ��������: ";
				cin >> value;
				st *= value;
				st.print();
				st /= value;
				st.print();
				st += value;
				st.print();
				st -= value;
				st.print();
				cout << "�������� ������ �������!" << endl;
				cout << "\n";
			}
			break;
		case 0: //0 - �����
			cout << "\n";
			flag = 0;
			break;
		default:
			cout << "\n";
			flag = 0;
			break;
		}
	}

	/////////////////////////////////////////////////////////������� �1
	system("cls");

	float input_num1;
	Real num1, num2;
	num2 = 0;

	cout << "������� �1 - ������� ���������\n" << endl;
	flag = 1;
	cout << "������� ���� �����:";
	cin >> input_num1;
	num1 = input_num1;
	while (flag == 1)
	{
		cout << "��������, ����� �������� �������� � ������� ������������ �����:" << endl;
		cout << "1 - ++ ���������� (+=0.5)" << endl;
		cout << "2 - ++ ����������� (+=2,5)" << endl;
		cout << "3 - -- ���������� (-=0.1)" << endl;
		cout << "4 - -- ����������� (-=0,2)" << endl;
		cout << "0 - �����" << endl;
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
		case 0: //0 - �����
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

	
