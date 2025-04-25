/*Задача 4.9
Статья 83 закона “О выборах депутатов Государственной Думы Федерального Собрания Российской Федерации” определяет следующий алгоритм пропорционального распределения мест в парламенте.
Необходимо распределить 450 мест между партиями, участвовавших в выборах. 
Сначала подсчитывается сумма голосов избирателей, поданных за каждую партию и подсчитывается сумма голосов, поданных за все партии. 
Эта сумма делится на 450, получается величина, называемая “первое избирательное частное” (смысл первого избирательного частного - это количество голосов избирателей, 
которое необходимо набрать для получения одного места в парламенте).
Далее каждая партия получает столько мест в парламенте, чему равна целая часть от деления числа голосов за данную партию на первое избирательное частное.
Если после первого раунда распределения мест сумма количества мест, отданных партиям, меньше 450, то оставшиеся места передаются по одному партиям, 
в порядке убывания дробной части частного от деления числа голосов за данную партию на первое избирательное частное. 
Если же для двух партий эти дробные части равны, то преимущество отдается той партии, которая получила большее число голосов.

Формат ввода
На вход программе подается список партий, участвовавших в выборах. 
Каждая строка входного файла содержит название партии (строка, возможно, содержащая пробелы), 
затем, через пробел, количество голосов, полученных данной партией – число, не превосходящее 10^8.

Формат вывода
Программа должна вывести названия всех партий и количество голосов в парламенте, полученных данной партией. 
Названия необходимо выводить в том же порядке, в котором они шли во входных данных.

Пример 1
Ввод:
Party One 100000
Party Two 200000
Party Three 400000

Вывод:
Party One 64
Party Two 129
Party Three 257


Пример 2
Ввод:
Party number one 100
Partytwo 100

Вывод:
Party number one 225
Partytwo 225


Пример 3
Ввод:
Party number one 449
Partytwo 1

Вывод:
Party number one 449
Partytwo 1*/

#include <iostream> 
#include <string> 
#include <algorithm>
#include <vector>
using namespace std;

struct Party
{
	string name;
	long long votes;
	int seats, pos;
	float fractionalPart;
	Party():name(" "), votes(0), seats(0), pos(0), fractionalPart(0.0f) {}
};

long long VectorFilling(vector<Party>&);
int DistributionSeats(long long&, vector<Party>&);
void DistributionRemainingSeats(int&, vector<Party>&);
void PrintResult(vector<Party>& vec);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

	vector<Party> mainvector;
	long long all_votes = VectorFilling(mainvector);
	int free_seats = DistributionSeats(all_votes, mainvector);

	sort(mainvector.begin(), mainvector.end(), [](const Party& a, const Party& b) 
		{ return a.fractionalPart > b.fractionalPart; });

	DistributionRemainingSeats(free_seats, mainvector);

	sort(mainvector.begin(), mainvector.end(), [](const Party& a, const Party& b) 
		{ return a.pos < b.pos; });

	PrintResult(mainvector);
 
cout << endl;  system("pause"); return 0;
}

//Заполнение структуры: название партии, число голосов, позиция в списке, возвращение общего количества голосов
long long VectorFilling(vector<Party>& vec)
{
	string input;
	long long all_votes = 0;
	int i = 0;
  
	while (getline(cin, input))
	{
		if (input.empty())
			break;

		Party party;
		size_t pos = input.find_last_of(' ');
		party.name = input.substr(0, pos);
		string numStr = input.substr(pos + 1);
		party.votes = stoi(numStr);
		all_votes += party.votes;
		party.pos = i++;
		vec.push_back(party);
	}
	//cout << "ALL_VOTES=" << all_votes << endl;
	return all_votes;
}

//Распределение мест, возвращение сколько мест осталось
int DistributionSeats(long long& all_votes, vector<Party>& vec)
{
	float f = all_votes / 450.0; //cout << "f=" << f << endl;
	int free_seats = 450;
	for (auto& element : vec)
	{
		element.seats = element.votes / f;
		free_seats -= element.seats;
		element.fractionalPart = element.votes / f - element.seats;
	}
	//cout << "FREE_SEATS=" << free_seats << endl;
	return free_seats;
}

//Дораспределение оставшихся мест по дробной части
void DistributionRemainingSeats(int& free_seats, vector<Party>& vec)
{
	for (int i = 0; i < free_seats; i++)
		vec[i % vec.size()].seats++;
}

//Вывод результата
void PrintResult(vector<Party>& vec)
{
	for (const auto& element : vec) cout << element.name << " " << element.seats << endl;
}
