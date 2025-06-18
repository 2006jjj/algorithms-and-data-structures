/*Задача 6.1
В управляющий совет школы входят родители, учителя и учащиеся школы, причём родителей должно быть не менее одной трети от общего числа членов совета. 
В настоящий момент в совет входит N человек, из них K родителей.
Определите, сколько родителей нужно дополнительно ввести в совет, чтобы их число стало составлять не менее трети от числа членов совета.*/


#include <iostream> 
using namespace std;

int lbinsearch(int, int, int, int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

int N, K;
cout << "Введите общее количество людей в совете:"<<endl;
cin >> N;
cout << "Введите общее количество родителей:"<<endl;
cin >> K;

int result = lbinsearch(0, N, N, K);
cout << "\nRESULT=" << result;

cout << endl;  system("pause"); return 0;
}

int lbinsearch(int left, int right, int n, int k)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if ((k + mid) * 3 >= n + mid)
		{
			right = mid;
		}
		else
			left = mid + 1;
	}
	return left;
}
