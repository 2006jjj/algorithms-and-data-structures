/*Задача 1.7
На координатной плоскости расположены равнобедренный прямоугольный треугольник ABC с длиной катета d и точка X. 
Катеты треугольника лежат на осях координат, а вершины расположены в точках: A (0,0), B (d,0), C (0,d).
Напишите программу, которая определяет взаимное расположение точки X и треугольника. 
Если точка X расположена внутри или на сторонах треугольника, выведите 0. Если же точка находится вне треугольника, выведите номер ближайшей к ней вершины.

Формат ввода
Сначала вводится натуральное число d (не превосходящее 1000), а затем координаты точки X – два целых числа из диапазона от ­–1000 до 1000.

Формат вывода
Если точка лежит внутри, на стороне треугольника или совпадает с одной из вершин, то выведите число 0. 
Если точка лежит вне треугольника, то выведите номер вершины треугольника, к которой она расположена ближе всего (1 – к вершине A, 2 – к B, 3 – к C).
Если точка расположена на одинаковом расстоянии от двух вершин, выведите ту вершину, номер которой меньше.

Пример 1:
Ввод:
5
1 1
Вывод: 3

Пример 2:
Ввод:
3
-1 -1
Вывод: 1

Пример 3:
Ввод:
4
4 4
Вывод: 2

Пример 4:
Ввод:
4
2 2
Вывод: 0  */


#include <iostream> 
using namespace std;


int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int d, x, y;
cout << "Введите число d: "<<endl;
cin >> d;
if (d > 1000 || d <= 0)
  cout << "Error" << endl;
else
{
  cout << "Введите координаты точки (х, у):" << endl;
  cin >> x >> y;
  if (x < -1000 || x > 1000 || y < -1000 || y > 1000)
    cout << "Error" << endl;
  else
  {
    int a, b, c;
    if (x >= 0 && y >= 0 && y <= d - x)
      cout << "0 " << endl;
    else
    {
      a = x * x + y * y;
      b = (x - d) * (x - d) + y * y;
      c = x * x + (y - d) * (y - d);
      //cout << "\na=" << a << "\nb=" << b << "\nc=" << c << endl;
      ((a <= b && a <= c) ? cout<<"1" : (b <= c) ? cout<<"2" : cout<<"3");
    }
  }
}
cout << endl; system("pause"); return 0;
}
