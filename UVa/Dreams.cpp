#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define min(a,b) ((a > b) ? (b) : (a))

using namespace std;

int main()
{
	int TC;
	cin >> TC;

	while(TC--)
	{
		int N;
		vector<int> degree;
		degree.clear();
		
		int temp;
		cin >> N;

		while (N--)
		{
			cin >> temp;
			degree.push_back(temp);
		}

		sort(degree.begin(), degree.end(), greater<int>());

		bool valid = true;
		int total = 0;

		for (int i = 0; i < degree.size(); i++)
		{
			total += degree[i];
			int left = 0, right = 0;
			for (int j = 0; j < degree.size(); j++)
			{
				if (j <= i) left += degree[j];
				else right += min(i+1, degree[j]);
			}
			right += (i+1)*(i);

			if (left > right) valid = false;
		}
		if (total%2 != 0) valid = false;

		if (valid) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}