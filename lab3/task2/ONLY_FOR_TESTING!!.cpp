#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<vector>
using namespace std;


void qsort(unsigned int* arr, int b, int e)
{
	int l = b, r = e;
	int piv = arr[(l + r) / 2];
	while (l <= r)
	{
		while (arr[l] < piv)
			l++;
		while (arr[r] > piv)
			r--;
		if (l <= r)
			swap(arr[l++], arr[r--]);
	}
	if (b < r)
		qsort(arr, b, r);
	if (e > l)
		qsort(arr, l, e);
}


int main()
{

	string path = "matix.txt";
	ofstream file;
	file.open(path);

	if (!file.is_open())
	{
		cout << "Error\n";
	}
	else
	{
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				file << rand() % 10 << ' ';
			}
			file << '\n';
		}


		file.close();
		ifstream fin;
		fin.open(path);
		if (!fin.is_open())
		{
			cout << "Error\n";
		}
		else
		{
			char ch;
			vector<char>readVector;
			while (fin.get(ch))
			{
				if (ch == ' ' || ch == '\n')continue;
				readVector.push_back(ch);
			}

			fin.close();
			unsigned int mas[25];
			for (int i = 0; i < 25; i++)
			{
				char str = readVector[i];
				mas[i] = static_cast<int>(str) - 48;
			}

			qsort(mas, 0, 25);

			ofstream in;
			in.open(path, ios::app);
			if (!in.is_open())
			{
				cout << "Error\n";
			}
			else
			{
				int j = 1;
				in << "-------------\n";
				for (int i = 0; i < 25; i++)
				{
					in << mas[i] << ' ';
					if (j == 5)
					{
						in << '\n';
						j = 0;
					}
					j++;
				}
			}
			in.close();
		}
	}
	return 0;
}
