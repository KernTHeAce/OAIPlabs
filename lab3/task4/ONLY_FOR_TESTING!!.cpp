#include<iostream>
#include<fstream>
#include<string>

using namespace std;


int main()
{
	ifstream in;
	in.open("D:\\q.txt");


	if (!in.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		cout << "File is open" << endl;
		int i = 0;

		while (!in.eof())
		{
			int k = 0;
			char* str = new char[1024];
			in.getline(str, 1024, '\n');
			for (int j = 0; j < 5; j++)
			{
				if (str[j] == ' ')
				{
					k++;
				}
			}
			if (k == 5)
			{
				i++;
			}
			delete str;
		}
		cout << i << endl;

		system("pause");
		return 0;
	}
}
