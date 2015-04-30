#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int TC;
	cin >> TC;

	while(TC--)
	{
		int player_num, special_num, dierolls;
		cin >> player_num >> special_num >> dierolls;

		vector<int> maps(150,-1);
		vector<int> player(player_num, 1);

		while(special_num--)
		{
			int init, goal;
			cin >> init >> goal;

			maps[init] = goal;
		}
		int current = 0;
		while(dierolls--)
		{
			int foo;
			cin >> foo;

			player[current] += foo;
			
			if (maps[player[current]] != -1)
				player[current] = maps[player[current]];

			if (player[current] >= 100)
			{
				break;
			}
			current++;
			current %= player_num;
		}

		while(dierolls > 0)
		{
			int foo;
			cin >> foo;
			dierolls--;
		}

		for (int i = 0; i < player.size(); i++)
		{
			cout << "Position of player " << i + 1 << " is " << ((player[i] > 100)? 100 : player[i]) << "." << endl;
		}
	}
}