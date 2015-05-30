#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> ds;

bool invalid(vector<int> _v, int N)
{
	int valid = 0;
	for (int i = 0; i < _v.size(); i++)
	{
		if (_v[i] == 0) return true;
		if (_v[i] == 1) valid++;
	}

	if (valid != N) return true;
	else return false;
}
int main()
{
	int N;
	vector<vector<int>> connection;
	string s;

	while (cin >> N)
	{
		ds.assign(26, -1);
		connection.assign(26, vector<int>(26, 0));
		
		int TC;
		cin >> TC;

		cin >> s;
		for (int i = 0; i < 3; i++)
			ds[s[i]-'A'] = 1;

		while (TC--)
		{
			cin >> s;
			connection[s[0] - 'A'][s[1] - 'A'] = 1;
			connection[s[1] - 'A'][s[0] - 'A'] = 1;

			for (int i = 0; i < 2; i++)
			{
				if (ds[s[i] - 'A'] == -1)
					ds[s[i] - 'A'] = 0;
			}
			
		}

		int ans = 0;

		vector<int> temp;
		while(invalid(ds,N))
		{
			// for (int i = 0; i < 26; i++)
			// {
			// 	cout << ds[i] << " ";
			// }
			// cout << endl;
			temp.clear();
			for (int i = 0; i < 26; i++)
			{
				if (ds[i] == 0)
				{	
					int counter = 0;
					for (int j = 0; j < 26; j++)
					{
						if (connection[i][j] == 1 && ds[j] == 1)
							counter++;
					}
					if (counter >= 3) temp.push_back(i);
				}
			}

			if (temp.empty()) break;
			else
			{
				ans++;
				for (int k = 0; k < (int) temp.size(); k++)
					ds[temp[k]] = 1;
			}
		}

		if (invalid(ds,N)) cout << "THIS BRAIN NEVER WAKES UP" << endl;
		else cout << "WAKE UP IN, " << ans << ", YEARS" << endl;
	}
}