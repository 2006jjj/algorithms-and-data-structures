/*Задача 5.7
В этой задаче вам нужно будет много раз отвечать на запрос «Найдите сумму чисел на отрезке в массиве».

Формат ввода
В первой строке записано два целых числа 
n и q(1≤n, q≤3⋅10^5) - размер массива и количество запросов.
Во второй строке записаны n целых чисел ai(1≤ai≤10^9) - сам массив.
Далее в q строках описаны запросы к массиву. 
Каждый запрос описывается двумя числами l, r (1≤l≤r≤n) - левой и правой границей отрезка, на котором нужно найти сумму.

Формат вывода
Для каждого запроса в отдельной строке выведите единственное число - сумму на соответствующем отрезке.

Пример
Ввод:
4 10
1 2 3 4
1 1
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
4 4

Вывод:
1
3
6
10
2
5
9
3
7
4*/

#include <iostream> 
#include <vector>
using namespace std;

void result(vector<pair<int, int>>&, vector<long long>&, const int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

int n, q;
cin >> n >> q;

vector<long> vec (n);
vector<pair<int, int>> vecpairs (q);
for (int i = 0; i < n; ++i) cin >> vec[i];
for (int i = 0; i < q; ++i) cin >> vecpairs[i].first >> vecpairs[i].second;

vector<long long> prefixsums(n + 1, 0);
for (int i = 1; i < n + 1; ++i)
	prefixsums[i] = prefixsums[i - 1] + vec[i-1];
//for (const auto& n : prefixsums) cout << n << " "; cout << endl;
cout << endl;
 
result(vecpairs, prefixsums, q);

cout << endl;  system("pause"); return 0;
}

void result(vector<pair<int, int>>& vecpairs, vector<long long>& prefixsums, const int& q)
{
	for (int i = 0; i < q; i++)
	{
		long long result = 0;
		int l = vecpairs[i].first;
		int r = vecpairs[i].second;
		result = prefixsums[r] - prefixsums[l - 1];
		cout << result << '\n';
	}
}
