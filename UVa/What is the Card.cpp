#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int TC, _TC = 0;
	cin >> TC;
	vector<pair<string,int>> cards;
	string s;

	while(_TC++ < TC)
	{
		int count = 52;
		cards.clear();
		while (count--)
		{
			cin >> s;
			if (s[0] == 'A' || s[0] == 'K' || s[0] == 'Q' || s[0] == 'J' || s[0] == 'T')
				cards.push_back(pair<string, int>(s, 10));
			else
				cards.push_back(pair<string, int>(s, (int)(s[0] - '0')));
		}

		int Y = 0, index = 26;

		for (int i = 0; i < 3; i++)
		{
			Y += cards[index].second;
			index += (1 + 10 - cards[index].second);
		}
		cout << "Case " << _TC << ": " << cards[index+Y-27].first << endl;
	}
}