#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


int check_super(string& palindrome)
{
	int C;
	C = sqrt(palindrome.size());
	
	if (C*C == palindrome.size())
	{
		for (int i = 0; i < C; i++)
		{
			for (int j = 0; j < C; j++)
			{
				//cout << palindrome[i*C + j] << palindrome[j*C + i] << palindrome[(C-1 - j)*C + (C-1 - i)] << palindrome[(C-1 - i)*C + (C-1 - j)] << endl;
				if ((palindrome[i*C + j] == palindrome[j*C + i]) && 
					(palindrome[i*C + j] == palindrome[(C-1 - j)*C + (C-1 - i)]) &&
					(palindrome[i*C + j] == palindrome[(C-1 - i)*C + (C-1 - j)]))
					continue;
				else
					return 0;
			}
		}
		return C;
	}
	else return 0;
}

int main()
{
	int TC, Case = 0;
	cin >> TC;

	string s, temp;
	getline(cin, s);
	while (++Case <= TC)
	{
		getline(cin, s);
		temp = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				temp += s[i];
			}
		}

		

		cout << "Case #" << Case << ":" << endl;
		
		int result = check_super(temp);
		if (result)
		{
			cout << result << endl;
		}
		else
		{
			cout << "No magic :(" << endl;
		}
	}
}