/*Задача 4.5
Сгруппировать слова по общим буквам
Sample Input : ["eat", "tea", "tan", "ate", "nat", "bat"]
Sample Output: [["ate", "eat", "tea"], ["nat", "tan"], ["bat"]]*/

#include <iostream> 
#include <string> 
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<vector<string>> sorted_strings(vector <string>&);
void print_sorted_vector(vector<vector<string>>&);

int main()
{setlocale(LC_ALL, ".1251"); system("color 0F"); srand(time(NULL));

vector <string> main_vector{"eat", "tea", "tan", "ate", "nat", "bat"};
vector<vector<string>> result = sorted_strings(main_vector);
print_sorted_vector(result);

cout << endl;  system("pause"); return 0;
}

vector<vector<string>> sorted_strings(vector<string>& vec)
{
	unordered_map<string, vector<string>> mapStr;
	vector<vector<string>> result;
	for (const auto& s : vec)
	{
		string sorted_str = s;
		sort(sorted_str.begin(), sorted_str.end());
		//cout << "sorted_str=" << sorted_str << endl;
		mapStr[sorted_str].push_back(s);
	}
	//for (const auto& element : main_map){ cout << "key=" << element.first<<endl; for (const auto& str : element.second)cout << " value=" << str << endl; }

	for (const auto& [key, value] : mapStr)
		result.push_back(value);

	for (auto& vec : result)
		sort(vec.begin(), vec.end());

	return result;
}

void print_sorted_vector(vector<vector<string>>& result)
{
	for (auto& vec : result)
	{
		cout << "[";
		for (const auto& str : vec)
			cout << str << " ";
		cout << "]\n";
	}
}
