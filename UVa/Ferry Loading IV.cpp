#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	queue<int> left_car, right_car;
	int TC;
	cin >> TC;
	string s;

	while (TC--)
	{
		bool left = true;
		int L, foo, ans = 0;
		cin >> L >> foo;

		while (foo--)
		{
			int temp;
			cin >> temp >> s;
			if (s == "left") left_car.push(temp);
			else right_car.push(temp);
		}

		while (!left_car.empty() || !right_car.empty())
		{
			int temp = L*100;
			if (left)
			{
				while ((!left_car.empty()) && (temp >= left_car.front()))
				{
					temp -= left_car.front();
					left_car.pop();
				}
				left = !left;
				ans++;
			}
			else
			{
				while ((!right_car.empty()) && (temp >= right_car.front()))
				{
					temp -= right_car.front();
					right_car.pop();
				}
				left = !left;
				ans++;
			}
		}
		cout << ans << endl;
	}
}