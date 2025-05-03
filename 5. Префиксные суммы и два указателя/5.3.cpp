/*Задача 5.3
Дана последовательность чисел длиной N
Необходимо найти количество отрезков с нулевой суммой.*/

#include <iostream> 
#include <unordered_map>
using namespace std;

int countzerosumranges(int*, const int&);
int countzerosumranges2(int*, const int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 4;
int nums[N]{-1,1,2,-2};
for (const auto& n : nums)
	cout << n << " ";
cout << endl;

int result = 0;
result=countzerosumranges(nums, N);
cout << "RESULT=" << result << endl;


result = countzerosumranges2(nums, N);
cout << "RESULT2=" << result << endl;


cout << endl;  system("pause"); return 0;
}

//Решение за O(N)
int countzerosumranges(int* nums, const int& N)
{
	unordered_map<long long, int> prefixMap;
	prefixMap[0] = 1;
	long long currentSum = 0;
	int count = 0;

	for (int n=0; n<N; ++n)
	{
		currentSum += nums[n];
		if (prefixMap.find(currentSum) != prefixMap.end())
		{
			count += prefixMap[currentSum];
		}
		prefixMap[currentSum]++;
	}
	//int countres = prefixMap[0]; cout << "countres=" << countres << endl;
	//for (const auto& element : prefixMap) cout << element.first << " " << element.second << endl;
	return count;
}


//Решение за O(N^2)
int countzerosumranges2(int* nums, const int& N)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		int rangesum = 0;
		for (int j = i; j < N; ++j)
		{
			rangesum += nums[j];
			//cout << "RANGESUM=" << rangesum << endl;
			if (rangesum == 0)
				count++;
		}
	}
	return count;
}
