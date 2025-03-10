/*Задача 2.4
Дана последовательности чисел длиной N (N>1)
Найти максимальное число в последовательности и второе по величине число 
(такое, которое будет максимальным, если вычеркнуть из последовательности одно максимальное число).*/

#include <iostream> 
using namespace std;

pair<int,int> findTWOmax(int *, const int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int array[] = { 1, 2, 33, -4, 53, 66, 77, -5 };
const int MAX = sizeof(array)/sizeof(array[0]);
auto p = findTWOmax(array, MAX);
cout << "Первый максимум:" << p.first << "\nВторой максимум:" << p.second << endl;

cout << endl; system("pause"); return 0;
}

pair<int, int> findTWOmax(int* array, const int MAX)
{
  int max1 = max(array[0], array[1]);
  int max2 = min(*array, *array+1);
  for (int j = 2; j < MAX; j++)
  {
    if (array[j] > max1)
    {
      max2 = max1;
      max1 = array[j];
    }
    else if (array[j] > max2)
      max2 = array[j];
  }
  return pair<int, int>(max1, max2);
}
