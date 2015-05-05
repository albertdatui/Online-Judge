#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
	map<vector<int>, int> courses;

	int N;
	while(cin >> N)
	{
		courses.clear();
		if (N == 0) break;
		int temp, popular = 1, ans = 0;
		vector<int> foo;

		while(N--)
		{
			foo.clear();
			for (int i = 0; i < 5; i++)
			{
				cin >> temp;
				foo.push_back(temp);
				sort(foo.begin(), foo.end());
			}

			pair<map<vector<int>, int>::iterator, bool> it;
			it = courses.insert(pair<vector<int>, int>(foo, 1));
			if (it.second == false)
			{
				it.first->second += 1;
				if (it.first->second > popular) popular = it.first->second;
			}
			//cout << it.first->second << endl;
		}

		for (map<vector<int>, int>::iterator ret = courses.begin(); ret != courses.end(); ++ret)
		{
			if (ret->second == popular) ans += popular;
		}
		cout << ans << endl;
	}
}