#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip> 
#include <string>


using namespace std;

const double PI = 3.141592653589793;

//Functions for error cheking with input:
int input_integers()
{
	int input_number;
	while (!(cin >> input_number))
	{
		cout << "Вы ввели некорректное число. Пожалуйста, введите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input_number;
}

double input_more_then_zero()
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

int input_2_to_16() 
{
	int input_number;
	while (!(cin >> input_number) || input_number < 2 || input_number > 16)
	{
		cout << "Вы ввели некорректное число. Пожалуйста, введите значение заново:\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return input_number;
}

string input_only_romans_nums()
{
	string input_str;
	bool not_romans_flag;

	cout << "Введите число в римской записи\n";

	while (true)
	{
		not_romans_flag = false;
		cin >> input_str;
		for (size_t i = 0; i < input_str.length(); i++)
		{
			if (input_str[i] != 'I' && input_str[i] != 'V' && input_str[i] != 'X' && input_str[i] != 'L' && input_str[i] != 'C' && input_str[i] != 'D' && input_str[i] != 'M')
			{
				not_romans_flag = true;
				break;
			}
		}
		if (not_romans_flag)
		{
			cout << "Вы ввели некорректное число. Пожалуйста, введите значение заново:\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			return input_str;
		}
	}
}


//Task's functions:

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
int sign(double x)
{
	if (x == 0) { return 0; }
	if (x > 0) { return 1; }
	if (x < 0) { return -1; }
	return 0;
}


// Task 3.1 Rectangle
void rectangle()
{
	double side_1, side_2;
	cout << "Введите параметры фигуры, необходимые для поиска площади.\n";
	cout << "1ая сторона = ";
	side_1 = input_more_then_zero();
	cout << "2ая сторона = ";
	side_2 = input_more_then_zero();
	cout << "Площадь прямогольника = " << side_1 * side_2 << endl;
}
// Task 3.2 Tritangle
void triangle()
{
	double side_1, side_2, side_3, square, half_perimeter;
	cout << "Введите параметры фигуры, необходимые для поиска площади.\n";
	cout << "1ая сторона = ";
	side_1 = input_more_then_zero();
	cout << "2ая сторона = ";
	side_2 = input_more_then_zero();
	cout << "3ая сторона = ";
	side_3 = input_more_then_zero();
	if (side_1 + side_2 <= side_3 || side_2 + side_3 <= side_1 || side_1 + side_3 <= side_2)
	{
		cout << "Треугольника с такими параметрами не существует.\n Расчёт площади невозможен.\n";
	}
	else
	{
		half_perimeter = (side_1 + side_2 + side_3) / 2;
		square = sqrt(half_perimeter * (half_perimeter - side_1) * (half_perimeter - side_2) * (half_perimeter - side_3));
		cout << "Площадь треугольника = " << square << endl;
	}
}
// Task 3.3 Circle
void circle()
{
	double radius;
	cout << "Введите радиус, необходимые для поиска площади.\n";
	cout << "r = ";
	radius = input_more_then_zero();
	cout << "Площадь круга = " << PI * radius * radius << endl;
}


//Task 4
void american_flag()
{
	for (size_t i = 0; i < 6; i++)
	{
		cout << "\n";
		for (size_t j = 0; j < 10; j++)
		{
			if (i % 2 == 0)
			{
				if (j <= 8) { cout << " * "; }
				else
				{
					cout.width(40);
					cout << setw(40) << setfill('/');
				}
			}
			else
			{
				if (j <= 8) { cout << "*  "; }
				else
				{
					cout.width(40);
					cout << setw(40) << setfill(' ');
				}
			}
		}
	}		
	for (size_t i = 0; i < 7; i++)
	{
		cout << "\n";
		for (size_t j = 0; j < 66; j++)
		{
			if (i % 2 == 0)
				{
				cout << "/";
				}
			else
			{
				cout << " ";
			}
		}
	}
	cout << endl;
}


//Task 6
void roman_numerals()
{
	int mass[1000];
	int sum = 0;
	cout << "Введите римское число" << endl;
	string str;
	str = input_only_romans_nums();
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'M') mass[i] = 1000;
		if (str[i] == 'D') mass[i] = 500;
		if (str[i] == 'C') mass[i] = 100;
		if (str[i] == 'L') mass[i] = 50;
		if (str[i] == 'X') mass[i] = 10;
		if (str[i] == 'V') mass[i] = 5;
		if (str[i] == 'I') mass[i] = 1;
	}
	for (int i = 0; i < str.length() - 1; i++) {
		if (mass[i] < mass[i + 1]) sum = sum - mass[i];
		else sum = sum + mass[i];
	}
	sum = sum + mass[str.length() - 1];
	cout << sum << endl;
}


