#include <iostream>
using namespace std;

double division(int a, int b)
{
    if (a == NULL)
    {
        throw "a number is NULL!";
    }
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
}

int main()
{
    int x = 50;
    int y = 0;
    double z = 0;

    int b = NULL;
    int d = NULL;
    double p = 0;

    int u = 50;
    int i = 5;
    double o = 0;
    try
    {
        z = division(x, y);
        cout << z << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    try
    {
        p = division(b, d);
        cout << p << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }

    // right try
    try
    {
        o = division(u, i);
        cout << o << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    return 0;

}