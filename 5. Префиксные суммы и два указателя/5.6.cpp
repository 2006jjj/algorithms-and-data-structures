/*Задача 5.6
Даны две отсортированные последовательности чисел длиной N и M соответственно.
Необходимо слить их в одну отсортированную последовательность.*/

#include <iostream> 
#include <algorithm>
using namespace std;

int* merge(int*, int*, const int&, const int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

int nums1[]{ 44};
int nums2[]{ 1, 2, 7, 55 };
int sizenum1 = sizeof(nums1) / sizeof(nums1[0]);
int sizenum2 = sizeof(nums2) / sizeof(nums2[0]);
sort(nums1, nums1 + sizenum1);
sort(nums2, nums2 + sizenum2);

for (const auto& n : nums1) cout << n << " ";
cout << endl;
for (const auto& n : nums2) cout << n << " ";

int* merged = merge(nums1, nums2, sizenum1, sizenum2);
delete[] merged;

cout << endl;  system("pause"); return 0;
}

int* merge(int* nums1, int* nums2, const int& size_nums1, const int& size_nums2)
{
	int first1 = 0, first2 = 0;
	int N = size_nums1 + size_nums2;
	int* merged = new int[N] {};

	for (int i = 0; i < N; ++i)
	{
		if (first2 == size_nums2 || (first1 < size_nums1 && nums1[first1] < nums2[first2]))
		{
			merged[i] = nums1[first1];
			first1++;
		}
		else
		{
			merged[i] = nums2[first2];
			first2++;
		}
	}
	cout << "\nMerged: ";
	for (int i = 0; i < N; ++i) 
		cout << merged[i] << " ";

	return merged;
}
