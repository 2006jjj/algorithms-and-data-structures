/*Задача 4.4
Дана строка S 
Выведите гистограмму как в примере (коды символов отсортированы)
S = Hello, world!

      #
      ##
##########
 !,Hdelorw
 */

#include <iostream> 
#include <map>
using namespace std;

void print_chart(string&);
void add_chart(map<char, int>&, char);
//bool compareValues(const pair<const char, int>&, const pair<const char, int>&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

string S = "Hello, world!";
print_chart(S);

cout << endl;  system("pause"); return 0;
}


void print_chart(string& s)
{
	map <char, int> strMap;
  int maxCount = 0;
	for (const char ch : s) 
		add_chart(strMap, ch);
	//for (const auto& [key, value] : strMap) cout << "key=" << key << " value=" << value << endl;

	for (const auto& [ch, count] : strMap)
		maxCount = max(maxCount, count);
	//cout << "maxCount=" << maxCount << endl;
  
	/*Поиск максимум через свою функцию
  auto max_pair = *max_element(strMap.begin(), strMap.end(), compareValues);
	Поиск максимума по значению через лямбда-функцию
	auto max_pair = *max_element(strMap.begin(), strMap.end(), [](const pair<const char, int>& a, const pair<const char, int>& b)  {  return a.second < b.second;  });
  cout << "Ключ:" << max_pair.first << " Значение:" << max_pair.second << endl<<endl;*/

	for (int i = maxCount; i != 0; --i)
	{
		for (const auto& [ch, value] : strMap)
		{
			if (value >= i)  
				cout << "#";
			else 
				cout << ' ';
		}
		cout << endl;
	}
	for (const auto& element : strMap) cout << element.first;
}

void add_chart(map <char, int>& strmap, char key)
{
	strmap[key]++;
}

//bool compareValues(const pair<const char, int>& a, const pair<const char, int>& b) { return a.second < b.second; }
