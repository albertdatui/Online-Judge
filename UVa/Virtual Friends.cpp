#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> ds;
vector<int> dsSize;
map<string, int> ppl;
int findSet(int i);
bool isSameSet(int i, int j);
void unionSet(int i, int j);

int main()
{
	int TC;
	cin >> TC;

	while(TC--)
	{
		ds.clear(); ppl.clear(); dsSize.clear();

		int N;
		cin >> N;
		string s1, s2;
		while (N--)
		{
			cin >> s1 >> s2;
			if (ppl.count(s1) == 0)
			{
				ds.push_back(ds.size());
				dsSize.push_back(1);
				ppl.insert(pair<string, int> (s1, ds.size() - 1));
			}

			if (ppl.count(s2) == 0)
			{
				ds.push_back(ds.size());
				dsSize.push_back(1);
				ppl.insert(pair<string, int> (s2, ds.size() - 1));
			}

			unionSet(ppl[s1], ppl[s2]);
			cout << dsSize[findSet(ppl[s2])] << endl;
		}
		//if (TC) cout << endl;
	}
}

int findSet(int i)
{
	if (ds[i] == i) return i;
	else return (ds[i] = findSet(ds[i]));
}

bool isSameSet(int i, int j)
{
	return (findSet(i) == findSet(j));
}

void unionSet(int i, int j)
{
	if (findSet(i) != findSet(j)) dsSize[findSet(j)] += dsSize[findSet(i)];
	ds[findSet(i)] = findSet(j);
}