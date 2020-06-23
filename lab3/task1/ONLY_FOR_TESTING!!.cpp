#include <Windows.h>
#include <iostream>
using namespace std;

void mul(double)
{
	cout << "Введите два числа: \n";
	int a, b;
	cin >> a >> b;
	cout << "Результат равен: " << a * b;
}
void div(double)
{
	cout << "Введите два числа: \n";
	int a, b;
	cin >> a >> b;
	cout << "Результат равен: " << a / b;
}
void diff(double)
{
	cout << "Введите два числа: \n";
	int a, b;
	cin >> a >> b;
	cout << "Результат равен: " << a - b;
}
void sum(double)
{
	cout << "Введите два числа: \n";
	int a, b;
	cin >> a >> b;
	cout << "Результат равен: " << a + b;
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	void (*P[4])(double) = { mul,div,diff,sum };
	cout << "1.Умножение двух чисел\n";
	cout << "2.Деление двух чисел\n";
	cout << "3.Разность двух чисел\n";
	cout << "4.Сумма двух чисел\n";
	cout << " Какую из трех функций выбрать?\n ";
	int a;
	cin >> a;
	a--;
	(*P[a])(a);
	return 0;
}
