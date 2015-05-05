#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int sortedness(string& s)
{
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i + 1; j < s.length(); j++)
		{
			if (s[i] > s[j]) count++;
		}
	}
	return count;
}

int main()
{
	int TC;
	cin >> TC;
	int M, N;
	vector<string> data;
	vector<pair<int, int>> index;
	
	while (TC--)
	{
		data.clear(); index.clear();
		cin >> M >> N;
		string s;

		while (N--)
		{
			cin >> s;
			data.push_back(s);
			index.push_back(pair<int, int>(sortedness(s), data.size() - 1));
		}

		sort(index.begin(), index.end());

		for (int i = 0; i < data.size(); i++)
		{
			cout << data[index[i].second] << endl;
		}

		//cout << TC << endl;
		if (TC) 
		{
			cout << endl;
		}
	}
}