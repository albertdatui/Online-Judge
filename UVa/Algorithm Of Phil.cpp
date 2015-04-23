#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	const long long MOD =  1000000007;

	int TC;
	cin >> TC;
	string S;
	int counter = 1;

	getline(cin,S);
	while(counter <= TC){
		long long ans = 0LL;
		char A[MOD];
		getline(cin,S);
		//cout << S << endl;

		while(S.size()){
			int length = S.size();
			if (length%2 == 1){
				length = length/2;
				A.append(1u,S[length]);
				//A = A + str(S[length]);
				S.erase(S.begin() + length);
			}
			else{
				length = length/2;
				if (int(S[length]) >= int(S[length - 1])){
					A.append(1u,S[length]);
					//A = A + str(S[length]);
					S.erase(S.begin() + length);
				}
				else{
					A.append(1u,S[length-1]);
					//A = A + str(S[length - 1]);
					S.erase(S.begin() + length - 1);
				}
			}
		}

		//cout << A << endl;
		int point = 0;

		while (1){
			if (point == A.size()){
				break;
			}

			ans = (ans*2 + (A[point] - '0'))%MOD;
			point++;
		}

		cout << "Case #"<< counter << ": " << ans << endl;
		counter++;
	}
	return 0;
}