#include <iostream>
#include <vector>

using namespace std;

bool all_visited(vector<int>& town)
{
	for (int i = 0; i < town.size(); i++)
	{
		if (town[i] == 0) return false;
	}
	return true;
}
int main()
{
	int N;
	cin >> N;

	while (N != 0)
	{
		int m = 0;
		bool valid = false;

		while(!valid)
		{
			int index = 0;
			vector<int> town(N,0);
			m++;

			while (true)
			{
				//cout << index << endl;
				town[index%N] = 1;

				if (all_visited(town) && ((index%N) == 12))
				{
					cout << m << endl;
					valid = true;
					break;
				}
				else if (all_visited(town))
				{
					break;
				}

				for (int i = 0; i < m; i++)
				{
					while(town[(index+1)%N] != 0)
					{
						index++;
					}
					index++;
				}
				//cout << m << endl;
				// for (int i = 0; i < town.size(); i++)
				// {
				// 	cout << town[i] << " ";
				// }
				// cout << endl;
			}
		}
		cin >> N;
	}
	return 0;
}