/*
ПІ: Вербицький Євген
Група: 121.1
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;
ofstream outFile("tree_output.txt");

void getRandomColor()
{
    cout << "\033[" << 30 + (rand() % 7 + 1) << "m";
}

void printTree(const vector<vector<char>> &tree)
{
    for (int i = 0; i < tree.size(); i++)
    {
        for (int j = 0; j < tree[i].size(); j++)
        {
            getRandomColor();
            cout << tree[i][j];
            outFile << tree[i][j];
        }
        cout << endl;
        outFile << endl;
    }
    cout.flush();
}

void printTreeBase(int n, int rows = 2)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << " ";
            outFile << " ";
        }
        cout << "\033[38;5;94m";
        cout << "*" << endl;
        outFile << "*" << endl;
    }
    cout << "\033[0m";
    cout.flush();
}

int main()
{
    int n;
    cout << "Enter number of layers: ";
    cin >> n;

    if (!outFile)
    {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    outFile << endl;
    char arr[5] = {'@', '#', '$', '^', '&'};
    srand(time(0));

    vector<vector<vector<char>>> allLayers;

    for (int i = 0; i < n; i++)
    {
        int rows = i + 3;
        int col = 2 * n + 3;
        vector<vector<char>> tree(rows, vector<char>(col, ' '));
        int nm = n;
        int stars = 1;
        for (int j = 0; j < rows; j++)
        {
            for (int a = 0; a < stars; a++)
            {
                if (rand() % 3 == 0)
                    tree[j][nm + a + 1] = arr[rand() % 5];
                else
                    tree[j][nm + a + 1] = '*';
            }
            stars += 2;
            nm--;
        }
        allLayers.push_back(tree);
    }

    while (true)
    {
        cout << "\033[2J\033[1;1H";
        cout.flush();
        for (vector<vector<char>> &tree : allLayers)
        {
            printTree(tree);
        }
        printTreeBase(n);

        this_thread::sleep_for(chrono::seconds(1));
    }

    outFile.close();
    return 0;
}
