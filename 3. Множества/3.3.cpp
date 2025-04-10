/*Задача 3.3
Дан словарь из N слов, длина каждого не превосходит K
В записи каждого из M слов текста (каждое длиной до K) может быть пропущена одна буква.
Для каждого слова сказать, входит ли оно (возможно, с одной пропущенной буквой), в словарь.*/

#include <iostream> 
#include <set>
#include <string> 
#include <algorithm>
#include <vector>
using namespace std;

void checkwords(vector<string>&, set<string>&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

set<string> s1, newwords;
vector<string> words_to_check;
string input;
int N, M;
cout << "Введите количество слов в словаре: ";
cin >> N;
cout << "Введите ваши слова в словарь:" << endl;
for (int i = 0; i < N; i++)
{
	cin >> input;
	s1.insert(input);
}
for (const string& str : s1)
{
	string testword;
	for (int i = 0; i < str.size(); i++)
	{
		testword = str;
		newwords.insert(testword);
		//testword.erase(i, 1);
		testword = str.substr(0, i) + str.substr(i+1);
		newwords.insert(testword);
	}
	cout << endl;
}
//for (const string& s : s2) cout << s << endl;
//for (const string &s : newwords) cout << s << endl;

cout << "Введите количество слов в тексте для проверки, есть ли они в словаре: ";
cin >> M;
cout << "\nВведите слова на проверку (допускается пропуск одной буквы):" << endl;
for (int i = 0; i < M; i++)
{
	cin >> input;
	words_to_check.push_back(input);
}
cout << endl;
//for (const string &s : words_to_check)  cout << s << endl;
 
checkwords(words_to_check, newwords);

cout << endl;  system("pause"); return 0;
}

void checkwords(vector<string>& words_to_check, set<string>& all_words)
{
	int x = 1;
	for (const string& s : words_to_check)
	{
		if (all_words.find(s) != all_words.end())
		//if(all_words.contains(s))
			cout << x++ << ") yes" << endl;
		else
			cout << x++ << ") no" << endl;
	}
}
