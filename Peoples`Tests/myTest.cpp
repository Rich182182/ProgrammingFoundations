#include <iostream>

using namespace std;

int main()
{
    int a = 56;
    int b = 54;
    applyOperation(a, b);
    int c = 34;
    int d = 56;
    applyOperation(c, d);
}

int applyOperation(int a, int b, char op)
{

    int plus = a + b;
    int minus = a - b;
    int dil = a / b;
    int mn = a * b;

    cout << plus << minus << dil << mn;
}
