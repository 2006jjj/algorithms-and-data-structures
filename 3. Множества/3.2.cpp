/*Задача 3.2
Дана последовательность положительных чисел длиной N и число X
Нужно найти два различных числа A и B из последовательности, таких что A+B=X или вернуть пару 0,0, если такой пары чисел нет.*/

#include <iostream> 
#include <set>
using namespace std;

pair <int, int> twotermswithsumx(set<int>, int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

set<int> s1;
int N, k, X;
cout << "Введите длину N:";
cin>>N;
cout << "Наше множество:" << endl;
for (int j=0; j<N; j++)
{
	cin >> k;
	s1.insert(k);
}
cout << "\nВведите число которое нужно найти:";
cin >> X;

auto p = twotermswithsumx(s1, X);
cout << "\nОтвет:" << p.first << " " << p.second << endl;
	
cout << endl; system("pause"); return 0;
}

pair <int, int> twotermswithsumx(set<int> s1, int X)
{
	set<int> s2;
	for (int n : s1)
	{
		if (s2.count(X - n))
			return pair(n, X - n);
		s2.insert(n);
	}
	return pair(0, 0);
}

