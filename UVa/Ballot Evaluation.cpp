#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, int> vote;
	int N, M;
	cin >> N >> M;
	string s;

	while (N--)
	{
		cin >> s;
		int a, b;
		scanf("%d.%d", &a, &b);
		vote.insert(pair<string, int> (s, a*10 + b));
	}

	int counter = 0;
	while (counter++ < M)
	{
		int ans = 0;
		while(cin >> s)
		{
			if (s == "+") continue;
			if (s == ">" || s == "<" || s == "<=" || s == ">=" || s == "=") break;

			ans += vote[s];
		}
		int perc;
		cin >> perc;
		perc *= 10;
		
		//cout << ans << " " << perc << endl;

		cout << "Guess #" << counter << " was ";
		bool verdict;

		if (s == ">") verdict = (ans > perc)? true : false;
		else if (s == ">=") verdict = (ans >= perc)? true : false;
		else if (s == "<") verdict = (ans < perc)? true : false;
		else if (s == "<=") verdict = (ans <= perc)? true : false;
		else if (s == "=") verdict = (ans == perc)? true : false;

		if (verdict) cout << "correct." << endl;
		else cout << "incorrect." << endl;
	}
}