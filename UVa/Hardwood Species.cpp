#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
	int TC;
	cin >> TC;
	string s;
	getline(cin, s); getline(cin, s);

	map<string, int> leaves;

	while(TC--)
	{
		int total = 0;
		leaves.clear();
		while(getline(cin,s))
		{
			if (s == "") break;

			pair<map<string, int>::iterator, bool> ret;
			total++;
			ret = leaves.insert(pair<string, int>(s,1));

			if (ret.second == false)
			{
				ret.first->second++;
			}
		}

		for (map<string, int>::iterator it = leaves.begin(); it != leaves.end(); ++it)
		{
			cout << fixed << setprecision(4) << it->first << " " << (double)(it->second/(double)total)*100 << endl;
		}
		if (TC) cout << endl;
	}		
}