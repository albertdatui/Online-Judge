#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(char a, char b)
{
	if (tolower(a) == tolower(b))
	{
		return a < b;
	}
	return tolower(a) < tolower(b);
}

int main()
{
	int TC;
	cin >> TC;

	string s;
	while (TC--)
	{
		cin >> s;

		sort(s.begin(), s.end(), comp);
		do
		{
			cout << s << endl;
		}while(next_permutation(s.begin(), s.end(), comp));
	}
	return 0;
}

