#include <iostream>
using namespace std;
int main(){
	int TC;
	cin >> TC;

	int i = 1;

	while (i <= TC){
		int max = 0;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++){
			int inp;
			cin >> inp;
			if (max < inp){
				max = inp;
			}
		}
		cout << "Case " << i << ": " << max << endl;
		i++;
	}
}