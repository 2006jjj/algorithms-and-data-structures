/*Задача 5.4
ДВА УКАЗАТЕЛЯ
Дана отсортированная последовательность чисел длиной N и число K
Необходимо найти количество пар чисел A,B, таких что B-A>K.*/

#include <iostream> 
using namespace std;

int twopointers(int*, const int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 5;
int nums[N]{1,3,5,7,8};
for (const auto& n : nums) 
  cout << n << " ";
cout << endl;

int result = 0;
result = twopointers(nums, N);
cout << "RESULT=" << result << endl;

cout << endl;  system("pause"); return 0;
}

int twopointers(int* nums, const int& N)
{
	const int K = 4;
	int cntpairs = 0;
	int last = 0;
	for (int first = 0; first < N; ++first)
	{
		while (last < N && nums[last] - nums[first] <= K)
			last++;
		cntpairs += N - last;
	}
	return cntpairs;
}
