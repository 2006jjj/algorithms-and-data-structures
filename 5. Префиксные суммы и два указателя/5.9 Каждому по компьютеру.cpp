/*Задача 5.9
В новом учебном году во Дворец Творчества Юных для занятий в компьютерных классах пришли учащиеся, которые были разбиты на N групп.
В i-й группе оказалось Xi человек. Тут же перед директором встала серьезная проблема: как распределить группы по аудиториям. 
Во дворце имеется M ≥ N аудиторий, в j-й аудитории имеется Yj компьютеров. Для занятий необходимо, чтобы у каждого учащегося был компьютер и еще один компьютер был у преподавателя. 
Переносить компьютеры из одной аудитории в другую запрещается. Помогите директору!
Напишите программу для поиска максимального количества групп, которое удастся одновременно распределить по аудиториям, 
чтобы всем учащимся в каждой группе хватило компьютеров, и при этом остался хотя бы один для учителя.

Формат ввода
На первой строке входного файла расположены числа N и M (1 ≤ N ≤ M ≤ 1000). 
На второй строке расположено N чисел — X1, ...,XN (1 ≤ Xi ≤ 1000 для всех 1 ≤ i ≤ N).
На третьей строке расположено M чисел Y1, ..., YM (1 ≤ Yi ≤ 1000 для всех 1 ≤ i ≤ M).

Формат вывода
Выведите на первой строке число P — количество групп, которое удастся распределить по аудиториям. 
На второй строке выведите распределение групп по аудиториям — N чисел, i-е число должно соответствовать номеру аудитории, в которой должна заниматься i-я группа. 
Нумерация как групп, так и аудиторий, начинается с 1. Если i-я группа осталась без аудитории, i-е число должно быть равно 0. 
Если допустимых распределений несколько, выведите любое из них.

Пример 1
Ввод:
1 1
1
2
Вывод:
1
1 


Пример 2
Ввод:
1 1
1
1
Вывод:
0
0*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void InsertVector(vector<pair<int, int>>&, const int&);
void CountGroupsAndRooms(vector<pair<int, int>>&, vector<pair<int, int>>&, const int&, const int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

int n, m;
cin >> n >> m;
vector<pair<int, int>> vecN (n);
vector<pair<int, int>> vecM (m);

InsertVector(vecN, n);
InsertVector(vecM, m);

sort(vecN.begin(), vecN.end(), [](const auto& a, const auto& b) { return a.first < b.first; });
sort(vecM.begin(), vecM.end(), [](const auto& a, const auto& b) { return a.first < b.first; });

for (int i = 0; i < n; ++i)
	vecN[i].first += 1;

//cout << "\nGroups:" << endl; for (const auto& n : vecN) cout << n.first << " " << n.second << endl;
//cout <<"Rooms:" << endl; for (const auto& m : vecM) cout << m.first << " " << m.second << endl; cout << endl;

CountGroupsAndRooms(vecN, vecM, n, m);

cout << endl;  system("pause"); return 0;
}


void InsertVector(vector<pair<int, int>>& vec, const int& x)
{
	for (int i = 0; i < x; ++i)
	{
		cin >> vec[i].first;
		vec[i].second = i + 1;
	}
}

void CountGroupsAndRooms(vector<pair<int, int>>& vecN, vector<pair<int, int>>& vecM, const int& n, const int& m)
{
	vector<int> result(n + 1, 0);
	int P = 0;
	int room = 0;
	int group = 0;

	for (int group = 0; group < n && room < m; ++group)
	{
		while (room < m && vecM[room].first < vecN[group].first)
			++room;

		if (room < m)
		{
			result[vecN[group].second] = vecM[room].second;
			++P;
			++room;
		}
	}
	cout << "\n" << P << endl;
	for (int i = 1; i <= n; ++i) 
		cout << result[i] << " ";
}
