#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int TC;
	cin >> TC;
	while (TC--)
	{
		int N;
		cin >> N;
		vector<int> party(N);
		int total = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> party[i];
			total += party[i];
		}

		int range = 1 << N;

		vector<int> DP;
		for (int k = 0; k < range; k++)
		{
			DP.push_back(0);
			for (int i = 0; i < N; i++)
				if ((k & (1 << i)) != 0) DP[k] += party[i];
		}

		for (int k = 0; k < N; k++)
		{
			int power = 0;

			for (int i = 0; i < range; i++)
			{
				if ((i & (1 << k)) != 0)
				{
					if (DP[i] - party[k] <= total / 2 && DP[i] > total / 2) power++;
				}
			}
			cout << "party " << k + 1 << " has power index " << power << endl;
		}
		cout << endl;
	}
}