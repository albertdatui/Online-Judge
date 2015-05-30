#include <iostream>
#include <vector>
#include <queue>

#define max(a,b) ((a > b)? (a) : (b))
#define min(a,b) ((a > b)? (b) : (a))
using namespace std;

int main()
{
	int TC;
	cin >> TC;

	while (TC--)
	{
		queue<int> left_car, right_car;
		bool left = true;
		int N, T, M;
		cin >> N >> T >> M;

		vector<int> arrival(M, 0), departure(M, 0);

		for (int i = 0; i < M; i++)
		{
			string s; int temp;
			cin >> temp >> s;
			arrival[i] = temp;
			if (s == "left") left_car.push(i);
			else right_car.push(i);
		}

		int clock = 0;

		while (!left_car.empty() || !right_car.empty())
		{
			int temp = N;
			string next = (left_car.empty() ? "right" :
						   right_car.empty() ? "left" :
						   arrival[right_car.front()] == arrival[left_car.front()] ? (left ? "left" :"right") : 
						   (clock >= arrival[left_car.front()] && clock >= arrival[right_car.front()])? (left ? "left" : "right") :
						   arrival[right_car.front()] < arrival[left_car.front()] ? "right" :
						   "left" );

			if (next == "left") clock = max(clock, arrival[left_car.front()]);
			else clock = max(clock, arrival[right_car.front()]);
			if (left)
			{
				if (next == "right")
				{
					clock += T;
					left = !left;
				}
				else
				{
					if (clock < arrival[left_car.front()]) clock = arrival[left_car.front()];
					while (temp-- && !left_car.empty() && clock >= arrival[left_car.front()])
					{
						departure[left_car.front()] = clock + T;
						left_car.pop();
					}
					clock += T;
					left = !left;
				}
			}
			else
			{
				if (next == "left")
				{
					clock += T;
					left = !left;
				}
				else
				{
					if (clock < arrival[right_car.front()]) clock = arrival[right_car.front()];
					while (temp-- && !right_car.empty() && clock >= arrival[right_car.front()])
					{
						departure[right_car.front()] = clock + T;
						right_car.pop();
					}
					clock += T;
					left = !left;
				}
			}
		}

		for (int i = 0; i < M; i++)
		{
			cout << departure[i] << endl;
		}
		if (TC) cout << endl;
	}
}