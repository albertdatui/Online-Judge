#include <iostream>
#include <string>
using namespace std;

int main(){
	string inp;

	while (getline(cin, inp)){
		int saved[60] = {0};
		int max = 0;

		for (int i = 0;i < inp.length();i++){
			if ((int(inp[i]) - 65 >= 0) & (int(inp[i]) - 65 < 60)){
				saved[int(inp[i]) - 65]++;
				if (max < saved[int(inp[i]) - 65]){
					max = saved[int(inp[i]) - 65];
				}
			}
		}

		for (int i = 0;i < 60;i++){
			if (max == saved[i]){
				cout << char(i+65);
			}
		}

		cout << " " << max << endl;
	}
}