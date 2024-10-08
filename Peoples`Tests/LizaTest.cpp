#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr = {2, 5, 8, 45, 87, 23, 95};
    int P = 87;
    for (int i = 0; i<arr.size(); i++)
    {if (arr[i] == P )
     {
        cout<<i<<endl;
     }
    
    }

}