#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int R, C;
	vector<vector<pair<int, int>>> Adj, TAdj;
	while(cin >> R >> C)
	{
		Adj.assign(R, vector<pair<int, int>>());
		TAdj.assign(C, vector<pair<int, int>>());

		for (int i = 0; i < R; i++)
		{
			int temp, foo;
			cin >> temp;
			vector<int> cols, value;

			for (int j = 0; j < temp; j++)
			{
				cin >> foo;
				cols.push_back(foo);
			}

			for (int j = 0; j < temp; j++)
			{
				cin >> foo;
				value.push_back(foo);
			}

			for (int j = 0; j < temp; j++)
				Adj[i].push_back(pair<int, int>(cols[j] - 1, value[j]));
		}

		//cout << "Here" << endl;
		for(int i = 0; i < R; i++)
			for (int j = 0; j < (int)Adj[i].size(); j++)
				TAdj[Adj[i][j].first].push_back(pair<int, int> (i ,Adj[i][j].second));

		//cout << "Here Again" << endl;
		cout << C << " " << R << endl;
		for (int i = 0; i < C; i++)
		{
			cout << (int) TAdj[i].size();
			if ((int) TAdj[i].size() == 0) 
			{
				cout << endl << endl;
				continue;
			}
			else cout << " ";
			
			for (int j = 0; j < (int) TAdj[i].size(); j++)
			{
				cout << TAdj[i][j].first + 1;
				if (j == (int)TAdj[i].size() - 1) cout << endl;
				else cout << " ";
			}

			for (int j = 0; j < (int) TAdj[i].size(); j++)
			{
				cout << TAdj[i][j].second;
				if (j == (int)TAdj[i].size() - 1) cout << endl;
				else cout << " ";
			}
		}
	}
}