#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool valid(vector<vector<int>>& _grid)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (_grid[i][j] != 0) return true;

	return false;
}
int main()
{
	int TC; char s;
	cin >> TC;
	cin.clear(); cin.clear();
	vector<vector<int>> grid(3,vector<int>(3));

	while (TC--)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j ++)
			{
				cin >> s;
				grid[i][j] = (int)s - '0';
			}
			cin.clear();
		}

		int ans = -1;
		while(valid(grid))
		{
			vector<vector<int>> temp(3, vector<int>(3));
			temp[0][0] = (grid[1][0] + grid[0][1]) % 2;
			temp[0][1] = (grid[0][0] + grid[0][2] + grid[1][1]) % 2;
			temp[0][2] = (grid[1][2] + grid[0][1]) % 2;
			temp[1][0] = (grid[0][0] + grid[2][0] + grid[1][1]) % 2;
			temp[1][1] = (grid[0][1] + grid[2][1] + grid[1][2] + grid[1][0]) % 2;
			temp[1][2] = (grid[0][2] + grid[2][2] + grid[1][1]) % 2;
			temp[2][0] = (grid[1][0] + grid[2][1]) % 2;
			temp[2][1] = (grid[2][2] + grid[2][0] + grid[1][1]) % 2;
			temp[2][2] = (grid[1][2] + grid[2][1]) % 2;
			grid = temp;
			ans++;
		}
		cin.clear();

		cout << ans << endl;
	}
}