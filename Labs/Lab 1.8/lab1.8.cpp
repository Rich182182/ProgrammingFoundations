/*
ПІ: Вербицький Євген 
Група: 121.1
*/
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
vector<int> VectorInitialize(vector<int>& arr, int input);
bool CheckCin(int &input);
void VectorPrint(vector<int>& arr);
void TaskChooser();
void FirstTask(){
    int input;
    cout << "Введіть число ";
    if(CheckCin(input)){
        
        FirstTask();
        return;
    }
    vector<int> arr;
    VectorInitialize(arr, input);
    VectorPrint(arr);
    cout << ((arr[arr.size() - 1] & 1) == 0 ? "Число парне" : "Число непарне") << endl; 
    TaskChooser();
}
void SecondTask(){
    int input;
    cout << "Введіть число в десятковій системі: ";
    if(CheckCin(input)){
        
        SecondTask();
        return;
    }
    vector<int> arr;
    VectorInitialize(arr,input);
    VectorPrint(arr);
    int one = 0;
    for (int i : arr ){
        if(i == 1) one++;
    }
    cout<< "Одиниць в числі: " << one << endl;
    TaskChooser();
}
void ThirdTask(){
    int input;
    int position;
    cout << "введіть число в десятковій системі числення: ";
    if(CheckCin(input)){
        
        FirstTask();
        return;
    }
    vector<int> arr;
    VectorInitialize(arr,input);
    VectorPrint(arr);
    cout << "Введіть номер позиції (починаючи з 0) ";
    if(CheckCin(position)){
        
        FirstTask();
        return;
    }
    cout << "на вашій позиції знаходиться цифра " << arr[position] << endl;
    TaskChooser();
}
vector<int> VectorInitialize(vector<int>& arr, int input){
    if (input == 0) {
        arr.push_back(0);
    } else {
        while (input > 0) {
            arr.insert(arr.begin(), input % 2);
            input /= 2;
        }

        
    }
    return arr;
}
void VectorPrint(vector<int>& arr){
    for (int i = 0; i < arr.size(); i++) { 
            cout << arr[i];
        }
        cout << endl;
}
void TaskChooser() {
    string task;
    cout << "Введіть номер завдання, або (end), щоб завершити програму: ";
    getline(cin, task);

    if (task.empty()) {
        cout << "Спробуйте ще раз." << endl;
        TaskChooser();
        return;
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
            TaskChooser();
            return;  
        }
        switch (nums) {
            case 1:
                FirstTask();
                break;
            case 2:
                SecondTask();
                break;
            case 3:
                ThirdTask();
                break;
            default:
                cout << "Невірний номер завдання, спробуйте ще раз " << endl;
                TaskChooser();
        }
    }  
}
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

int main(){
    TaskChooser();
    return 0;
}
    
