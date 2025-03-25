/*Задача 3.4
Даны два списка чисел, которые могут содержать до 100000 чисел каждый. 
Посчитайте, сколько чисел содержится одновременно как в первом списке, так и во втором. 

Формат ввода
Вводятся два списка чисел. Все числа каждого списка находятся на отдельной строке.

Формат вывода
Выведите ответ на задачу.

Пример 1
Ввод:
1 3 2
4 3 2
Вывод: 
2

Пример 2
Ввод:
1 2 6 4 5 7
10 2 3 4 8
Вывод: 
2

Пример 3
Ввод:
1 7 3 8 10 2 5
6 5 2 8 4 3 7
Вывод: 
5*/

#include <iostream> 
#include <string> 
#include <sstream>
#include <set>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

set<int> s1;
int x, count = 0;
string str, str2;

getline(cin, str);
istringstream sin(str);
while (sin >> x)
	s1.insert(x);

getline(cin, str2);
istringstream sin2 (str2);
while (sin2 >> x)
	if (s1.insert(x).second == false)
		count++;
	
//for (int n : s1) cout << n << ' '; 
 
cout << "Ответ:" << count << endl;

cout << endl; system("pause"); return 0;
}
