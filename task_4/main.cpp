#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	// ���������� ����������� ��� ������ ������� �������
	int input_task;
	bool flag = true;
	// ���������� ��� ������� �����
	fstream file;
	string temp_str;
	double input_number;
	double sum = 0;
	//
	while (flag)
	{
		cout << "������� ����� �������, ������� ������ ���������." << endl;
		cout << "���� �� ������ ��������� �������� - ������� 0" << endl;
		cin >> input_task;
		switch (input_task)
		{
		case(0):
			flag = false;
			break;
		case(1):
			cout << "�������: ";
			cout << "����" << endl;
			//
			file.open("file_for_task_1.txt", ios::out);
			cout << "������� 10 �����:" << endl;
			for (size_t i = 0; i < 10; i++)
			{
				while (!(cin >> input_number))
				{
					cout << "�� ����� �� �����. ����������, ������� �����:\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				file << input_number;
				if (i != 9) { file << endl; }
			}
			file.close();
			//
			file.open("file_for_task_1.txt", ios::in);

			while (!file.eof())
			{
				getline(file, temp_str);
				sum += stoi(temp_str);
				cout << sum << endl;
			}
			cout << "����� ��������� ����� ����� " << sum << endl;
			break;
		case(2):
			cout << "�������: ";
			cout << "" << endl;
			break;
		case(3):
			cout << "�������: ";
			cout << "" << endl;
			break;
		case(4):
			cout << "�������: ";
			cout << "" << endl;
			break;
		case(5):
			cout << "�������: ";
			cout << "" << endl;
			break;
		case(6):
			cout << "�������: ";
			cout << "" << endl;
			break;
		case(7):
			cout << "�������: ";
			cout << "" << endl;
			break;
		case(8):
			cout << "�������: ";
			cout << "" << endl;
			break;
		case(9):
			cout << "�������: ";
			cout << "" << endl;
			break;
		default:
			cout << "� �� ������� ���." << endl;
			break;
		}
	}
}