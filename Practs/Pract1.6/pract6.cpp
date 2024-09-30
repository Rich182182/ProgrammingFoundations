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
    int zero = 0; 
    int one = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) { 
            one += 1;
        } else {
            zero += 1;
        }
    }
    if(zero == one){
        cout << "Одиниць стільки ж скільки і нулів"<< endl;
    }
    else{
    cout << (zero > one ? "Нулів більше ніж одиниць" : "Одиниць більше ніж нулів") << endl;
    }
    TaskChooser();
}
void SecondTask(){
    int input1;
    int input2;
    cout << "Введіть 1 число в десятковій системі: ";
    if(CheckCin(input1)){
        
        SecondTask();
        return;
    }
    cout << "Введіть 2 число в десятковій системі: ";
    if(CheckCin(input2)){
        
        SecondTask();
        return;
    }
    vector<int> arr1;
    vector<int> arr2;
    VectorInitialize(arr1, input1);
    VectorInitialize(arr2, input2);
    vector<int> result;
    if (arr1.size() > arr2.size()){
        int div = arr1.size() - arr2.size();
        for (int i = 0; i < div; i++){
            arr2.insert(arr2.begin(), 0);
        }
    }
    else{
        int div = arr2.size() - arr1.size();
        for (int i = 0; i < div; i++){
            arr1.insert(arr1.begin(), 0);
        }
    }
    VectorPrint(arr1);
    VectorPrint(arr2);
    for (int i = 0; i < arr1.size(); i++){
        result.push_back(arr1[i] ^ arr2[i]);
    }
    cout<< "Представлення двох чисел в XOR: "<< endl;
    VectorPrint(result);
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
            default:
                cout << "Невірний номер завдання, спробуйте ще раз " << endl;
                TaskChooser();
        }
    }  
}
bool CheckCin(int &input){
    cin >> input;
    if(cin.fail()){
        cin.clear(); 
        cin.ignore(10000, '\n'); 
    }
    cin.ignore();
    return cin.fail();
}
int main(){
    TaskChooser();
    return 0;
}
    
