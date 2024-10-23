/**
 * Done by:
 * Student Name: Liza Rabirokh
 * Student Group: 121 1groups
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream> // Для роботи з файлами

using namespace std;

int main()
{
    ofstream outFile("cristmas_tree.txt");

    string green = "\033[32m";
    string brown = "\033[33m";
    string reset = "\033[0m";

    string toys = "@$%#";
    srand(time(0));

    int n;
    cout << "Введіть кількість рівнів ялинки: ";
    cin >> n;

    for (int level = 1; level <= n; level++)
    {
        int rows = level + 2;
        int col = 2 * n + 3;
        int nm = n;
        vector<vector<char>> tree(rows, vector<char>(col, ' '));
        for (int row = 1; row <= rows; row++)
        {
            for (int star = 1; star <= 2 * row - 1; star++)
            {
                if (rand() % 5 == 0)
                {
                    char toy = toys[rand() % toys.length()];
                    tree[row - 1][n + star + 1 - row] = toy;
                }
                else
                {
                    tree[row - 1][n + star + 1 - row] = '*';
                }
            }
        }
        for (int i = 0; i < tree.size(); i++)
        {
            for (int j = 0; j < tree[i].size(); j++)
            {
                cout << tree[i][j];
                outFile << tree[i][j];
            }
            cout << endl;
            outFile << endl;
        }
    }
    int trunkHeight = 2;
    int trunkWidth = 3;
    for (int t = 0; t < trunkHeight; ++t)
    {
        for (int space = 1; space <= n; space++)
        {
            cout << " ";
            outFile << " ";
        }
        cout << brown;
        for (int star = 1; star <= trunkWidth; star++)
        {
            cout << "*";
            outFile << "*";
        }
        cout << reset << endl;
        outFile << endl;
    }

    return 0;
}