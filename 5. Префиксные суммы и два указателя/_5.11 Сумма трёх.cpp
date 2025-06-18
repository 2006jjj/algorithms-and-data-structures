/*Задача 5.11
Даны три массива целых чисел 
A,B,C и целое число S.
Найдите такие i,j,k, что Ai+Bj+Ck=S.

Формат ввода
На первой строке число S(1≤S≤10^9). 
Следующие три строки содержат описание массивов A,B,C в одинаковом формате: первое число задает длину n соответствующего массива (1≤n≤15000), затем заданы n целых чисел от 1 до 10^9 — сам массив.

Формат вывода
Если таких i,j,k не существует, выведите единственное число −1. Иначе выведите на одной строке три числа — i,j,k. 
Элементы массивов нумеруются с нуля. Если ответов несколько, выведите лексикографически минимальный.


Пример 1
Ввод:
3
2 1 2
2 3 1
2 3 1
Вывод:
0 1 1


Пример 2
Ввод:
10
1 5
1 4
1 3
Вывод:
-1


Пример 3
Ввод:
5
4 1 2 3 4
3 5 2 1
4 5 3 2 2
Вывод:
0 1 2*/


#include <iostream> 
#include <string> 
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <climits>
using namespace std;

pair<vector<pair<long, long>>, int> MakeVector();
void Find_ijk(vector<pair<long, long>>&, vector<pair<long, long>>&, vector<pair<long, long>>&, const long&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

long S = 0;
cin >> S;
cin.ignore(numeric_limits<streamsize>::max(), '\n');

auto [A, n1] = MakeVector();
auto [B, n2] = MakeVector();
auto [C, n3] = MakeVector();
 
//cout << "S=" << S << "\nn1=" << n1 << "\nn2=" << n2 << "\nn3=" << n3 << endl;
//for (const auto& n : A) cout << n.first << " "; cout << endl;
//for (const auto& n : B) cout << n.first << " "; cout << endl;
//for (const auto& n : C) cout << n.first << " "; cout << endl;

sort(A.begin(), A.end());
sort(B.begin(), B.end());
sort(C.begin(), C.end(), [](const auto& a, const auto& b){
		if (a.first != b.first)
			return a.first < b.first;
		return a.second > b.second;
	});

Find_ijk(A,B,C,S);

cout << endl;  system("pause"); return 0;
}

pair<vector<pair<long, long>>, int> MakeVector()
{
	int n=0;
	string s;
	getline(cin, s);
	istringstream sin(s);
	sin >> n;

	vector<pair<long, long>> vec(n);
	for (int i = 0; i < n; ++i)
	{
		long value;
		sin >> value;
		vec[i] = { value, i };
	}
	return { vec, n };
}

void Find_ijk(vector<pair<long, long>>& A, vector<pair<long, long>>& B, vector<pair<long, long>>& C, const long& S)
{
	bool flag = false;
	vector<int> res(3, INT_MAX);
	
	for (const auto& [aval, apos] : A)
	{
		int cpos = C.size() - 1;
		for (const auto& [bval, bpos] : B)
		{
			while (cpos >=0 && aval + bval + C[cpos].first > S)
				--cpos;

			if (cpos >= 0 && aval + bval + C[cpos].first == S)
			{
				vector<int> current_res = { apos, bpos, C[cpos].second };
				if (!flag || current_res < res)
				{
					res = current_res;
					flag = true;
				}
			}
		}
	}

	if (flag)
		cout << res[0] << " " << res[1] << " " << res[2];
	else
		cout << "-1";
}
