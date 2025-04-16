/*Задача 4.3
На шахматной доске N x N находятся M ладей (ладья бьет клетки на той же горизонтали или вертикали до ближайшей занятой).
Определите, сколько пар ладей бьют друг друга.
Ладьи задаются парой чисел i и j, обозначающих координаты клетки.*/

#include <iostream> 
#include <vector>
#include <unordered_map>
using namespace std;

int count_beating_rooks(vector<pair<int, int>>&);
void add_rook(unordered_map<int, int>&, int);
int count_pairs(unordered_map<int, int>&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

vector<pair<int, int>> roods {{1,3}, {3,9}, {1,7}, {5,3}, {3,4}};

int result=count_beating_rooks(roods);
cout << "\nRESULT=" << result << endl;

cout << endl;  system("pause"); return 0;
}

int count_beating_rooks(vector<pair<int,int>>& roods)
{
	unordered_map <int, int> rooksinrow, rooksincol;
	for (const auto& [row, col] : roods) cout  << "row=" << row << " col=" << col << endl;

	for (const auto& [row, col] : roods)
	{
		add_rook(rooksinrow, row);
		add_rook(rooksincol, col);
	}

	cout << "\nROOKS_IN_ROW:" << endl;
	for (const auto& [row, value] : rooksinrow) 
		cout << row << " " << value << endl;

	cout << "\nROOKS_IN_COL:" << endl;
	for (const auto& [col, value] : rooksincol)
		cout << col << " " << value << endl;

	return count_pairs(rooksinrow) + count_pairs(rooksincol);
}

void add_rook(unordered_map<int, int>& row_or_col, int key)
{
	row_or_col[key]++;
}
	
int count_pairs(unordered_map<int,int>& row_or_col)
{
	int pairs = 0;
	//for (const auto& [key, roworcol] : row_or_col) pairs += row_or_col[key] - 1;
	for (const auto& element : row_or_col) 
    pairs += row_or_col[element.first] - 1;
	return pairs;
}
