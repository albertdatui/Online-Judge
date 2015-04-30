#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
	int R, C;

	cin >> R >> C;

	while ((R!=0) && (C!=0))
	{
		if (R >= 3 && C >= 3)
			cout << (((R*C)%2 == 0)? (R*C)/2 : (R*C)/2 + 1) << " ";
		else if ((R == 1) || (C == 1))
			cout << R*C << " ";
		else
			cout << (max(R,C)/4 * 4 + ((max(R,C)%4 == 1)? 2 : ((max(R,C)%4 >= 2)? 4 : 0))) << " ";

		cout << "knights may be placed on a " << R << " row " << C << " column board." << endl;
		cin >> R >> C;
	}
}