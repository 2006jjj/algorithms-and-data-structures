/*Задача 4.10
Клуб Юных Хакеров организовал на своем сайте форум. Форум имеет следующую структуру:
каждое сообщение либо начинает новую тему, либо является ответом на какое-либо предыдущее сообщение и принадлежит той же теме.
После нескольких месяцев использования своего форума юных хакеров заинтересовал вопрос - какая тема на их форуме наиболее популярна. 
Помогите им выяснить это.

Формат ввода
В первой строке вводится целое число N - количество сообщений в форуме (1 <= N <= 1000). Следующие строки содержат описание сообщений в хронологическом порядке.
Описание сообщения, которое представляет собой начало новой темы, состоит из трех строк. Первая строка содержит число 0. Вторая строка содержит название темы. 
Длина названия не превышает 30 символов. Третья строка содержит текст сообщения. Описание сообщения, которое является ответом на другое сообщение, состоит из двух строк. 
Первая строка содержит целое число - номер сообщения, ответом на которое оно является. 
Сообщения нумеруются, начиная с единицы. Ответ всегда появляется позже, чем сообщение, ответом на которое он является. Вторая строка содержит текст сообщения.
Длина каждого из сообщений не превышает 100 символов.

Формат вывода
Выведите название темы, к которой относится наибольшее количество сообщений. Если таких тем несколько, то выведите первую в хронологическом порядке

Пример 1
Ввод:
7
0
Олимпиада по информатике
Скоро третья командная олимпиада?
0
Новая компьютерная игра
Вышла новая крутая игра!
1
Она пройдет 24 ноября
1
В Санкт-Петербурге и Барнауле
2
Где найти?
4
Примет участие более 50 команд
6
Интересно, какие будут задачи

Вывод:
Олимпиада по информатике


Пример 2
Ввод:
1
0
topic 1
body 1

Вывод:
topic 1*/

#include <iostream> 
#include <string> 
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void FillingVectors(vector<string>&, vector<int>&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

vector<string> str_vec;
vector<int> num_vec;
map<int, int> mainmap;

FillingVectors(str_vec, num_vec);
//cout << endl; for (const auto& element : str_vec) cout << element<< " ";
//cout << endl; for (const auto& element : num_vec) cout << element << " ";

for (const auto& v1 : num_vec) 
	mainmap[v1]++;
//cout << endl; for (const auto& [key, value] : mainmap) cout << key<<" " << value << endl;

vector<pair<int, int>> ans (mainmap.begin(), mainmap.end());
//for (const auto& element : ans) cout << element.first << " " << element.second << endl;

sort(ans.begin(), ans.end(), [](const pair<int, int>& a, const pair<int, int>& b)
	{
		if (a.second != b.second)
			return a.second > b.second;
		return a.first < b.first;
	});

cout << str_vec[ans[0].first];

cout << endl;  system("pause"); return 0;
}

void FillingVectors(vector<string>& v_str, vector<int>& v_int)
{
	string input;
	getline(cin, input);
	int n = stoi(input);
  
	if (n >= 1 && n <= 1000)
	{
		for (int i = 0; i < n; ++i)
		{
			if (input.empty())
				break;

			getline(cin, input);
			if (input == "0")
			{
				int top_index = v_str.size();
				v_int.push_back(top_index);

				getline(cin, input);
				v_str.push_back(input);

				getline(cin, input);
			}
			else
			{
				v_int.push_back(v_int[stoi(input) - 1]);
				getline(cin, input);
			}
		}
	}
}
