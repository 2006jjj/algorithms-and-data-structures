/*Задача 1.1
Дана строка (в кодировке UTF-8)
Найти самый часто встречающийся в ней символ.
Если несколько символов встречаются одинаково часто, то можно вывести любой.

Решение:
Заведем словарь, где ключом является символом, а значением - сколько раз он встретился.
Если символ встретился впервые - создаем элемент словаря с ключом, совпадающем с этим символом и значением ноль.
Прибавляем к элементу словаря с ключом, совпадающем с этим символом, единицу.*/


#include <iostream> 
#include <string> 
#include <map>
using namespace std;

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

map<char, int> test {}; 
string s;  
char ch = ' ';  
int count=0;
cout << "Введите вашу строку:"; 
getline(cin, s); 
cout << "string=" << s << endl; 
int strsize = s.size();
for (int i=0; i<strsize; i++)
{
  if (s[i] == test[s[i]])
    test[s[i]] = 0;
  test[s[i]] += 1;
  if (test[s[i]] > count)
  {
    ch = s[i]; 
    count = test[s[i]]; 
  }
}
cout << "\nsymbol=" << ch <<" count="<<count<< endl;
 
//for (auto& element : test) cout << "element.first=" << element.first << " element.second=" << element.second << endl; 

cout << endl; system("pause"); return 0;
}
