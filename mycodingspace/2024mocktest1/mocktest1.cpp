#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int doubleVal(int num)
{
    return num * 2;
}
double doubleVal(double num)
{
    return num * 2;
}
double doubleVal(string hexnum)
{
    int num;
    stringstream ss;
    ss << hex << hexnum;
    ss >> num;
    return num * 2;
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "insufficient arguments\n.";
    }
    else
    {
        float floatnum;
        int intnum, hexnum;

        string input(argv[1]);
        stringstream ss;

        int pos = input.find_first_of(".xX");

        if (pos != string::npos)
        {
            if (input[pos] == '.')
            {
                ss << input;
                ss >> floatnum;
                floatnum = doubleVal(floatnum);
                cout << fixed << setprecision(2) << floatnum << endl;
            }
            else if (input[pos] == 'x' || input[pos] == 'X')
            {
                hexnum = doubleVal(input);
                cout << showbase << hex << hexnum << endl;
            }
        }
        else
        {
            ss << input;
            ss >> intnum;
            intnum = doubleVal(intnum);
            cout << intnum << endl;
        }
    }
    return 0;
}
