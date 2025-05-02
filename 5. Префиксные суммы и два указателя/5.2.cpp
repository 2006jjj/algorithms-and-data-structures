/*Задача 5.2
Дана последовательность чисел длиной N и M запросов.
Запросы: Сколько нулей на полуинтервале [L,R].*/


#include <iostream>
using namespace std;

int* makeprefixzeroes(int*, const int&);
int countzeroes(int*, const int&, const int&);
void countzeroes2(int*, const int&, const int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 7;
int nums[N]{1,0,1,1,0,0,1};

for (const auto& n : nums)
	cout << n << " ";
cout << endl;

int* prefixzeroes = makeprefixzeroes(nums, N);
for (int i = 0; i <= N; i++) 
  cout << prefixzeroes[i] << " ";

const int r = 5;
const int l = 2;
int zerosum = countzeroes(prefixzeroes, l, r);
cout << "\nZEROSUM=" << zerosum;

delete[] prefixzeroes;

countzeroes2(nums, l, r);

cout << endl;  system("pause"); return 0;
}

int* makeprefixzeroes(int* nums, const int& N)
{
	int* prefixzeroes = new int[N+1];
	*prefixzeroes = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (nums[i - 1] == 0)
			prefixzeroes[i] = prefixzeroes[i - 1] + 1;
		else
			prefixzeroes[i] = prefixzeroes[i - 1];
	}
	return prefixzeroes;
}

//Решение за O(N+M)
int countzeroes(int* prefixzeroes, const int& l, const int& r)
{
	return prefixzeroes[r] - prefixzeroes[l];
}

//Решение за O(NM)
void countzeroes2(int* nums, const int& l, const int& r)
{
	int count = 0;
	for (int i = l; i < r; i++)
	{
		if (nums[i] == 0)
			count++;
	}
	cout << "\nCOUNT=" << count << endl;
}
