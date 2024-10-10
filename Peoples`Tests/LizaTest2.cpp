#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 2. Задано множину послідовностей значень
    // A[m,n]A[m,n]A[m,n], де m – номер послідовності, а n – кількість
    // елементів у m-тій послідовності. Знайти індекси розміщення
    // мінімального значення в множині.
    vector<vector<int>> vec = {
        {1, 2, 3}
    , {4, 5, 6},
     {7, 8, 9}};
    for (int i = 0; i < vec.size(); i++){
        for (int j = 0; j < vec[i].size(); j++) {
            cout <<vec[i][j] << " ";
            cout<<endl;
        }
        
    }    
    return 0;
}