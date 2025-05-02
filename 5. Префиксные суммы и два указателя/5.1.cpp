/*Задача 5.1
Реализация RSQ (range sum query) через префиксные суммы.*/

#include <iostream> 
using namespace std;

int* makeprefixsum(int*, const int&);
int rsq(int*, const int&, const int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 6;
int nums[N]{5,3,8,1,4,6};

for (const auto& n : nums) 
	cout << n << " ";
cout << endl;

int *prefixsum = makeprefixsum(nums, N);
for (int i = 0; i <= N; i++)
	cout << prefixsum[i] << " ";

const int r = 5;
const int l = 2;
int sum = rsq(prefixsum, l, r);
cout << "\nSUM=" << sum;

delete[] prefixsum;

cout << endl;  system("pause"); return 0;
}

int* makeprefixsum(int* nums, const int& N)
{
	int* prefixsum = new int[N + 1];
	prefixsum[0] = 0;
	for (int i = 1; i < N + 1; i++)
		prefixsum[i] = prefixsum[i - 1] + nums[i - 1];

	return prefixsum;
}

int rsq(int* prefixsum, const int& l, const int& r)
{
	return prefixsum[r] - prefixsum[l];
}
