/*
ПІ: Вербицький Євген
Група: 121.1
*/
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void TaskChooser(vector<vector<int>> arr);
bool CheckCin(int &input);
namespace Tasks {
    void FirstTask(vector<vector<int>> arr) {  
        // int input; 
        // cout << "Введіть значення, індекс якого ви хочете знайти в масиві ";
        // if(CheckCin(input)){
        
        //     FirstTask(arr);
        //     return;
        // }
        // for (int i = 0; i < arr.size(); i++) {
        //     if (arr[i] == temp) {
        //         flag = false;
        //         cout <<"Індекс першого входження вашого числа: " << i << endl;
        //         break;
        //     }
        // }
        // if (flag) {
        //     cout << "Такого числа немає в масиві, спробуйте ще раз" << endl;
        //     FirstTask(arr);
        //     return;
        // }
        // TaskChooser(arr);
    }

    void SecondTask(vector<vector<int>> arr) {
        // int min = arr[0];
        // for (int i = 1; i < arr.size(); i++) {
        //     if (arr[i] >= 0) {
        //         if (arr[i] < min) {
        //             min = arr[i];
        //         }
        //     }
        // }
        // cout <<"Найменше значення в масиві серед додатніх чисел: " << min << endl; 
        // TaskChooser(arr);
    }

    void ThirdTask(vector<vector<int>> arr) {
        // int min = arr[0];
        // int minPlace = 0;
        // int max = arr[0];
        // int maxPlace = 0;
        // vector<int> secArr = arr;
        // for (int i = 1; i < secArr.size(); i++) {
        //     if (secArr[i] > max) {
        //         max = secArr[i];  
        //         maxPlace = i; 
        //     }
        //     if (secArr[i] < min) {
        //         min = secArr[i];
        //         minPlace = i;
        //     }
        // }
        // secArr[minPlace] = max;
        // secArr[maxPlace] = min;
        // for (int i = 0; i < secArr.size(); i++) {
        //     cout << secArr[i] << endl;
        // }
        // TaskChooser(arr);
    }
}

using namespace Tasks;

void initializeArray(); 

bool CheckCin(int &input) {
    cin >> input;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n'); 
        cout << "невірний ввід данних, спробуйте ще раз" << endl;
        return true; 
    }
    cin.ignore(10000, '\n'); 
    return false; 
}
void TaskChooser(vector<vector<int>> arr) {
    string task;
    cout << "Введіть номер завдання, впишіть (arr), якщо хочете переписати масив, або (end), щоб завершити програму: ";
    getline(cin, task);

    if (task.empty()) {
        cout << "Спробуйте ще раз." << endl;
        TaskChooser(arr);
        return;
    }

    if (task == "arr") {
        initializeArray();  
    } 
    else if (task == "end") {
        exit(0);  
    } 
    else {
        int nums;
        try {
            nums = stoi(task); 
        } 
        catch (...) {
            cout << "Невірний ввід данних, спробуйте ще раз" << endl;
            TaskChooser(arr);
            return;  
        }
        switch (nums) {
            case 1:
                FirstTask(arr);
                break;
            case 2:
                SecondTask(arr);
                break;
            case 3: 
                ThirdTask(arr);
                break;  
            default:
                cout << "Невірний номер завдання, спробуйте ще раз " << endl;
                TaskChooser(arr);
        }
    }  
}
void VectorPrint(vector<vector<int>>& arr){
    for (int i = 0; i < arr.size(); i++) { 
            cout << endl;
            for(int j = 0; arr[i].size(); i++) {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
}
void initializeArray() {
    int m;
    cout << "введіть довжину масиву, в якому будуть масиви(m)";
    if(CheckCin(m)) initializeArray();
    int n;
    cout << "введіть довжину масивів, які будуть в основному масиві(n)";
    if(CheckCin(n)) initializeArray();
    int arraySize;
    srand(time(0));
    vector<vector<int>> arr(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; i < n; i++) arr[i][j] = rand() % 100; 
        }
    if (arr.empty()) {
            cout << "Масив порожній. Спробуйте ще раз." << endl;
            initializeArray();
            return;
        }
    VectorPrint(arr);

    TaskChooser(arr);  
}

int main() {
    initializeArray(); 
    return 0;
}
