#include <iostream>
using namespace std;
int main()
{
    char str[80] = "Hello world";
    char *p = str;
    *(str + 4) = 'x';
    *(p + 5) = 'y';
    cout << str << '\n';
    for (char *p1 = str; *p1 != '\0'; p1++)
    {
        cout << *p1;
    }
} 