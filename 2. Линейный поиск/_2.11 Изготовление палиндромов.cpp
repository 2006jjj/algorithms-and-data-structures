/*Задача 2.11
В строкоремонтную мастерскую принесли строку, состоящую из строчных латинских букв. 
Заказчик хочет сделать из неё палиндром. В мастерской могут за 1 байтландский тугрик заменить произвольную букву в строке любой выбранной заказчиком буквой.
Какую минимальную сумму придётся заплатить заказчику за ремонт строки?

Формат ввода
Входные данные содержат непустую строку, состоящую из строчных латинских букв, которую принёс заказчик. Длина строки не превосходит 10^4.
Напомним, что палиндромом называется строка, которая равна самой себе, прочитанной в обратном направлении.

Формат вывода
Выведите одно целое число — минимальную сумму, которую заказчику придётся заплатить за превращение принесённой заказчиком строки в палиндром.

Пример 1
Ввод: a
Вывод: 0

Пример 2
Ввод: ab
Вывод: 1

Пример 3
Ввод: cognitive
Вывод: 4  */


#include <iostream> 
#include <string> 
using namespace std;

int countugriks(string&);
int main()
{setlocale(LC_ALL, ".1251"); std::system("color 0F"); srand(time(NULL));

string str;
getline(cin, str);
cout<<"Ответ:"<<countugriks(str);

cout << endl; system("pause");return 0;
}

int countugriks(string &str)
{
	int strsize = str.size();
	int res=0;
	for (int j = 0; j < strsize/2; j++)
	{
		char ch;
		if (str[j] != str[strsize - j - 1])
		{
			ch = str[j];
			str[j] = str[strsize - j - 1];
			str[strsize - j - 1] = ch;
			res++;
		}
	}
	return res;
}
