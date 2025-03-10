/*Задача 2.3
Дана последовательность чисел длиной N (N>0)
Найти максимальное число в последовательности.*/

#include <iostream> 
using namespace std;

const int MAX = 6;
int findmax(int *);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int array[MAX] = { 1,2,1,6,3,1 };
cout<<findmax(array);

cout << endl; system("pause"); return 0;
}

int findmax(int *array)
{
  int ans = *array;
  for (int j = 1; j < MAX; j++)
  {
    if (array[j] > ans)
      ans = array[j];
    cout << "array[" << j << "]=" << array[j] << endl;
  }
  cout << "Ответ:";
  return ans;
}
