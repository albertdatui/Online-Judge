#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s;

	while (getline(cin,s))
	{
		if (s == "") continue;
		stack<vector<int>> Math;
		stringstream ss; ss << s;
		
		int temp;
		while (ss >> temp)
		{
			//cout << temp << endl;
			vector<int> foo(2, 0); foo[0] = temp;
			if (Math.empty())
			{
				Math.push(foo); continue;
			}

			if (temp < 0) 
			{
				//cout << "Pushing to stack" << " " << foo[0] << " " << foo[1] << endl;
				Math.push(foo);
			}
			else
			{
				if (abs(Math.top()[0]) == temp)
				{
					//cout << "Popping the stack" << " " << temp << endl;
					if (temp <= Math.top()[1])
					{
						//cout << temp << " " << Math.top()[1] << endl;
						//cout << "Not Sufficient" << endl;
						break;
					}
					foo = Math.top();
					Math.pop();
					if (!Math.empty()) 
					{
						Math.top()[1] += (abs(foo[0]));
						//cout << "Popping Success => The top is " << Math.top()[0] << " " << Math.top()[1] << endl;
					}
					else
					{
						//cout << "Popping Success" << endl;
					}
				}
				else
				{
					//cout << "Pushing to stack" << " " << foo[0] << " " << foo[1] << endl;
					Math.push(foo);
				}
			}
		}

		if (Math.empty()) cout << ":-) Matrioshka!" << endl;
		else cout << ":-( Try again." << endl;
	}
}