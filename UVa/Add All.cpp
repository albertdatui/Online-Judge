#include <iostream>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N;
	while(cin >> N)
	{
		if (N == 0) break;
		priority_queue<int, vector<int>, std::greater<int>> PQ;

		int cost = 0, ans = 0;
		while(N--)
		{
			int temp;
			cin >> temp;
			PQ.push(temp);
		}

		while (PQ.size() >= 2)
		{
			ans = PQ.top(); PQ.pop();
			ans += PQ.top(); PQ.pop();

			cost += ans;
			PQ.push(ans);
		}

		cout << cost << endl;
	}
}