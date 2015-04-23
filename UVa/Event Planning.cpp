#include <iostream>
#include <string>

using namespace std;

int main(){
	int N, B, H, W;

	while (cin >> N >> B >> H >> W){
		int total = 1000000;
		for (int h = 0; h < H ; h++){
			int cost;
			cin >> cost;
			for (int w = 0; w < W; w++){
				int week;
				cin >> week;
				if (week >= N & cost*N <= B){
					if (total > cost*N){
						total = cost*N;
					}
				}
			}
		}

		if (total == 1000000){
			cout << "stay home" << endl;
		}
		else{
			cout << total << endl;
		}
	}
}