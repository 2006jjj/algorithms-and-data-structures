/*Задача 2.7
Игра PitCraft происходит в двумерном мире, который состоит из блоков размером 1 на 1 метр. 
Остров игрока представляет собой набор столбцов различной высоты, состоящих из блоков камня и окруженный морем.
Над островом прошел сильный дождь, который заполнил водой все низины, а не поместившаяся в них вода стекла в море, не увеличив его уровень.
По ландшафту острова определите, сколько блоков воды осталось после дождя в низинах на острове. 

Вычисляем индекс самой высокой горы, и в два прохода с двух сторон вычисляем кубики с водой.*/

#include <iostream> 
usingnamespace std;

int findx(int* array, const int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int array[] = { 3, 1, 4, 3, 5, 4, 6, 1, 1, 3, 1 };
const int MAX = sizeof(array) / sizeof(array[0]);

cout<<findx(array, MAX);

cout << endl; system("pause"); return 0;
}

int findx(int* array, const int MAX)
{
	int maxpos = 0;
	for (int j = 1; j < MAX; j++)
	{
		if (array[j] > maxpos)
			maxpos = j;
	}

	cout << "maxpos=" << maxpos << endl;
	cout << array[maxpos] << endl;

	int ans = 0;
	int nowmax = 0;

	for (int j = 0; j < maxpos; j++)
	{
		if (array[j] > nowmax)
			nowmax = array[j];
		ans += nowmax - array[j];
	}

	nowmax = 0;
	for (int j = MAX - 1; j > maxpos; j--)
	{
		if (array[j] > nowmax)
			nowmax = array[j];
		ans += nowmax - array[j];
	}
	cout << "ans=";
	return ans;
}
