/*Задача 3.5
Во входной строке записана последовательность чисел через пробел. 
Для каждого числа выведите слово YES (в отдельной строке), если это число ранее встречалось в последовательности или NO, если не встречалось.

Формат ввода
Вводится список чисел. Все числа списка находятся на одной строке.

Формат вывода
Выведите ответ на задачу.

Пример
Ввод:
1 2 3 2 3 4
Вывод:
NO
NO
NO
YES
YES
NO*/

#include <iostream> 
#include <string> 
#include <sstream>
#include <vector>
#include <set>
using namespace std;
void findrepeatnumber(vector<int>&, set<int>&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

set<int> s1;
vector<int> v1;
int x;
string str;

getline(cin, str);
istringstream sin(str);
while (sin >> x)
	v1.push_back(x);

findrepeatnumber(v1, s1);
 
cout << endl; system("pause"); return 0;
}

void findrepeatnumber(vector<int> &v1, set<int> &s1)
{
	for (int n : v1)
	{
		if (s1.count(n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		s1.insert(n);
	}
}
