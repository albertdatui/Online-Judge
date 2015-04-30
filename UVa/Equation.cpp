#include <iostream>
#include <vector>
#include <string>

using namespace std;

int op_pow(string s)
{
	if (s == "/" || s == "*") return 2;
	else if (s == "+" || s == "-") return 1;
	else return 0;
}

int main()
{
	vector<string> op;
	vector<string> answer;

	int TC;
	cin >> TC;
	string s;
	getline(cin,s);	getline(cin,s);

	while(TC--)
	{
		op.clear(); answer.clear();
		while(getline(cin,s))
		{
			if (s == "") break;
			if (s >= "0" && s <= "9") answer.push_back(s);
			else if (s == "(") op.push_back(s);
			else if (s == ")")
			{
				while(op.back() != "(")
				{
					answer.push_back(op.back());
					op.pop_back();
				}
				op.pop_back();
			}
			else
			{
				while(1)
				{
					if (op.empty())
					{
						op.push_back(s);
						break;
					}
					else if (op_pow(s) > op_pow(op.back()))
					{
						op.push_back(s);
						break;
					}
					else
					{
						answer.push_back(op.back());
						op.pop_back();
					}
				}
			}
			//cout << answer.size() << " -> " << op.size() << endl;
		}

		while (!op.empty())
		{
			answer.push_back(op.back());
			op.pop_back();
		}

		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i];
		}
		cout << endl;
		if (TC) cout << endl;
	}

}