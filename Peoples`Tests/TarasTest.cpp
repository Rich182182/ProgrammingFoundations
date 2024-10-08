#include <iostream>
#include <vector>

using namespace std;

int main() {
    bool b = (1 / 2)==(2>>sizeof(float));
    if(b){
        cout << "true"<< endl;
    }
    cout << b << endl;
        // // Задано послідовність значень А[n]. Знайти найбільше і найменше значення та поміняти їх місцями. 
        // vector<int> arr = { 56, 24, 57, -34, 54, 31, -72 }; // послідовність значень A[n]

        // int minVal = arr[0];
        // int maxVal = arr[0];

        // int indexMin = 0;
        // int indexMax = 0;
        

        // for (int i = 1; i < arr.size(); i++){
        //     // перевірка на найменьше значення
        //         if (minVal > arr[i]) {
        //             minVal = arr[i];
        //             indexMin = i;
        //         }
        //     // перевірка на найбільше значення
        //         if (maxVal < arr[i]) {
        //             maxVal = arr[i];
        //             indexMax = i;
        //         }
        // }

        // arr[indexMin] = maxVal;
        // arr[indexMax] = minVal;
        // for (int i = 0; i < arr.size(); i++) {
        //     cout << arr[i];
        // }

    }