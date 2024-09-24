/*
ПІ: Вербицький Євген
Група: 121.1
Я зробив програму, яка ніби повністю передбачає поведінку юзера, я і не тестив сильно, але по логіці всі помилки при вводі мають ловитися, можете спробувати зламати
*/
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void TaskChooser(vector<int> arr);

namespace Tasks {
    void FirstTask(vector<int> arr) {  
        string input; 
        cout << "Введіть значення, індекс якого ви хочете знайти в масиві ";
        getline(cin, input);
        int temp;
        try{
            temp = stoi(input);
        }
        catch(...){
            cout << "Невірний ввід данних, спробуйте ще раз" << endl;
            FirstTask(arr);
        }
        bool flag = true;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == temp) {
                flag = false;
                cout <<"Індекс першого входження вашого числа: " << i << endl;
                break;
            }
        }
        if (flag) {
            cout << "Такого числа немає в масиві, спробуйте ще раз" << endl;
            FirstTask(arr);
            return;
        }
        TaskChooser(arr);
    }

    void SecondTask(vector<int> arr) {
        int min = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= 0) {
                if (arr[i] < min) {
                    min = arr[i];
                }
            }
        }
        cout <<"Найменше значення в масиві серед додатніх чисел: " << min << endl; 
        TaskChooser(arr);
    }

    void ThirdTask(vector<int> arr) {
        int min = arr[0];
        int minPlace = 0;
        int max = arr[0];
        int maxPlace = 0;
        vector<int> secArr = arr;
        for (int i = 1; i < secArr.size(); i++) {
            if (secArr[i] > max) {
                max = secArr[i];  
                maxPlace = i; 
            }
            if (secArr[i] < min) {
                min = secArr[i];
                minPlace = i;
            }
        }
        secArr[minPlace] = max;
        secArr[maxPlace] = min;
        for (int i = 0; i < secArr.size(); i++) {
            cout << secArr[i] << endl;
        }
        TaskChooser(arr);
    }
}

using namespace Tasks;

void initializeArray(); 

void TaskChooser(vector<int> arr) {
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

void initializeArray() {
    vector<int> arr;
    string input;
    cout << "Введіть свій масив через SPACE (23 21 45 21), або створіть рандомний (впишіть rand) ";
    getline(cin, input);
    int arraySize;
    srand(time(0));
    if (input == "rand") {
        arraySize = 5;
        arr.resize(arraySize);
        for (int i = 0; i < arraySize; i++) {
            arr[i] = rand() % 100; 
        }
    } 
    else {
        stringstream ss(input);
        char delimiter = ' ';
        string token;
        while (getline(ss, token, delimiter)) {
            try {
                arr.push_back(stoi(token)); 
            } 
            catch (invalid_argument&) {
                cout << "Неправильний формат вводу, спробуйте ще раз" << endl;
                initializeArray();  
                return;
            }
        }
        arraySize = arr.size();
    }
    if (arr.empty()) {
            cout << "Масив порожній. Спробуйте ще раз." << endl;
            initializeArray();
            return;
        }
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    TaskChooser(arr);  
}

int main() {
    initializeArray(); 
    return 0;
}
