#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{

	ofstream out;
	ifstream in;

	out.open("D:\\rq.txt");
	in.open("D:\\q.txt");


	if (!in.is_open() && !out.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		cout << "file is open" << endl;

		string str;
		string line;
		while (getline(in, str))
		{
			line += str;
		}
		string lin;
		for (int i = 0; i < 255; i++)
		{
			for (int j = 0; j < line.length() - 1; j++)
			{
				if (i == (int)line[j])
				{
					lin += line[j];
					break;
				}
			}
		}

		out << lin;

		system("pause");
		return 0;
	}
}
