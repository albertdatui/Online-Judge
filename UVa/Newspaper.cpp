//It is a very interesting problem.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
	string s;

	int TC;
	cin >> TC; getline(cin,s);
	while(TC--)
	{
		int dict[256];
		memset(dict, 0, sizeof(dict));
		double total = 0;
		int temp;
		cin >> temp; getline(cin,s);

		unsigned char key; int money;
		while(temp--)
		{
			cin >> key >> money; getline(cin,s);
			//cout << key << " " << money << endl;
			dict[int(key)] = money;
		}

		cin >> temp; getline(cin,s);
		while(temp--)
		{
			unsigned char c;
			while((c = cin.get()) != '\n')
			{
				total += dict[(int)c];
			}
		}
		//cout << total << endl;
		cout << fixed << setprecision(2) << total/100.0 << "$" << endl;
	}
}