//Task 7
int generator_int(int m, int i, int c)
{
	int s_i = 0;
	if (i == 0) return 0;
	if (i > 0)
	{
		for (int x = 1; x < i + 1; x++)
		{
			s_i = (m * s_i + i) % c;
		}
	}
	else 
	{
		for (int x = -1; x > i - 1; x -= 1)
		{
			s_i = (m * s_i + i) % c;
		}
	}

	return s_i;
}

void generator_hub()
{
	int choice_1, choice_2;

	bool choice_flag_main = true;

	int input_m, input_i, input_c;
	int generated_num;

	while (choice_flag_main) 
	{
		cout << "Каким способом вы хотите сгенерировать число?\n1.Ввести значения вручную\n2.Воспользоваться готовыми вариантами из задания.\n";
		cout << "Введите \"0\" для выхода из задания\n";
		choice_1 = input_integers();
		switch (choice_1)
		{
		case(0):
			choice_flag_main = false;
			break;
		case(1):
			cout << "Введите m\n";
			input_m = input_integers();
			cout << "Введите i\n";
			input_i = input_integers();
			cout << "Введите c\n";
			input_c = input_integers();
			generated_num = generator_int(input_m, input_i, input_c);
			cout << "Ваше число - " << generated_num << endl;
			break;
		case(2):
			cout << "Какой пример вы хотите запустить?\n 1) I вариант: m = 37, i = 3, c = 64\n 2) II вариант: m = 25173, i = 13849, c = 65537\n";
			cout << "Введите номер варианта арабской цифрой:\n";
			cin >> choice_2;
			switch (choice_2)
			{
			case(1):
				generated_num = generator_int(37, 3, 64);
				cout << "Ваше число - " << generated_num << endl;
				break;
			case(2):
				generated_num = generator_int(25173, 13849, 65537);
				cout << "Ваше число - " << generated_num << endl;
				break;
			default:
				cout << "Я вас не понимаю.";
				break;
			}
				

			break;
		default:
			cout << "Я вас не понимаю";
			break;
		}
	}
	
}


//Task 8
void matrix_multiplication()
{
	float sellers_goods[3][4] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} };
	float prices_commissions[4][2] = { {1.2, 0.5}, {2.8, 0.4}, {5.0, 2.0}, {2.0, 1.5} };
	float profits[3][2] = { 0 };
	char matrix_tables_ac[3] = {'Г', '|', 'L'};
	char matrix_tables_b[4] = { 'Г', '|', '|', 'L' };

	cout << "\nМатрица А: \n";
	for (int a = 0; a < 3; a++)
	{
		cout << matrix_tables_ac[a] << " ";
		for (int b = 0; b < 4; b++)
		{
			cout << sellers_goods[a][b] << "\t";
		}
		cout << endl;
	}

	cout << "\nМатрица B: \n";
	for (int a = 0; a < 4; a++)
	{
		cout << matrix_tables_b[a] << " ";
		for (int b = 0; b < 2; b++)
		{
			cout << prices_commissions[a][b] << "\t";
		}
		cout << endl;
	}

	cout << "\nМатрица С = A*B:\n";
	for (int i = 0; i < 3; i++) {
		cout << matrix_tables_ac[i] << " ";
		for (int j = 0; j < 4; j++) {
			profits[i][0] += sellers_goods[i][j] * prices_commissions[j][0];
			profits[i][1] += sellers_goods[i][j] * prices_commissions[j][1];
		}
		cout << profits[i][0] << "\t" << profits[i][1] << endl;
	}
	cout << endl;

	float maxProfit = 0,  maxProfitSeller = 0, maxComissions = 0, maxComissionsSeller = 0;
	float minProfit = profits[0][0], minProfitSeller = 1, minComissions = profits[0][1], minComissionsSeller = 1;
	float total_profit = 0, total_comissions = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "Продавец №" << i + 1 << "всего получил " << profits[i][0] + profits[i][1] << " д.е" << endl;
		total_profit += profits[i][0];
		total_comissions += profits[i][1];
		if ((profits[i][0]) < minProfit)
		{
			minProfit = profits[i][0];
			minProfitSeller = i + 1;
		}

		if ((profits[i][1]) < minComissions)
		{
			minComissions = profits[i][1];
			minComissionsSeller = i + 1;
		}

		if ((profits[i][0]) > maxProfit)
		{
			maxProfit = profits[i][0];
			maxProfitSeller = i + 1;
		}

		if ((profits[i][1]) > maxComissions)
		{
			maxComissions = profits[i][1];
			maxComissionsSeller = i + 1;
		}
	}

	cout << endl;
	cout << "Наибольшую выручку, равную " << maxProfit << " получил продавец №" << maxProfitSeller << endl;
	cout << "Наибольшие комиссионные, равные " << maxComissions << " получил продавец №" << maxComissionsSeller << endl << endl;
	cout << "Наименьшую выручку, равную " << minProfit << " получил продавец №" << minProfitSeller << endl;
	cout << "Наименьшие комиссионные, равные " << minComissions << " получил продавец №" << minComissionsSeller << endl << endl;
	cout << "Общая сумма денег, вырученная за проданные товары равна " << total_profit << " д.е" << endl;
	cout << "Общая сумма комиссионных равна " << total_comissions << " д.е" << endl;
}


