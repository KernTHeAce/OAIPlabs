#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string line;
    string line1;

    ifstream in1;
    ofstream out;
    ifstream in;

    in.open("r.txt");
    in1.open("rr.txt");
    out.open("q.txt");

    if (in.is_open())
    {
        while (getline(in1, line1))
        {
            if (getline(in, line))
                out << line1 << " *" << line << endl;
            else
                out << line1 << " *" << endl;
        }
        cout << "End of program" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }

    in.close();
    in1.close();
    out.close();

    system("pause");
    return 0;
}
