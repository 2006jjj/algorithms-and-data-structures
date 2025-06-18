/*Задача 6.2
Юра решил подготовиться к собеседованию в Яндекс. Он выбрал на сайте leetcode N задач.
В первый день Юра решил K задач, а в каждый следующий день Юра решал на одну задачу больше, чем в предыдущий день.
Определите, сколько дней уйдет у Юры на подготовку к собеседованию.*/


#include <iostream>
using namespace std;

int lbinsearch(int, int, int, int);
bool checkendowment(int, int, int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

int N, K;
cout << "Введите общее количество задач для достижения цели:"<<endl;
cin >> N;
cout << "Введите количество задач которые Юра решил за один день:"<<endl;
cin >> K;

int result = lbinsearch(0, N, N, K);
cout << "\nRESULT=" << result<<" days";

cout << endl;  system("pause"); return 0;
}

int lbinsearch(int left, int right, int n, int k)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (checkendowment(mid, n, k))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

bool checkendowment(int days, int n, int k) 
{
	return (k+(k+days-1)) * days / 2 >= n;
}
