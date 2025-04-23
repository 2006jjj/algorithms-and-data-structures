/*Задача 4.7
Как известно, в США президент выбирается не прямым голосованием, а путем двухуровневого голосования. Сначала проводятся выборы в каждом штате и определяется победитель выборов в данном штате. 
Затем проводятся государственные выборы: на этих выборах каждый штат имеет определенное число голосов — число выборщиков от этого штата. 
На практике, все выборщики от штата голосуют в соответствии с результами голосования внутри штата, то есть на заключительной стадии выборов в голосовании участвуют штаты, имеющие различное число голосов. 
Вам известно за кого проголосовал каждый штат и сколько голосов было отдано данным штатом. Подведите итоги выборов: для каждого из участника голосования определите число отданных за него голосов.

Формат ввода
Каждая строка входного файла содержит фамилию кандидата, за которого отдают голоса выборщики этого штата, затем через пробел идет количество выборщиков, отдавших голоса за этого кандидата.

Формат вывода
Выведите фамилии всех кандидатов в лексикографическом порядке, затем, через пробел, количество отданных за них голосов.

Пример 1
Ввод:
McCain 10
McCain 5
Obama 9
Obama 8
McCain 1

Вывод:
McCain 16
Obama 17


Пример 2
Ввод:
ivanov 100
ivanov 500
ivanov 300
petr 70
tourist 1
tourist 2

Вывод:
ivanov 900
petr 70
tourist 3


Пример 3
Ввод:
bur 1

Вывод:
bur 1*/


#include <iostream> 
#include <string> 
#include <sstream>
#include <map>
using namespace std;

void Election_USA(map<string, int>&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

map<string, int> mainmap;
Election_USA(mainmap);

cout << endl;  system("pause"); return 0;
}

void Election_USA(map<string, int>& mainmap)
{
	string input;
	while (true)
	{
		string key;
		int value;
		getline(cin, input);
		if (input.empty())
			break;

		istringstream sin(input);
		sin >> key >> value;
		mainmap[key] += value;
	}

	for (const auto& [key, value] : mainmap)
		cout << key << " " << value << endl;
}
