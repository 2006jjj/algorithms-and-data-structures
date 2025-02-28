/*Задача 1.2
Даны три целых числа a, b, c.
Найдите все корни уравнения ax^2 + bx + c = 0 и выведите их в порядке возрастания.*/

#include <iostream> 
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int a = 0, b = 0, c = 0, d = 0;
float x1 = 0.0, x2 = 0.0;
cout << "Введите 3 переменные:";
cin >> a >> b >> c;

if (a == 0)
{
  if (b != 0)
    cout << "x=" << (-c / b);
  if (b == 0 && c == 0)
    cout << "Бесконечное количество решений"<<endl;
}
else
{
  d = (b * b) - (4 * a * c);
  cout << "D=" << sqrt(d)<<endl;
  if (d == 0)
  {
    x1 = - b  / (2 * a);
    cout << "x1=" << x1 << endl;
  }
  else if (d > 0)
  {
    x1 = (-b - sqrt(d)) / (2 * a);
    x2 = (-b + sqrt(d)) / (2 * a);
    (x1 < x2) ? cout << "x1=" << x1 << "\nx2=" << x2 << endl 
              : cout << "x1=" << x2 << "\nx2=" << x1 << endl;
  }
  else 
    cout << "D < 0, решений нет";
}

cout << endl; system("pause"); return 0;
}
