/*Задача 6.3
Михаил читает лекции по алгоритмам. За кадром стоит доска размером W*H сантиметров. 
Михаилу нужно разместить на доске N квадратных стикеров со шпаргалками, при этом длина стороны стикера в сантиметрах должна быть целым числом.
Определите максимальную длину стороны стикера, чтобы все стикеры поместились на доске. */


#include <iostream> 
using namespace std;

int rbinsearch(int, int, int);
bool check(int, int, int, int);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL)); ios::sync_with_stdio(false); cin.tie(nullptr);

int W, H, N;
cout << "Введите параметры доски (W и H):" << endl;
cin >> W >> H;
cout << "Введите количество стикеров которые нужно разместить:"<<endl;
cin >> N;

//cout << "\nN=" << N << " \nW=" << W << "\nH="<< H;

int result = rbinsearch(W, H, N);
cout << "\nRESULT=" << result;

cout << endl;  system("pause"); return 0;
}

int rbinsearch(int W, int H, int N)
{
	int left = 1;
	int right = min(W, H);
  
	while (left != right)
	{
		int mid = (left + right + 1) / 2;
		if (check(mid, W, H, N))
			left = mid;
		else
			right = mid - 1;
	}
	return left;
}


bool check(int size, int w, int h, int N) 
{ 
	return (w / size) * (h / size) >= N;
}
