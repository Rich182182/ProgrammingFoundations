/*
ПІ: Вербицький Євген
Група: 121.1
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
using namespace Pract5;
namespace Pract5{
void FirstTask(){
}
void SecondTask(){}
void ThirdTask(){}
}
int main(){
    vector<int> arr;
    string input;
    cout << "введіть свій масив через SPACE(23 21 45 21), або створіть рандомний (впишіть rand)";
    cin >> input;
    int b = sizeof(input);
    for (int a = 0; a < sizeof(input); a++){

    }
    int task;
    cout << "Введіть номер завдання";
    cin >> task;
    switch(task){
        case(1):
            FirstTask();
            break;
        
        case(2):
            SecondTask();
            break;
        case(3): 
            ThirdTask();  
            break;
        default:
            cout << "невірний номер завдання";

    }
    return 9;
}
