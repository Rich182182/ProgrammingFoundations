// /*
// ПІ: Вербицький Євген 
// Група: 121.1
// */
// #include <iostream>
// #include <bitset>
// #include <vector>
// using namespace std;
// vector<int> VectorInitialize(vector<int>& arr, int input);
// bool CheckCin(int &input);
// void VectorPrint(vector<int>& arr);
// void TaskChooser();
// void FirstTask(){
//     int input;
//     cout << "Введіть число ";
//     if(CheckCin(input)){
        
//         FirstTask();
//         return;
//     }
//     vector<int> arr;
//     VectorInitialize(arr, input);
//     VectorPrint(arr);
//     cout << ((arr[arr.size() - 1] & 1) == 0 ? "Число парне" : "Число непарне") << endl; 
//     TaskChooser();
// }
// void SecondTask(){
//     int input;
//     cout << "Введіть число в десятковій системі: ";
//     if(CheckCin(input)){
        
//         SecondTask();
//         return;
//     }
//     vector<int> arr;
//     VectorInitialize(arr,input);
//     VectorPrint(arr);
//     int one = 0;
//     for (int i : arr ){
//         if(i == 1) one++;
//     }
//     cout<< "Одиниць в числі: " << one << endl;
//     TaskChooser();
// }
// void ThirdTask(){
//     int input;
//     int position;
//     cout << "введіть число в десятковій системі числення:";
//     cin >> input;
//     vector<int> arr;
//     VectorInitialize(arr,input);
//     VectorPrint(arr);
//     cout << "Введіть номер позиції (починаючи з 0)";
//     cin >> position;
//     cout << "на вашій позиції знаходиться цифра " << arr[position] << endl;
//     TaskChooser();
// }
// vector<int> VectorInitialize(vector<int>& arr, int input){
//     if (input == 0) {
//         arr.push_back(0);
//     } else {
//         while (input > 0) {
//             arr.insert(arr.begin(), input % 2);
//             input /= 2;
//         }

        
//     }
//     return arr;
// }
// void VectorPrint(vector<int>& arr){
//     for (int i = 0; i < arr.size(); i++) { 
//             cout << arr[i];
//         }
//         cout << endl;
// }
// void TaskChooser() {
//     string task;
//     cout << "Введіть номер завдання, або (end), щоб завершити програму: ";
//     getline(cin, task);

//     if (task.empty()) {
//         cout << "Спробуйте ще раз." << endl;
//         TaskChooser();
//         return;
//     }

//     else if (task == "end") {
//         exit(0);  
//     } 
//     else {
//         int nums;
//         try {
//             nums = stoi(task); 
//         } 
//         catch (...) {
//             cout << "Невірний ввід данних, спробуйте ще раз" << endl;
//             TaskChooser();
//             return;  
//         }
//         switch (nums) {
//             case 1:
//                 FirstTask();
//                 break;
//             case 2:
//                 SecondTask();
//                 break;
//             case 3:
//                 ThirdTask();
//                 break;
//             default:
//                 cout << "Невірний номер завдання, спробуйте ще раз " << endl;
//                 TaskChooser();
//         }
//     }  
// }
// bool CheckCin(int &input){
//     cin >> input;
//     if(cin.fail()){
//         cin.clear(); 
//         cin.ignore(10000, '\n'); 
//     }
//     cin.ignore();
//     return cin.fail();
// }
// int main(){
//     TaskChooser();
//     return 0;
// }
    
/*
ПІ: Вербицький Євген
Група: 121.1
Я зробив програму, яка ніби повністю передбачає поведінку юзера, я і не тестив сильно, але по логіці всі помилки при вводі мають ловитися
*/
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void TaskChooser(vector<int> arr);
bool CheckCin(int &input);
namespace Tasks {
    void FirstTask(vector<int> arr) {  
        int input; 
        cout << "Введіть значення, індекс якого ви хочете знайти в масиві ";
        if(CheckCin(input)){
        
            FirstTask(arr);
            return;
        }
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

bool CheckCin(int &input){
    cin >> input;
    if(cin.fail()){
        cin.clear(); 
        cin.ignore(10000, '\n'); 
    }
    cin.ignore();   
    return cin.fail();
}
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
    int input;
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
