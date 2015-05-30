#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int TC;
	cin >> TC;
	int a;
	int diff, sum;
	
	while (TC--)
	{
		cin >> sum >> diff;
		if (sum >= diff && (sum+diff)%2 == 0 && (sum-diff)%2 == 0)
		{
			a = (sum + diff) / 2;

			if ((sum - a) >= 0) cout << a << " " << sum - a << endl;
			else cout << "impossible" << endl;
		}
		else cout << "impossible" << endl;
	}
}