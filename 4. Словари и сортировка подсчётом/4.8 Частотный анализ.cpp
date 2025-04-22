/*Задача 4.8
Дан текст. Выведите все слова, встречающиеся в тексте, по одному на каждую строку. 
Слова должны быть отсортированы по убыванию их количества появления в тексте, а при одинаковой частоте появления — в лексикографическом порядке. 
Указание. После того, как вы создадите словарь всех слов, вам захочется отсортировать его по частоте встречаемости слова. 
Желаемого можно добиться, если создать список, элементами которого будут кортежи из двух элементов: частота встречаемости слова и само слово. 
Например, [(2, 'hi'), (1, 'what'), (3, 'is')].
Тогда стандартная сортировка будет сортировать список кортежей, при этом кортежи сравниваются по первому элементу, а если они равны — то по второму. Это почти то, что требуется в задаче.

Формат ввода
Вводится текст.

Формат вывода
Выведите ответ на задачу.

Пример 1
Ввод:
hi
hi
what is your name
my name is bond
james bond
my name is damme
van damme
claude van damme
jean claude van damme

Вывод:
damme
is
name
van
bond
claude
hi
my
james
jean
what
your


Пример 2
Ввод:
oh you touch my tralala
mmm my ding ding dong

Вывод:
ding
my
dong
mmm
oh
touch
tralala
you


Пример 3
Ввод:
ai ai ai ai ai ai ai ai ai ai

Вывод:
ai
*/

#include <iostream> 
#include <string> 
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void MakeMap(map<string, int>&);
void MakeVector(map<string, int>&);
int SortOurVector(const tuple<int, string>&, const tuple<int, string>&);
void PrintVector(vector<tuple<int, string>>&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

map<string, int> mainmap;
MakeMap(mainmap);

cout << endl;  system("pause"); return 0;
}

void MakeMap(map<string, int>& mainmap)
{
	string input, key;
	while (true)
	{
		getline(cin, input);

		if (input.empty()) 
			break;
	
		istringstream sin(input);
		while (sin >> key)
			mainmap[key]++;
	}
	MakeVector(mainmap);
}

void MakeVector(map<string, int>& mainmap)
{
	vector<tuple<int, string>> mainvector;
	for (const auto& [key, value] : mainmap)
		mainvector.push_back(make_tuple(value, key));

	/*лямбда-функция sort(mainvector.begin(), mainvector.end(), [](const tuple<int, string>& a, const tuple<int, string>& b) { return get<0>(a) > get<0>(b); });*/
	sort(mainvector.begin(), mainvector.end(), SortOurVector);
	PrintVector(mainvector);
}

int SortOurVector(const tuple<int, string>& a, const tuple<int, string>& b)
{
	if (get<0>(a) == get<0>(b))
		return get<1>(a) < get<1>(b);
	return get<0>(a) > get<0>(b);
}

void PrintVector(vector<tuple<int, string>>& mainvector)
{
	//for (auto& element : mainvector) cout << get<1>(element) << " " << get<0>(element) << endl;
	for (auto& element : mainvector) cout << get<1>(element) << endl;
}
