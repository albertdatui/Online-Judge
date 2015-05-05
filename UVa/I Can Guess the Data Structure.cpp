#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main()
{
	int N;

	while(cin >> N)
	{
		stack<int> Stack;
		queue<int> Queue;
		priority_queue<int> PQ;
		vector<int> choices(3, 1); // 0 -> stack, 1 -> queue, 2 -> priority_queue

		while(N--)
		{
			int cmd, data;
			cin >> cmd >> data;

			if (cmd == 1)
			{
				Stack.push(data);
				Queue.push(data);
				PQ.push(data);
			}
			else
			{
				if (Stack.empty() || Queue.empty() || PQ.empty())
				{
					choices[0] = 0;
					choices[1] = 0;
					choices[2] = 0;
				}
				else
				{
					if (data != Stack.top()) choices[0] = 0;
					if (data != Queue.front()) choices[1] = 0;
					if (data != PQ.top()) choices[2] = 0;

					Stack.pop(); Queue.pop(); PQ.pop();
				}
			}
		}

		int ans = 0, type;

		for (int i = 0; i < 3; i++)
		{
			ans += choices[i];
			if (choices[i] == 1) type = i;
		}
		
		if (ans == 0) cout << "impossible" << endl;
		else if (ans > 1) cout << "not sure" << endl;
		else
		{
			if (type == 0) cout << "stack" << endl;
			else if (type == 1) cout << "queue" << endl;
			else cout << "priority queue" << endl;
		}
	}
}