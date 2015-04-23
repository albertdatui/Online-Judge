#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int k;
	cin >> k;
	
	int ans[13] = {2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

	while (k != 0)
	{
		cout << ans[k-1] << endl;
		cin >> k;
	}

	// int m = k;
	// bool valid = false;

	// while (!valid)
	// {
	// 	int size = 2*k;
	// 	m++;
	// 	int index = (m - 1)%size;

	// 	while (true)
	// 	{
	// 		if (index < k)
	// 		{
	// 			break;
	// 		}
	// 		size--;
	// 		if (size == k)
	// 		{
	// 			cout << m << endl;
	// 			valid = true;
	// 			break;
	// 		}
	// 		index += (m - 1);
	// 		index %= size;
	// 	}
	// }
}