/*Задача 5.10
Если из правильного арифметического выражения вычеркнуть всё, кроме круглых скобок, то получится правильная скобочная последовательность. 
Проверьте, является ли введённая строка правильной скобочной последовательностью.

Формат ввода
Вводится непустая строка, состоящая из открывающих и закрывающих круглых скобок. Длина строки не превосходит 100000

Формат вывода
Выведите YES если введённая строка является правильной скобочной последовательностью и NO иначе

Пример 1
Ввод:
(())()
Вывод:
YES


Пример 2
Ввод:
(()))()
Вывод:
NO */


#include <iostream> 
#include <string> 
#include <algorithm>
using namespace std;

void CorrectString(const string&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

string s;
getline(cin, s);
 
CorrectString(s);
 
cout << endl;  system("pause"); return 0;
}

void CorrectString(const string& s)
{
	int res = 0;
	for (const auto& ch : s)
	{
		if (ch == '(')
			res++;
		else
			res--;

		if (res < 0)
		{
			cout << "NO";
			exit(0);
		}
	}
	res == 0 ? cout << "YES" : cout << "NO";
}
