#include <iostream>

#include <Windows.h>

#include <fstream>

using namespace std;

struct filmstrip {

	char adress[15];

	char type[15];

	int stages;

	int flats;

	int time1;

	int time2;

};

void BubbleSort(filmstrip* a, int n, int p);

int menu(char* path);

int counter(char* path);

void Create(char* path);

void Addition(char* path);

void Output(char* path);

void Delete(char* path);

int SK(char* path);

void Sort(char* path);

int main(int argc, char** argv) {

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	char path[] = "D:\\task.txt";

	void (*masf[])(char*) = { Create,Addition,Output,Delete,Sort };

	while (1)

		(*masf[menu(path)])(path);

	system("pause");

	return 0;

}

void BubbleSort(filmstrip* a, int n, int p) {

	int j;

	filmstrip t;

	switch (p)
	{

		case 1: 

			while (n--)

				for (j = 0; j < n; j++) {

					if ((int)a[j].adress >= (int)a[j + 1].adress) continue;

					t = a[j];

					a[j] = a[j + 1];

					a[j + 1] = t;

				}

			break;

	

		case 2: 

			while (n--)

				for (j = 0; j < n; j++) {

					if ((int)a[j].type >= (int)a[j + 1].type) continue;

					t = a[j];

					a[j] = a[j + 1];

					a[j + 1] = t;

				}

			break;

	

		case 3: 

			while (n--)

				for (j = 0; j < n; j++) {

					if (a[j].stages >= a[j + 1].stages) continue;

					t = a[j];

					a[j] = a[j + 1];

					a[j + 1] = t;

				}

			break;

	

		case 4: 

			while (n--)

				for (j = 0; j < n; j++) {

					if (a[j].flats <= a[j + 1].flats) continue;

					t = a[j];

					a[j] = a[j + 1];

					a[j + 1] = t;

				}

			break;

	

		case 5: 

			while (n--)

				for (j = 0; j < n; j++) {

					if (a[j].time1 < a[j + 1].time1) continue;

					t = a[j];

					a[j] = a[j + 1];

					a[j + 1] = t;

				}

			break;

	

		case 6: 

			while (n--)

				for (j = 0; j < n; j++) 
				{

					if (a[j].time2 < a[j + 1].time2) continue;

					t = a[j];

					a[j] = a[j + 1];

					a[j + 1] = t;
				}
			

			break;

	

	}

}

int menu(char* path) {

	char k;

	do {

		cout << "Меню:" << endl;

		cout << "1) Создание файла;" << endl;

		cout << "2) Добавление элемента в конец файла;" << endl;

		cout << "3) Вывод содержимого файла на экран;" << endl;

		cout << "4) Удаление элемента из файла;" << endl;

		cout << "5) Упорядочивание элементов в файле по выбранному признаку;" << endl;

		cout << "6) Выход." << endl;

		cout << "Выберите пункт меню: " << endl;

		k = getchar();

		system("cls");

	} while (strchr("123456", k) == NULL);

	if (k == '6') exit(0);

	return k - 49;

}

int counter(char* path) {

	ifstream fin;

	int n = 0;

	char buff[20];

	fin.open(path, ios_base::binary);

	while (!fin.eof()) {

		fin.getline(buff, 20, '\n');

		n++;

	}

	n /= 9;

	fin.close();

	return n;

}

void Create(char* path) {

	cout << "Текущий файл: " << path << endl;

	int n;

	cout << "Введите количество структур: ";

	cin >> n;

	filmstrip* a = new filmstrip[n];

	for (int i = 0; i < n; i++) {

		cout << "Введите название фильма: ";

		cin >> a[i].adress;

		cout << "Введите фамилию режиссёра: ";

		cin >> a[i].type;

		cout << "Введите имя режиссёра: ";

		cin >> a[i].stages;

		cout << "Введите стоимость фильма: ";

		cin >> a[i].flats;

		cout << "Введите прибыль фильма: ";

		cin >> a[i].time1;

		a[i].time2 =25- a[i].time1;

	}

	ofstream fout(path, ios_base::binary | ios_base::trunc);

	for (int i = 0; i < n; i++) {

		fout << i + 1 << endl;

		fout << a[i].adress << endl;

		fout << a[i].type << endl;

		fout << a[i].stages << endl;

		fout << a[i].flats << endl;

		fout << a[i].time1 << endl;

		fout << a[i].time2 << endl;

	}

	fout.close();

	delete[] a;

	system("pause");

}

