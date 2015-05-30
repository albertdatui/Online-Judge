#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int find(int student, vector<int>& vec)
{
	for (int i = 0; i < (int) vec.size(); i++)
	{
		if (vec[i] == student) return i;
	}
}

int main()
{
	int N, M;
	while ((cin >> N >> M) && ((M != 0) || (N != 0)))
	{
		vector<vector<int>> constraint;

		while(M--)
		{
			int temp, foo, dist;
			cin >> temp >> foo >> dist;
			vector<int> foobuzz (3,0);
			foobuzz[0] = temp; foobuzz[1] = foo; foobuzz[2] = dist;
			constraint.push_back(foobuzz);
		}

		vector<int> configuration(N);
		for (int i = 0; i < N; i++)
		{
			configuration[i] = i;
		}

		int ans = 0;
		do
		{
			bool verdict = true;

			for (int i = 0; i < (int) constraint.size(); i++)
			{
				int pos1 = find(constraint[i][0], configuration);
				int pos2 = find(constraint[i][1], configuration);
				int dist = abs(pos1 - pos2);

				if ((constraint[i][2] > 0) && (dist > constraint[i][2]))
				{
					verdict = false;
					break;
				}

				if ((constraint[i][2] < 0) && (dist < abs(constraint[i][2])))
				{
					verdict = false;
					break;
				}
			}

			if (verdict) ans++;
		}while(next_permutation(configuration.begin(), configuration.end()));

		cout << ans << endl;
	}
}