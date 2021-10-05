#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

const double PI = 3.141592653589793;

// Function for input correct number 
double input_num_with_check()
{
	double input_number;
	while (!(cin >> input_number) || input_number < 0 || input_number == 0)
	{
		cout << "Вы ввели некорректное число. Пожалуйста, введите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input_number;
}

// Task 1
double ex_number()
{

	fstream file;
	string temp_str;

	double input_number;
	double sum = 0;

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

	file.open("file_for_task_1.txt", ios::in);
	while (!file.eof())
	{
		getline(file, temp_str);
		sum += stoi(temp_str);
	}
	return sum;
}

// Task 2
int sign(int x)
{
	if (x == 0) { return 0; }
	if (x > 0) { return 1; }
	if (x < 0) { return -1; }
}

// Task 3.1 Rectangle
void rectangle()
{
	double side_1, side_2;
	cout << "Введите параметры фигуры, необходимые для поиска площади.\n";
	cout << "1ая сторона = ";
	side_1 = input_num_with_check();
	cout << "2ая сторона = ";
	side_2 = input_num_with_check();
	cout << "Площадь прямогольника = " << side_1 * side_2 << endl;
}
// Task 3.2 Tritangle
void triangle()
{
	double side_1, side_2, side_3, square, half_perimeter;
	cout << "Введите параметры фигуры, необходимые для поиска площади.\n";
	cout << "1ая сторона = ";
	side_1 = input_num_with_check();
	cout << "2ая сторона = ";
	side_2 = input_num_with_check();
	cout << "3ая сторона = ";
	side_3 = input_num_with_check();
	half_perimeter = (side_1 + side_2 + side_3) / 2;
	square = sqrt(half_perimeter * (half_perimeter - side_1) * (half_perimeter - side_2) * (half_perimeter - side_3));
	cout << "Площадь треугольника = " << square << endl;
}
// Task 3.3 Circle
void circle()
{
	double radius;
	cout << "Введите радиус, необходимые для поиска площади.\n";
	cout << "r = ";
	radius = input_num_with_check();
	cout << "Площадь круга = " << PI * radius * radius << endl;
}


int main()
{
	setlocale(LC_ALL, "Rus");

	// variables for main functions of main
	int input_task;
	bool flag = true;
	// variables for intput
	double input_number;
	// vars task 3
	bool flag_choice = true;

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
			cout << "Задание: Файл" << endl;
			cout << "Сумма введенных чисел равна " << ex_number() << endl;
			break;
		case(2):
			cout << "Задание: Знак числа" << endl;
			cout << "Введите число для определения знака, где" << endl << "          Г 1, x > 0" << endl << "sign(x) = | 0, x = 0" << endl << "          L -1, x < 0" << endl;
			cout << "x = ";
			cin >> input_number;
			cout << "sign(x) = " << sign(input_number) << endl;
			break;
		case(3):
			cout << "Задание: Геометрические фигуры" << endl;
			int task;
			cout << "Площадь какой фигуры вы хотите посчитать?: " << endl;
			cout << "1. Прямоугольник\n2.Треугольник \n3.Круг\n Введите номер фигуры: ";
			while (flag_choice)
			{
				cin >> task;
				switch (task)
				{
				case(1):
					flag_choice = false;
					rectangle();
					break;
				case(2):
					flag_choice = false;
					triangle();
					break;
				case(3):
					flag_choice = false;
					circle();
					break;
				default:
					cout << "Я не понимаю вас." << endl;
					break;
				}
			}
			break;
		case(4):
			cout << "Задание: ";
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