/*Задача 3.1 
Написать свое множество с помощью двумерного массива и 3 функции (добавление, нахождение, удаление элемента)*/

#include <iostream> 
#include <iomanip> 
using namespace std;

void addnum(int(*)[], int, const int);
bool findnum(int(*)[], int, int);
void deletenum(int(*)[], int, int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

	int a = 25;
	const int setsize = 10;
	int myset[setsize][setsize]{};
 
	addnum(myset, a, setsize);
	addnum(myset, 7, setsize);
	addnum(myset, 0, setsize);
	addnum(myset, 62, setsize);
	addnum(myset, 17, setsize);
	addnum(myset, 88, setsize);
	addnum(myset, 20, setsize);
	addnum(myset, 48, setsize);
	addnum(myset, 47, setsize);
	addnum(myset, 56, setsize);
	addnum(myset, 65, setsize);
	addnum(myset, 74, setsize);
	addnum(myset, 83, setsize);
	addnum(myset, 99, setsize);
	addnum(myset, 117, setsize);
	addnum(myset, 117, setsize);
	addnum(myset, 117, setsize);
	addnum(myset, 117, setsize);
	addnum(myset, 107, setsize);
	addnum(myset, 10, setsize);
	addnum(myset, 117, setsize);
	addnum(myset, 777, setsize);
	addnum(myset, 73, setsize);
	addnum(myset, 2, setsize); 
	addnum(myset, 2, setsize);
	addnum(myset, 2, setsize);
	addnum(myset, 11, setsize);
 
	deletenum(myset, 0, setsize);
	deletenum(myset, 9, setsize);
	deletenum(myset, 7, setsize);
	deletenum(myset, 7, setsize);
	deletenum(myset, 7, setsize);

	bool find_number = 0;
	find_number = findnum(myset, 117, setsize);
	cout << "find_number=" << find_number << endl;
	for (int i = 0; i < setsize; i++)
	{
		for (int j = 0; j < setsize; j++)
			cout << setw(5)<< myset[i][j] ;
		cout << endl; 
	}

cout << endl; system("pause");return 0;
}

void addnum(int(*array)[], int a, const int asize)
{
	short maxsize = asize * asize;
	short hash = a % asize;
	for (int i = 0; i < maxsize; i += asize)
	{
		if ((*array + i)[hash] != 0 && (*array + i + asize)[hash] == 0)
		{
			(*array + i + asize)[hash] = a;
			break;
		}
		else
			if ((*array)[hash] == 0)
			{
				(*array)[hash] = a;
				break;
			}
	}
}

bool findnum(int(*array)[], int a, int asize)
{
	short maxsize = asize * asize;
	for (int i = 0; i < maxsize; i += asize)
	{
		if ((*array + i)[a % asize] == a)
			return true;
	}
	return false;
}

void deletenum(int(*array)[], int a, int asize)
{
	short maxsize = asize * asize;
	short hash = a % asize;
	for (int i = 0; i < maxsize; i += asize)
	{
		if ((*array + i)[hash] != 0 && (*array + i + asize)[hash] == 0)
		{
			(*array + i)[hash] = 0;
			break;
		}
		else
			if ((*array + maxsize - asize)[hash] != 0)
			{
				(*array + maxsize - asize)[hash] = 0;
				break;
			}
	}
}
