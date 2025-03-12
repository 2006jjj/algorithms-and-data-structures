/*Задача 2.8
Дана строка (возможно, пустая), состоящая из букв A-Z:
AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB

Нужно написать функцию RLE, которая на выходе даст строку вида:
A4B3C2XYZD4E3F3A6B28. И сгенерирует ошибку, если на вход пришла невалидная строка.
Пояснения: 
Если символ встречается 1 раз, он остается без изменений; 
Если символ повторяется более 1 раза, к нему добавляется количество повторений.*/

#include <iostream> 
#include <string> 
using namespace std;

string easypeasy(string&);
string pack(char, int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

string s = "AAAABBBCCXYZDDDDEEEFFFAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBB";
cout<<"Ответ:"<< easypeasy(s);

cout << endl; system("pause"); return 0;
}

string easypeasy(string &s)
{
	string ans, ch;
	const int MAX = s.size();
	char lastsym = s[0];
	int lastpos = 0;

	for (int j = 0; j < MAX; j++)
	{
		if (s[j] != lastsym)
		{
			ans.append(pack(lastsym, j - lastpos));
			lastsym = s[j];
			lastpos = j;
		}
	}
	ans.append(pack(s[lastpos], MAX - lastpos));
	return ans;
}

string pack(char s, int count)
{
	if (count > 1)
		return &s + to_string(count);
	return &s;
}
