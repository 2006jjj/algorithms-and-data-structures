/*Задача 2.5
Дана последовательность чисел длиной N
Найти минимальное четное число в последовательности или вывести -1, если такого не существует.*/

#include <iostream> 
using namespace std;

int findx(int* array, const int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int array[] = { 1,2,3,4,5,6 };
const int MAX = sizeof(array) / sizeof(array[0]);

cout<<findx(array, MAX);

cout << endl; system("pause"); return 0;
}

int findx(int* array, const int MAX)
{
	int ans = -1;
	bool flag = false;
	for (int j = 0; j < MAX; j++)
	{
		if (array[j] % 2 == 0 && (flag == false || array[j] < ans))
		//if (array[j] % 2 != 0 && (flag == false || array[j] > ans))  //нечетные, > - поиск максимального , < - поиск минимального
		{
			ans = array[j];
			flag = true;
		}

	}
	cout << "Ответ:";
	return ans;
}