//Task 9
void number_systems(string start_num, int start_syst, int new_syst) 
{
	int decimal_number = 0, decimal_degree = 0;
	int normal_int;
	string new_number = "";

	for (int i = 0; i < start_num.length(); i ++)
	{	
		if (start_num[i] < 65) { normal_int = int(start_num[i] - '0'); }
		else { normal_int = int(start_num[i] - 55); }
		decimal_number += normal_int * pow(start_syst, start_num.length() - i - 1);
		decimal_degree++;
	}
	
	while (decimal_number > 0)
	{
		if (decimal_number % new_syst < 10)
		{
			new_number = char(decimal_number % new_syst + 48) + new_number;
		}
		else
		{
			new_number = char(decimal_number % new_syst + 55) + new_number;

		}
		decimal_number /= new_syst;
	}

	cout << start_num << "(" << start_syst << " c.c.) = " << new_number << "(" << new_syst << "c.c)\n";

}


int main()
{
	setlocale(LC_ALL, "Rus");

	// variables for main functions of main
	int input_task;
	bool flag = true;
	// variables for intput
	double input_number;
	string start_input_num;
	int start_input_syst, new_input_syst;
	bool err_flag;
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
			cout << "Задание: Былая слава" << endl;
			american_flag();
			break;
		case(5):
			cout << "Задание: Синус" << endl;
			system("c:\\windows\\syswow64\\cmd.exe /c c:\\windows\\sysnative\\cmd.exe /c start /b /w /D\"C:\\Users\\soumireL\\Code\\C++\\MIREA\\task4_5(graph)\\Debug\" task4_5(graph).exe");
			break;
		case(6):
			cout << "Задание: Автоматный распознаватель" << endl;
			roman_numerals();
			cout << "" << endl;
			break;
		case(7):
			cout << "Задание: Генератор псевдослучайных чисел\n";
			generator_hub();
			cout << "" << endl;
			break;
		case(8):
			cout << "Задание: Умножение матриц";
			matrix_multiplication();
			cout << "" << endl;
			break;
		case(9):
			cout << "Задание: Системы счисления\n";
			err_flag = false;
			while (!err_flag)
			{
				cout << "Введите исходное число: " << endl;
				cin >> start_input_num;
				for (size_t i = 0; i < start_input_num.length(); i++)
				{
					if (start_input_num[i] > 70 || (start_input_num[i] < 65 && start_input_num[i] > 57) || start_input_num[i] < 48)
					{
						err_flag = false;
						cout << "Введено некорректное число. Пожалуйста, введите число снова\n";
						start_input_num = "";
						break;
					}
				}
				err_flag = true;
			}
			cout << "Введите исходную систему счисления: " << endl;
			start_input_syst = input_2_to_16();
			cout << "Введите конечную систему счисления: " << endl;
			new_input_syst = input_2_to_16();
			number_systems(start_input_num, start_input_syst, new_input_syst);
			break;
		default:
			cout << "Я не понимаю вас." << endl;
			break;
		}
	}
}