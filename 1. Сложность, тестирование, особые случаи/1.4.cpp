/*Задача 1.4 Кольцевая линия метро
Витя работает недалеко от одной из станций кольцевой линии Московского метро, а живет рядом с другой станцией той же линии. 
Требуется выяснить, мимо какого наименьшего количества промежуточных станций необходимо проехать Вите по кольцу, чтобы добраться с работы домой.

Формат ввода
Станции пронумерованы подряд натуральными числами 1, 2, 3, …, N (1-я станция – соседняя с N-й), N не превосходит 100.

Вводятся три числа: сначала N – общее количество станций кольцевой линии, а затем i и j – номера станции, на которой Витя садится, и станции, на которой он должен выйти. 
Числа i и j не совпадают. Все числа разделены пробелом.

Формат вывода
Требуется выдать минимальное количество промежуточных станций (не считая станции посадки и высадки), которые необходимо проехать Вите.*/


#include <iostream> 
#include <cstdlib>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int i, j, a, b, N = 0;
cout << "Введите N, i, j:"<<endl;
cin >> N >> i >> j;
if (i < j)
{
  //a = i + abs(j - N) - 1;
  a = N - abs(i-j)-1;
  cout << "a=" << a<<endl;}
else
{
  //a = j + abs(i - N) - 1;
  a = N - abs(j - i) - 1;
  cout << "a=" << a << endl;
}
b = abs(i - j) - 1;
cout << "b=" << b << endl;
(a < b) ? cout << "\notvet:" << a : cout << "\notvet:" << b << endl;
 
cout << endl; system("pause"); return 0;
}
