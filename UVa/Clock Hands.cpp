#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	string s1, s2;

	while (getline(cin, s1, ':') && getline(cin, s2))
	{
		double H, M;
		H = atof(s1.c_str()); M = atof(s2.c_str());

		if (H == 0 && M == 0){
			return 0;
		}

		double ans;
		ans = fabs((H/12)*360 - (M/60)*360 + (M/60)*30);
		cout << fixed << setprecision(3) << ((ans > 180.0)? 360 - ans : ans) << endl;
	}
}