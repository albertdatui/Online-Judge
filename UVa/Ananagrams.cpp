#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
	map <string, string> dict;
	pair <map<string, string>::iterator, bool> ret;
	vector <string> anagrams;

	string word,key;

	while (cin >> word)
	{
		if (word == "#")
		{
			break;
		}
		
		key = word;
		transform(key.begin(), key.end(), key.begin(), ::tolower);
		sort(key.begin(), key.end());

		ret = dict.insert(pair<string, string>(key, word));
		if (ret.second == false)
		{
			anagrams.push_back(ret.first->first);
		}
	}

	for (int i = 0; i < anagrams.size(); i++)
	{
		dict.erase(anagrams[i]);
	}

	anagrams.clear();

	for (map <string, string>::iterator it=dict.begin(); it != dict.end(); ++it)
	{
		anagrams.push_back(it->second);
	}

	sort(anagrams.begin(), anagrams.end());

	for (int i = 0; i < anagrams.size(); i++)
	{
		cout << anagrams[i] << endl;
	}

	return 0;
}