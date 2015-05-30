#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, rep;
	vector<vector<int>> arr;

	while(cin >> N >> rep)
	{
		arr.assign(1000001,vector<int>());

		int temp, foo;
		for (int i = 1; i <= N; i++)
		{
			cin >> temp;
			arr[temp].push_back(i);
		}

		while(rep--)
		{
			cin >> temp >> foo;
			if (temp > arr[foo].size()) cout << 0 << endl;
			else
				cout << arr[foo][temp-1] << endl;
		}
	}
}