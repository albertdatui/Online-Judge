#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
	int F, R;

	while (cin >> F && F != 0)
	{
		cin >> R;
		double ans = 0.0;
		vector<int> front, rear;
		vector<double> spread;

		while (F--)
		{
			int temp; cin >> temp;
			front.push_back(temp);
		}

		while (R--)
		{
			int temp; cin >> temp;
			rear.push_back(temp);
		}

		for (int i = 0; i < (int) front.size(); i++)
		{
			for (int j = 0; j < (int) rear.size(); j++)
			{
				spread.push_back((double)front[i]/(double)rear[j]);
			}
		}

		sort(spread.begin(), spread.end());

		for (int i = 1; i < (int) spread.size(); i++)
		{
			if (ans < spread[i]/spread[i-1]) ans = spread[i]/spread[i-1];
		}

		cout << fixed << setprecision(2) << ans << endl;
	}
}