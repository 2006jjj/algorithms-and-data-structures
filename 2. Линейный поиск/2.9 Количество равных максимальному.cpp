/*Задача 2.9
Последовательность состоит из натуральных чисел и завершается числом 0. 
Всего вводится не более 10000 чисел (не считая завершающего числа 0). 
Определите, сколько элементов этой последовательности равны ее наибольшему элементу.
Числа, следующие за числом 0, считывать не нужно.

Формат ввода
Вводится последовательность целых чисел, оканчивающаяся числом 0 (само число 0 в последовательность не входит).

Формат вывода
Выведите ответ на задачу.

Пример 1
Ввод:
1 7 9 0
Вывод:
1

Пример 2
Ввод:
1 3 3 1 0
Вывод:
2*/

#include <iostream> 
using namespace std;

int findcountmaxnumber();
int main()
{setlocale(LC_ALL, ".1251"); std::system("color 0F"); srand(time(NULL));

cout << findcountmaxnumber() << endl;


cout << endl; system("pause");return 0;
}
int findcountmaxnumber()
{
	const int MAX = 10001;
	int array[MAX]{}, i;

	for (int j = 0; j < MAX; j++)
	{
		cin >> i;
		array[j] = i;
		if (array[j] == 0)
			break;
	}
	
	int maxnumber = 0, finalcount = 0;
	for (int j = 0; array[j] != 0; j++)
	{
		if (array[j] > maxnumber)
		{
			maxnumber = array[j];
			finalcount = 0;
		}
		if (array[j] == maxnumber)
			finalcount++;

		cout << array[j] << " ";
	}
	cout << "\nmaxnumber=" << maxnumber << endl;
	return finalcount;
}
