#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int TC;
	cin >> TC;
	int _TC = 0;
	while(_TC++ < TC)
	{
		int R, C, BIG, SMALL;
		cin >> R >> C >> BIG >> SMALL;
		vector<int> freq(26,0);

		string s;
		int foo = 0;
		while(foo++ < R)
		{
			cin >> s;
			for (int i = 0; i < s.size(); i++)
				freq[(int)(s[i] - 'A')]++;
		}

		sort(freq.begin(), freq.end(), greater<int>());

		int ans = 0, max = freq[0];

		for (int i = 1; i < freq.size(); i++)
		{
			if (max == freq[i]) ans = i;
		}

		ans = (R*C - (ans + 1)*max)*SMALL + (ans + 1)*max*BIG;
		cout << "Case " << _TC << ": " << ans << endl;
	}
}