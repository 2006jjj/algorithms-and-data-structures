/*Задача 5.5
Игрок в футбол обладает одной числовой характеристикой - профессионализмом. 
Команда называется сплоченной, если профессионализм любого игрока не превосходит суммарный профессионализм любых двух других игроков из команды. 
Команда может состоять из любого количества игроков. Дана отсортированная последовательность чисел длиной N - профессионализм игроков.
Необходимо найти максимальный суммарный профессионализм сплоченной команды.*/



#include <iostream> 
#include <algorithm>
using namespace std;

int bestsumteam(int*, const int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

const int N = 7;
int nums[]{6,4,3,3,1,11,1};
for (const auto& n : nums)
	cout << n << " ";
cout << endl;

sort(nums, nums + N);
for (const auto& n : nums) 
  cout << n << " ";

int result = 0;
cout << "\nRESULT=" << bestsumteam(nums, N) << endl;

cout << endl;  system("pause"); return 0;
}

int bestsumteam(int* players, const int& N)
{
	int bestsum = 0;
	int nowsum = 0;
	int last = 0;

	for (int first = 0; first < N; ++first)
	{
		while (last < N && (last == first || players[first] + players[first + 1] >= players[last]))
		{
			nowsum += players[last];
			last++;
		}
		bestsum = max(bestsum, nowsum);
		nowsum -= players[first];
	}
	return bestsum;
}
