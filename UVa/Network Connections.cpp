#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int findSet(vector<int>& UFDS, int i);
bool isSameSet(vector<int>& UFDS, int i, int j);
void unionSet(vector<int> & UFDS, int i, int j);

int main()
{
	int TC;
	cin >> TC;

	stringstream ss;
	while (TC--)
	{
		int N, S = 0, NS = 0;
		cin >> N;

		vector<int> UFDS(N);
		for (int i = 0; i < N; i++)
			UFDS[i] = i;

		string s; int c1, c2;
		
		getline(cin,s);
		while(getline(cin, s))
		{
			if (s == "") break;
			ss.clear();
			ss << s;
			ss >> s >> c1 >> c2;
			c1--; c2--;

			if (s == "c")
				unionSet(UFDS, c1, c2);
			else
			{
				if (isSameSet(UFDS, c1, c2)) S++;
				else NS++;
			}
		}

		cout << S << "," << NS << endl;
		if (TC) cout << endl;
	}
}

int findSet(vector<int>& UFDS, int i)
{
	return (UFDS[i] == i? i : UFDS[i] = findSet(UFDS, UFDS[i]));
}

void unionSet(vector<int> & UFDS, int i, int j)
{
	UFDS[findSet(UFDS,i)] = findSet(UFDS, j);
}

bool isSameSet(vector<int>& UFDS, int i, int j)
{
	return (findSet(UFDS, i) == findSet(UFDS, j));
}