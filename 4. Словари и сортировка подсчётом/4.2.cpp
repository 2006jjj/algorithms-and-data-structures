/*Задача 4.2
Дано два числа X и Y без ведущих нулей
Необходимо проверить, можно ли получить первое из второго перестановкой цифр.*/

#include <iostream> 
using namespace std;

bool isdigitpermutation(int&, int&);
void countdigits(int&, int*);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

int x,y;
cout << "Введите ваши числа:"<<endl;
cin >> x >> y;

bool answer= isdigitpermutation(x, y);
answer ? cout << "\nЧисла совпадают"<<endl : cout << "\nЧисла не совпадают" << endl;

cout << endl;  system("pause"); return 0;
}

bool isdigitpermutation(int& x, int& y)
{
	const int N = 10;
	int digits_x[N]{}, digits_y[N]{};
	countdigits(x, digits_x);
	countdigits(y, digits_y);

	for (int digit = 0; digit < N; digit++)
	{
		if (digits_x[digit] != digits_y[digit])
			return false;
	}
	return true;
}

void countdigits(int& num, int*array)
{
	while (num > 0)
	{
		int lastdigit = num % 10;
		array[lastdigit]++;
		num /= 10;
	}
	for (int i = 0; i < 10; i++) cout << *(array + i) << ' ';
	cout << endl;
}
