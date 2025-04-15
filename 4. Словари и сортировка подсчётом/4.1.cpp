/*Задача 4.1
Сортировка подсчетом*/

#include <iostream> 
using namespace std;

int findmax(int*, const int&);
int findmin(int*, const int&);
void countsort(int*, const int&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

const int N = 7;
int array[N]{5,4,5,3,3,1,5};
cout << "Неотсортированный массив: " << endl;
for (int n : array) cout << n << ' ';

countsort(array, N);

cout << endl;  system("pause"); return 0;
}

void countsort(int *array, const int& N)
{
	int maxval = findmax(array, N);
	int minval = findmin(array, N);
	const int k = maxval - minval + 1;
	//cout << "\nmaxval=" << maxval << "\nminval=" << minval << "\nk=" << k << endl;

  cout << "\n\nПодсчет позиций: "<<endl;
	int* count = new int[k] {};
	//for (int n = 0 ; n<k; n++) cout << *(count + n) << ' ';
	for (int i = 0; i < N; i++)
		count[array[i] - minval] += 1;
	for (int n = 0; n < k; n++) cout << *(count + n) << ' ';

  cout << "\n\nОтсортированный массив: " << endl;
	int nowpos = 0;
	for (int j = 0; j < k; j++)
	{
		for (int i = 0; i < count[j]; i++)
		{
			array[nowpos] = j + minval;
			cout << *(array + nowpos++)<<' ';
		}
	}
	delete[] count;
}

int findmax(int* array, const int& N)
{
	int ans = 0;
	for (int j = 1; j < N; j++)
	{
		if (array[j] > array[ans])
			ans = j;
	}
	return array[ans];
}

int findmin(int* array, const int& N)
{
	int ans = 0;
	for (int j = 1; j < N; j++)
	{
		if (array[j] < array[ans])
			ans = j;
	}
	return array[ans];
}
