#include <iostream>

using namespace std;

int main(){
	int TC;
	cin >> TC;

	while (TC--){
		int farmer;
		cin >> farmer;

		int ans = 0;
		while (farmer--){
			int area, num_anim, friendliness;

			cin >> area >> num_anim >> friendliness;
			ans += area*friendliness;
		}
		cout << ans << endl;
	}

	return 0;
}