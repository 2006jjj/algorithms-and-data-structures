/*Задача 2.6
Дана последовательность слов
Вывести все самые короткие слова через пробел.*/

#include <iostream>
#include <string> 
using namespace std;

string findshortword(string* array, const int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

string array[] = { "abc", "aaa", "c", "d", "fv", "ffff" , "alalla", "f"};
const int MAX = sizeof(array) / sizeof(array[0]);
findshortword(array, MAX);

cout << endl; system("pause"); return 0;
}

string findshortword(string* array, const int MAX)
{
  string ans;
  int minlen = array->length();
  
  for (int j = 0; j < MAX; j++)
  {
    if (array[j].length() < minlen)
      minlen = array[j].length();
  }
  
  for (int j = 0; j < MAX; j++)
  {
    if (array[j].length() == minlen)
      ans.append(array[j] + ' ');
  }
  cout << "ans=" << ans;
	return ans;
}
