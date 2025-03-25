/*Задача 3.6
Дан список. Выведите те его элементы, которые встречаются в списке только один раз. 
Элементы нужно выводить в том порядке, в котором они встречаются в списке.

Формат ввода
Вводится список чисел. Все числа списка находятся на одной строке.

Формат вывода
Выведите ответ на задачу.

Пример 1
Ввод:
1 2 2 3 3 3
Вывод:
1

Пример 2
Ввод:
4 3 5 2 5 1 3 5
Вывод:
4 2 1 */

#include <iostream> 
#include <string> 
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

void finduniquenumbers();
int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));
 
finduniquenumbers();

cout << endl; system("pause"); return 0;
}

void finduniquenumbers()
{
	vector<int> v1;
	int x;
	string str;
	getline(cin, str);
	istringstream sin(str);

	while (sin >> x)
		v1.push_back(x);

	for (int n : v1)
	{
		if (count(v1.begin(), v1.end(), n) == 1)
			cout << n << ' ';
	}
}
