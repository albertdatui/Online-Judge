#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int TC;
	cin >> TC;
	map<string, vector<string>> dict;
	pair<map<string, vector<string>>::iterator, bool> ret;
	
	while(TC--)
	{
		int N;
		cin >> N;

		dict.clear();
		string s, key;
		vector<string> temp;

		while(N--)
		{
			temp.clear();
			cin >> s;
			key = s;
			temp.push_back(s);
			sort(key.begin(), key.end());
			ret = dict.insert(pair<string, vector<string>>(key,temp));
			if (ret.second == false)
			{
				ret.first->second.push_back(s);
			}
		}

		// for (map<string, vector<string>>::iterator it = dict.begin(); it != dict.end(); ++it)
		// {
		// 	cout << it->first << endl;
		// 	for (int i = 0; i < it->second.size(); i++)
		// 	{
		// 		cout << it->second[i] << endl;
		// 	}
		// }

		cin >> s;
		while(s != "END")
		{
			key = s;
			sort(s.begin(), s.end());
			cout << "Anagrams for: " << key << endl;

			map<string, vector<string>>::iterator iter;
			iter = dict.find(s);
			if (iter != dict.end())
			{
				for (int i = 1; i <= iter->second.size(); i++)
				{
					cout << setw(3) << i << ") " << (iter->second)[i-1] << endl;
				}
			}
			else
			{
				cout << "No anagrams for: " << key << endl;
			}
			cin >> s;
		}
		if (TC != 0)
			cout << endl;
	}
}