void Addition(char* path) {

	int n = counter(path);

	ofstream fout(path, ios_base::binary | ios_base::app);

	filmstrip* a = new filmstrip[1];

	if (fout.is_open()) {

		cout << "Адресс: ";

		cin >> a[0].adress;

		cout << "Тип : ";

		cin >> a[0].type;

		cout << "количество этажей: ";

		cin >> a[0].stages;

		cout << "Количество квартир: ";

		cin >> a[0].flats;

		cout << "Срок эксплуатации: ";

		cin >> a[0].time1;

		a[0].time2 =25- a[0].time1;

		fout << n + 1 << endl;

		fout << a[0].adress << endl;

		fout << a[0].type << endl;

		fout << a[0].stages << endl;

		fout << a[0].flats << endl;

		fout << a[0].time1 << endl;

		fout << a[0].time2 << endl;

		fout.close();

		delete[] a;

	}

	else cout << "Файл не открыт." << endl;

	system("pause");

}

void Output(char* path) {

	int n = counter(path);

	ifstream fin;

	int order;

	fin.open(path, ios_base::binary);

	if (fin.is_open()) {

		filmstrip* a = new filmstrip[n];

		for (int i = 0; i < n; i++) {

			fin >> order;

			cout << "№" << order << endl;

			fin >> a[i].adress;

			cout << "Адресс: " << a[i].adress << endl;

			fin >> a[i].type;

			cout << "Тип: " << a[i].type << endl;

			fin >> a[i].stages;

			cout << "Количество этажей: " << a[i].stages << endl;

			fin >> a[i].flats;

			cout << "Количество квартир: " << a[i].flats << endl;

			fin >> a[i].time1;

			cout << "Срок эксплуатации: " << a[i].time1 << endl;

			fin >> a[i].time2;

			cout << "Срок до кап ремонта: " << a[i].time2 << endl;

		}

		fin.close();

		system("pause");

	}

	else cout << "Файл не открыт." << endl;

}

void Delete(char* path) {

	int k, choice;

	char temp[20];

	cout << "Выберете способ удаления структуры:" << endl;

	cout << "\t0. По ключу" << endl;

	cout << "\t1. По номеру" << endl;

	cin >> choice;

	do {

		if (choice) {

			cout << "Введите номер структуры: ";

			cin >> k;

			k--;

		}

		else k = SK(path);

	} while (k < 0);

	ifstream fin;

	ofstream fout;

	fin.open(path, ios::binary);

	fout.open("buff.bin", ios::binary);

	for (int i = 0; !fin.eof(); i++) {

		for (int num = 0; num < 9 && !fin.eof(); num++) {

			fin >> temp;

			if (i != k) {

				fout << temp << endl;

			}

		}

	}

	fin.close();

	fout.close();

	remove(path);

	rename("buff.bin", path);

}

int SK(char* path) {

	char tmp[20], k[20];

	cout << "Введите ключ для поиска: ";

	cin >> k;

	ifstream fin;

	fin.open(path, ios::binary);

	for (int i = 0; !fin.eof(); i++) {

		for (int j = 0; j < 9; j++) {

			fin >> tmp;

			if (!strcmp(tmp, k)) {

				fin.close();

				return i;

			}

		}

	}

	fin.close();

	return -1;

}

void Sort(char* path) {

	int p, n;

	n = counter(path);

	filmstrip* a = new filmstrip[n];

	ifstream fin;

	int order;

	fin.open(path, ios_base::binary);

	if (fin.is_open()) {

		filmstrip* a = new filmstrip[n];

		for (int i = 0; i < n; i++) {

			fin >> order;

			fin >> a[i].adress;

			fin >> a[i].type;

			fin >> a[i].stages;

			fin >> a[i].flats;

			fin >> a[i].time1;

			fin >> a[i].time2;

		}

		fin.close();

		cout << "\t1. Адрес;" << endl;

		cout << "\t2. Тип здания;" << endl;

		cout << "\t3. Количество этажей;" << endl;

		cout << "\t4. количество квартир;" << endl;

		cout << "\t5. Срок эксплуатации;" << endl;

		cout << "\t6. Срок до кап ремонта;" << endl;

		cout << "Выберете по какому параметру сортировать: ";

		cin >> p;

		BubbleSort(a, n, p);

		ofstream fout(path, ios_base::binary | ios_base::trunc);

		if (fout.is_open()) {

			for (int i = 0; i < n; i++) {

				fout << i + 1 << endl;

				fout << a[i].adress << endl;

				fout << a[i].type << endl;

				fout << a[i].stages << endl;

				fout << a[i].flats << endl;

				fout << a[i].time1 << endl;

				fout << a[i].time2 << endl;

			}

		}

	}

	else cout << "Файл не открыт." << endl;

}