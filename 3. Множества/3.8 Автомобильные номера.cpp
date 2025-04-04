/*Задача 3.8
Неизвестный водитель совершил ДТП и скрылся с места происшествия. Полиция опрашивает свидетелей. Каждый из них говорит, что запомнил какие-то буквы и цифры номера. 
Но при этом свидетели не помнят порядок этих цифр и букв. Полиция хочет проверить несколько подозреваемых автомобилей. 
Будем говорить, что номер согласуется с показанием свидетеля, если все символы, которые назвал свидетель, присутствуют в этом номере (не важно, сколько раз).

Формат ввода
Сначала задано число  - количество свидетелей. Далее идет M строк, каждая из которых описывает показания очередного свидетеля. 
Эти строки непустые и состоят из не более чем 20 символов. Каждый символ в строке - либо цифра, либо заглавная латинская буква, причём символы могут повторяться.
Затем идёт число  - количество номеров. Следующие строки представляют из себя номера подозреваемых машин и имеют такой же формат, как и показания свидетелей.

Формат вывода
Выпишите номера автомобилей, согласующиеся с максимальным количеством свидетелей. 
Если таких номеров несколько, то выведите их в том же порядке, в котором они были заданы на входе.

Пример 1
Ввод:
3
ABC
A37
BCDA
2
A317BD
B137AC

Вывод: 
B137AC

Пример 2
Ввод:
2
1ABC
3A4B
3
A143BC
C143AB
AAABC1

Вывод: 
A143BC
C143AB*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool CheckCarNumbers(unordered_set<char>&, const string&);

int main()
{
	setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

	int M, N;
  //Создание вектора с неупорядоченными символьными множествами (показания свидетелей)
	cin >> M;
	vector<unordered_set<char>> indications;
	for (int i = 0; i < M; i++)
	{
		unordered_set<char> symbols;
		string str;
		cin >> str;
		for (const char& c : str)
			symbols.insert(c);
		indications.push_back(symbols);
	}

  //Создание вектора с номерами машин
	cin >> N;
	vector<string> car_numbers(N);
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		car_numbers[i] = str;
	}
  
	/*cout << endl;
	for (unordered_set<char>& x : indications)
	{
		for (const char& c : x)
			cout << c << " ";
		cout << endl;
	}
	cout << endl;
	for (const string& s : car_numbers)
		cout << s << endl;*/

  //Создание вектора с количеством совпадений, функция CheckCarNumbers правильно подсчитывает количество свидетелей, с которыми согласуется каждый номер
	vector<int> matchCounts(N, 0);
	for (int i = 0; i < N; i++)
	{
		for (unordered_set<char>& x : indications)
		{
			if (CheckCarNumbers(x, car_numbers[i]))
				matchCounts[i]++;
		}
	}

	//for (int n : matchCounts) cout << n << ' ';

  //Поиск максимального количества совпадений
	int maxcount = *max_element(matchCounts.begin(), matchCounts.end());
	//cout << "\nMaxCount=" << maxcount << endl;

  //Ответ
	for (int i = 0; i < N; i++)
	{
		if (matchCounts[i] == maxcounts)
			cout << car_numbers[i] << endl;
	}
  
cout << endl; system("pause"); return 0;
}

bool CheckCarNumbers(unordered_set<char> &x, const string &str)
{
	for (const char &c : x)
	{
		if (str.find(c) == string::npos)
			return false;
	}
	return true;
}
