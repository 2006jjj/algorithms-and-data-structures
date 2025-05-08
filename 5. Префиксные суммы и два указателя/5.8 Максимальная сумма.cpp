/*Задача 5.8
В этой задаче вам требуется найти непустой отрезок массива с максимальной суммой.

Формат ввода
В первой строке входных данных записано единственное число n(1≤n≤3⋅10^5) - размер массива.
Во второй строке записано n целых чисел ai(−10^9≤ai≤10^9) - сам массив.

Формат вывода
Выведите одно число - максимальную сумму на отрезке в данном массиве.

Пример 1
Ввод:
4
1 2 3 4
Вывод:
10


Пример 2
Ввод:
4
5 4 -10 4
Вывод:
9*/

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

long MaximumSegmentSum(vector<long>&, const int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

int n;
cin >> n;

vector<long> vec (n);
for (int i = 0; i < n; ++i) 
	cin >> vec[i];

long result = MaximumSegmentSum(vec, n);
cout << result;

cout << endl;  system("pause"); return 0;
}

long MaximumSegmentSum(vector<long>& vec, const int& n)
{
	long current = vec[0];
	long result_max = vec[0];
	for (int i = 1; i < n; ++i)
	{
		current = max(vec[i], current + vec[i]);
		result_max = max(result_max, current);
	}
	return result_max;
}
