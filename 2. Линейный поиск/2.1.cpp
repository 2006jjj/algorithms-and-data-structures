/*Задача 2.1
Дана последовательность чисел длиной N
Найти первое (левое или правое) вхождение положительного числа X в неё или вывести -1, если число X не встречалось.*/

#include <iostream> 
using namespace std;

int findx(int[], int);
const int MAX = 6;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

unsigned int x;
int array[MAX] = { 1,2,1,2,3,1 };
cout << "Введите число x:";
cin >> x;
cout<<findx(array, x);

cout << endl; system("pause"); return 0;
}


int findx(int array[], int x)
{
  int ans = -1;
  char ch;
  cout << "Введите с какой стороны найти первое вхождение числа в массиве? (l/r):";
  cin >> ch;
  if (ch == 'l')
  {
    for (int i = 0; i < MAX; i++)
    {
      if (array[i] == x && ans == -1)
        ans = i;
      cout << "array[" << i << "]=" << array[i] << endl;
    }
  }
  else
  {
    for (int i = 0; i < MAX; i++)
    {
      if (array[i] == x)
        ans = i;
      cout << "array[" << i << "]=" << array[i] << endl;
    }
  }
  cout << "Ответ:";
  return ans;
}
