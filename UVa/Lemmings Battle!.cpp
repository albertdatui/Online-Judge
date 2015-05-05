#include <iostream>
#include <set>
#include <vector>

#define min(a,b) ((a > b)? (b) : (a))

using namespace std;

typedef multiset<int, greater<int>>::iterator ITER;
int main()
{
	int TC;
	cin >> TC;
	
	multiset<int, greater<int>> BlueArmy, GreenArmy;

	while(TC--)
	{
		int N, Green, Blue;
		cin >> N >> Green >> Blue;

		BlueArmy.clear(); GreenArmy.clear();

		while (Green--)
		{
			int temp; cin >> temp;
			GreenArmy.insert(temp);
		}

		while (Blue--)
		{
			int temp; cin >> temp;
			BlueArmy.insert(temp);
		}

		while (!BlueArmy.empty() && !GreenArmy.empty())
		{
			int B = min(N, min(BlueArmy.size(), GreenArmy.size()));

			vector<int> BFight, GFight;
			BFight.clear(); GFight.clear();

			//cout << B << endl;

			int counter = 0;
			for (ITER Blue_it = BlueArmy.begin(); counter < B; counter++)
			{
				BFight.push_back(*Blue_it); BlueArmy.erase(Blue_it++);
			}

			counter = 0;
			for (ITER Green_it = GreenArmy.begin(); counter < B; counter++)
			{
				GFight.push_back(*Green_it); GreenArmy.erase(Green_it++);
			}

			for (int i = 0; i < B; i++)
			{
				//cout << BFight[i] << " " << GFight[i] << endl;
				if (BFight[i] > GFight[i])
				{
					BFight[i] -= GFight[i];
					GFight[i] = 0;
				}
				else
				{
					GFight[i] -= BFight[i];
					BFight[i] = 0;
				}
				if (BFight[i] != 0) BlueArmy.insert(BFight[i]);
				if (GFight[i] != 0) GreenArmy.insert(GFight[i]);
			}
			//cout << "Finish" << endl;
		}

		if (BlueArmy.empty() && GreenArmy.empty()) cout << "green and blue died" << endl;
		else if (BlueArmy.empty())
		{
			cout << "green wins" << endl;
			for (ITER it = GreenArmy.begin(); it != GreenArmy.end(); ++it)
				cout << *it << endl;
		}
		else
		{
			cout << "blue wins" << endl;
			for (ITER it = BlueArmy.begin(); it != BlueArmy.end(); ++it)
				cout << *it << endl;
		}

		if (TC) cout << endl;
	}
}