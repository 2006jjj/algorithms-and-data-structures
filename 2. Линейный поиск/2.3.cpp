/*Задача 2.3
Дана последовательность чисел длиной N (N>0)
Найти максимальное число в последовательности (и индекс).*/

#include <iostream> 
using namespace std;

const int MAX = 6;
int findmax(int *);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int array[MAX] = { 3, -2, -1, -6, -3, -1 };
cout<<findmax(array);

cout << endl; system("pause"); return 0;
}

int findmax(int *array)
{
  int ans = 0;
  for (int j = 1; j < MAX; j++)
  {
    if (array[j] > array[ans])
      ans = j;
  }
  cout << "Индекс:"<< ans << "\nОтвет:";
  return array[ans];
}
