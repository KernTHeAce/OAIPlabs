#include<fstream>

#include <iostream>

#include<vector>

#include<cstring>

#include<string>

using namespace std;

void swap(string* al, string* ak, int m, int l)

{

	for (int i = 0; i < l * m; i += (m * 2))

	{

		for (int j = 0; j < m; j++)

		{

			string temp;

			temp = ak[i + j];

			ak[i + j] = al[i + j];

			al[i + j] = temp;

		}

	}

}

int main()

{

	setlocale(0, "");

	ofstream fileL;

	ofstream fileK;

	string pathL = "D://fileL.txt";

	string pathK = "D://fileK.txt";

	fileL.open(pathL);

	fileK.open(pathK);

	if (!fileL.is_open() || !fileK.is_open())

	{

		cout << "Error!" << endl;

	}

	else

	{

		int l, k, m, n;

		cout << "Введите l(количество матриц в первом файле):"; cin >> l;

		cout << "\nВведите k(количество матриц во втором файле):"; cin >> k;

		cout << "\nВведите m и n(размеры матриц):"; cin >> m >> n;

		for (int i = 0; i < k; i++)

		{

			for (int j = 0; j < m; j++)

			{

				for (int r = 0; r < n; r++)

				{

					int a = 1;

					fileK << a << " ";

				}

				fileK << '\n';

			}

		}

		for (int i = 0; i < l; i++)

		{

			for (int j = 0; j < m; j++)

			{

				for (int r = 0; r < n; r++)

				{

					int a = 0;

					fileL << a << " ";

				}

				fileL << '\n';

			}

		}

		fileL.close();

		fileK.close();

		ifstream fl;

		ifstream fk;

		fl.open(pathL);

		fk.open(pathK);

		string* al = new string[m * l];

		string* ak = new string[m * k];

		string str;

		for (int i = 0; getline(fl, str); i++)

		{

			al[i] = str;

		}

		for (int i = 0; getline(fk, str); i++)

		{

			ak[i] = str;

		}

		fk.close();

		fl.close();

		if (k > l)

			swap(al, ak, m, l);

		else

			swap(al, ak, m, l);

		ofstream filel;

		ofstream filek;

		filel.open(pathL);

		filek.open(pathK);

		for (int i = 0; i < m * l; i++)

		{

			filel << al[i] << '\n';

		}

		for (int i = 0; i < m * k; i++)

		{

			filek << ak[i] << '\n';

		}

		fl.close();

		fk.close();

	}

	system("pause");

	return 0;

}