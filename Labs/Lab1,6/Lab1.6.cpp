/*
ПІ: Вербицький Євген
Група: 121.1
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    {
    // Частина перша
    char var1 = '4';
    char var2 = '@';
    char var3 = 'Y';

    const char const1 = '4';
    const char const2 = '@';
    const char const3 = 'Y';

    int code1 = 0x2;   
    int code2 = 0x56;  
    int code3 = 0xb6; 

    std::cout << "Змінні: " << var1 << " " << var2 << " " << var3 << std::endl;
    std::cout << "Константи: " << const1 << " " << const2 << " " << const3 << std::endl;
    std::cout << "Коди символів: " << code1 << " " << code2 << " " << code3 << std::endl;
    }
    //Частина друга
    {
    int intVar = 13915;
    float floatVar = 4.78e5;
    unsigned short ushortVar = 9765;

    std::cout << "int: " << intVar << std::endl;
    std::cout << "float: " << floatVar << std::endl;
    std::cout << "unsigned short: " << ushortVar << std::endl;

    double doubleVar = floatVar;
    int intVar2 = static_cast<int>(ushortVar);
    char charVar = reinterpret_cast<char&>(intVar);

    std::cout << "double: " << doubleVar << std::endl;
    std::cout << "int: " << intVar2 << std::endl;
    std::cout << "char: " << charVar << std::endl;

    return 0;

    }
    return 0;
}
