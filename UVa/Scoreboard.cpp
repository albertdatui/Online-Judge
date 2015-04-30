#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

bool comp(vector<int> T1, vector<int> T2)
{
	if (T1[11] != T2[11])
		return T1[11] > T2[11];

	if (T1[12] != T2[12])
		return T1[12] < T2[12];

	return T1[0] < T2[0];
}

int main()
{
	int TC;
	cin >> TC;

	string s;
	stringstream ss;
	getline(cin, s);
	getline(cin, s);

	while(TC--)
	{
		vector<vector<int>> scoreboard(100,vector<int>(14,0));
		for (int i = 0; i < 100; i++)
			scoreboard[i][0] = i + 1;

		while(getline(cin, s))
		{
			if (s.empty()) break;
			int team, probs, time;
			string verdict;
			ss.clear();
			ss << s;
			ss >> team >> probs >> time >> verdict;
			
			scoreboard[team-1][13] = 1;
			if ((verdict == "C") && (scoreboard[team-1][probs] != -1))
			{
				scoreboard[team - 1][11]++;
				scoreboard[team - 1][12] += time;
				scoreboard[team - 1][12] += scoreboard[team - 1][probs];
				scoreboard[team - 1][probs] = -1;
			}

			if ((verdict == "I") && (scoreboard[team-1][probs] != -1))
				scoreboard[team-1][probs] += 20;

			//cout << team << " " << probs << " " << time << " " << verdict << endl;
		}

		sort(scoreboard.begin(), scoreboard.end(), comp);

		for (int i = 0; i < 100; i++)
		{
			if (scoreboard[i][13] == 1)
			{
				cout << scoreboard[i][0] << " " << scoreboard[i][11] << " " << scoreboard[i][12] << endl;
			}
		}

		if (TC)
			cout << endl;
	}
}