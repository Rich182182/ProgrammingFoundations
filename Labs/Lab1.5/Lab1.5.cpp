/*
ПІ: Вербицький Євген 
Група: 121.1
*/
#include <iostream>
using namespace std;
int main()
{
    //First part
    {
        double a = 13.7;
        int b = 20;
        int c = 24;
        int d = 16;
        cout << (!((!(a >= b)) || (!(c <= d)))) << endl;
}
    {
        double a = 81;
        int b = 81;
        double c = 20.3;
        int d = 4;
        cout << (!((!(a >= b)) || (!(c <= d)))) << endl;
    }
    //Second part
    {
        const int A = 167;
        int B = -42;
        double ptr = 7.27;
        double* C = &ptr;
        const int D = 1993;
        int E = 15760;
        char F = 'F';
        cout << (((A ^ (~B)) + (*C * D)) != (E - (B << sizeof(F)))) << endl;
    }
    return 0;
}
