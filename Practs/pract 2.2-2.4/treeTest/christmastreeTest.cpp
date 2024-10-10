/**
 * Done by:
 * Student Name: Smal Margaryta
 * Student Group: 123
 * Practic 2.4
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
// Задача - Christmas Tree

// Основна вимоги(Закриється одна практична -> 2.3 або 2.4) Напишіть програму, яка отримує від користувача число n,
//  що вказує кількість рівнів (шарів) ялинки.Програма повинна вивести ялинку з n рівнів у вигляді трикутників з зірочок(*).
//  Кожен рівень ялинки складається з кількох рядків,
//  де кількість зірочок збільшується від 1 до непарного числа, а також відображається стовбур.

// Додаткові вимоги(Закриваються дві практичні -> 2.3 i 2.4)
// за використання двохвимірного масиву
// за відмальовування ялинки в кольорі
// за додавання в рандомних місцях ялинки іграшок(@, $, %, #)
// за запис ялинки в файл - cristmas_tree.txt
void setRandomColor()
{
	int color = 30 + (rand() % 7 + 1);
	cout << "\033[" << color << "m";
}

void resetColor()
{
	cout << "\033[0m";
}

int main()
{

	ofstream file("./cristmas_tree.txt");
	if (!file.is_open())
	{
		cerr << "Unable to open file" << endl;
		return 1;
	}

	srand(static_cast<unsigned int>(time(nullptr)));

	int n;
	cout << "Enter the numbers of Christmas tree levels: ";
	cin >> n;

	char star = '*';
	char toys[] = {'@', '$', '&', '#'};

	vector<vector<int>> levels(n);

	cout << "Christmas tree" << endl;
	file << "Christmas tree" << endl;

	for (int a = 0; a < n; a++)
	{
		int rows = 3 + a;
		int ret = n + 3;
		levels[a].resize(rows);

		for (int i = 0; i < rows; i++)
		{
			levels[a][i] = 1 + (i * 2);
			cout << setw(ret);
			file << setw(ret);
			setRandomColor();
			for (int j = 0; j < levels[a][i]; j++)
			{
				if (rand() % 5 == 0)
				{
					cout << toys[rand() % 4];
					file << toys[rand() % 4];
				}
				else
				{
					cout << star;
					file << star;
				}
			}
			resetColor();
			ret--;
			cout << endl;
			file << endl;
		};
	}

	for (int i = 0; i < 2; i++)
	{
		cout << setw(n + 2) << star << endl;
		file << setw(n + 2) << star << endl;
	}

	file.close();
	cout << "Christmas tree saved in file 'cristmas_tree.txt'";
	return 0;
}
// int main()
// {
//     int n;
//     cout << "enter number of layers ";
//     cin >> n;
//     vector<vector<char>> tree;
//     for (int i = 0; i < n; i++)
//     {
//         int nm = n;
//         int rows = i + 3;
//         int stars = 1;
//         for (int j = 0; j < rows; j++)
//         {

//             for (int a = 0; a < nm + 1; a++)
//             {
//                 cout << " ";
//             }
//             for (int a = 0; a < stars; a++)
//             {
//                 cout << "*";
//             }
//             stars += 2;
//             nm--;
//             cout << endl;
//         }
//     }
//     for (int i = 0; i < 2; i++)
//     {
//         for (int j = 0; j < n + 1; j++)
//         {
//             cout << " ";
//         }
//         cout << "*" << endl;
//     }
// }
// #include <iostream>
// #include <iomanip>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// #include <fstream>
// using namespace std;
// ofstream outFile("tree_output.txt", ios::app);

// void getRandomColor()
// {
//     cout << "\033[" << 30 + (rand() % 7 + 1) << "m";
// }
// void printTree(vector<vector<char>> tree)
// {
//     for (int i = 0; i < tree.size(); i++)
//     {
//         for (int j = 0; j < tree[i].size(); j++)
//         {
//             getRandomColor();
//             cout << tree[i][j];
//             outFile << tree[i][j];
//         }
//         cout << endl;
//         outFile << endl;
//     }
// }
// void printTreeBase(int n, int rows = 2)
// {
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < n + 1; j++)
//         {
//             cout << " ";
//             outFile << " ";
//         }
//         cout << "\033[38;5;94m";
//         cout << "*" << endl;
//         outFile << "*" << endl;
//     }
//     cout << "\033[0m";
// }
// int main()
// {
//     int n;
//     cout << "enter number of layers ";
//     cin >> n;
//     if (!outFile)
//     {
//         cerr << "Error opening file for writing!" << endl;
//         return 1;
//     }
//     outFile << endl;
//     char arr[5] = {'@', '#', '$', '^', '&'};
//     srand(time(0));
//     for (int i = 0; i < n; i++)
//     {
//         int rows = i + 3;
//         int col = 2 * n + 3;
//         vector<vector<char>> tree(rows, vector<char>(col, ' '));
//         int nm = n;
//         int stars = 1;
//         for (int j = 0; j < rows; j++)
//         {
//             for (int a = 0; a < stars; a++)
//             {
//                 if (rand() % 3 == 0)
//                     tree[j][nm + a + 1] = arr[rand() % 5];
//                 else
//                     tree[j][nm + a + 1] = '*';
//             }
//             stars += 2;
//             nm--;
//         }
//         printTree(tree);
//     }
//     printTreeBase(n);
//     outFile.close();
// }