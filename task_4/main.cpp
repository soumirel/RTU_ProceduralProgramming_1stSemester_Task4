#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	// Переменные необходимые для работы главных функций
	int input_task;
	bool flag = true;
	// Переменные для решения задач
	fstream file;
	string temp_str;
	double input_number;
	double sum = 0;
	//
	while (flag)
	{
		cout << "Введите номер задания, которое хотите проверить." << endl;
		cout << "Если вы хотите закончить проверку - введите 0" << endl;
		cin >> input_task;
		switch (input_task)
		{
		case(0):
			flag = false;
			break;
		case(1):
			cout << "Задание: ";
			cout << "Файл" << endl;
			//
			file.open("file_for_task_1.txt", ios::out);
			cout << "Введите 10 чисел:" << endl;
			for (size_t i = 0; i < 10; i++)
			{
				while (!(cin >> input_number))
				{
					cout << "Вы ввели не число. Пожалуйста, введите число:\n";
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
			cout << "Сумма введенных чисел равна " << sum << endl;
			break;
		case(2):
			cout << "Задание: ";
			cout << "" << endl;
			break;
		case(3):
			cout << "Задание: ";
			cout << "" << endl;
			break;
		case(4):
			cout << "Задание: ";
			cout << "" << endl;
			break;
		case(5):
			cout << "Задание: ";
			cout << "" << endl;
			break;
		case(6):
			cout << "Задание: ";
			cout << "" << endl;
			break;
		case(7):
			cout << "Задание: ";
			cout << "" << endl;
			break;
		case(8):
			cout << "Задание: ";
			cout << "" << endl;
			break;
		case(9):
			cout << "Задание: ";
			cout << "" << endl;
			break;
		default:
			cout << "Я не понимаю вас." << endl;
			break;
		}
	}
}