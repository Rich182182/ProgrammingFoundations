/*
ПІ: Вербицький Євген
Група: 121.1
*/
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void TaskChooser(vector<vector<int>> arr);
bool CheckCin(int &input);
void VectorPrint(vector<vector<int>>& arr);
namespace Tasks {
    void FirstTask(vector<vector<int>> arr) {  
        VectorPrint(arr);
        int min = arr[0][0];
        int indexi = 0;
        int indexj = 0;
        for (int i = 0; i < arr.size(); i++) { 
            for(int j = 1; j < arr[i].size(); j++) {
                if(arr[i][j] < min){
                    min = arr[i][j];
                    indexi = i;
                    indexj = j;
                }
            }
        }
        cout <<"Індекс m: "<< indexi << "; індекс n: " << indexj << endl;
        TaskChooser(arr);
    }

    void SecondTask(vector<vector<int>> arr) {
        VectorPrint(arr);
        int max;
        for (int i = 0; i < arr.size(); i++) { 
            for(int j = 0; j < arr[i].size(); j++) {
                if (max == 0 & arr[i][j] < 0) max = arr[i][j];
                if(arr[i][j] > max & arr[i][j] < 0){
                    max = arr[i][j];
                }
            }
        }
        cout << "максимальне від'ємне число: "<< max << endl;
        TaskChooser(arr);
    }

    void ThirdTask(vector<vector<int>> arr) {
        VectorPrint(arr);
        int min;
        for (int i = 0; i < arr.size(); i++) { 
            for(int j = 0; j < arr[i].size(); j++) {
                if (min == 0 & arr[i][j] > 0) min = arr[i][j];
                if(arr[i][j] < min & arr[i][j] > 0){
                    min = arr[i][j];
                }
            }
        }
        cout << "мінімальне додатнє число: " << min << endl;
        TaskChooser(arr);
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
            for(int j = 0; j < arr[i].size(); j++) {
                cout << setw(3) << arr[i][j] << " ";
            }
            cout << endl;
        }
}
void initializeArray() {
    int m;
    cout << "введіть довжину масиву, в якому будуть масиви(m) ";
    if(CheckCin(m)) initializeArray();
    int n;
    cout << "введіть довжину масивів, які будуть в основному масиві(n) ";
    if(CheckCin(n)) initializeArray();
    int arraySize;
    srand(time(0));
    vector<vector<int>> arr(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) arr[i][j] = (rand() % 200) - 99; 
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
