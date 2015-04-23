#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int TCx, TCy;
	double W;

	cin >> TCy >> TCx >> W;
	//cout << TCy << " " << TCx << " " << W << endl;
	while ((TCx != 0 & TCy != 0 & W != 0)){
		vector <double> Xpos;
		vector <double> Ypos;

		for (int i=0; i<TCy;i++){
			double input;
			cin >> input;
			Ypos.push_back(input);
		}

		for (int i=0; i<TCx;i++){
			double input;
			cin >> input;
			Xpos.push_back(input);
		}

		W = W/2.0;

		sort(Xpos.begin(), Xpos.end());
		sort(Ypos.begin(), Ypos.end());

		if ((Xpos[0] - W > 0) || (Ypos[0] - W > 0) || (Xpos[TCx-1] + W < 100.0) || (Ypos[TCy-1] + W < 75.0)){
			cout << "NO" << endl;
		} 
		else{
			bool completed = true;
			double r = 0.0;
			r = Xpos[0] + W;
			for (int i=1;i<TCx;i++){
				//cout << r << endl;
				if (Xpos[i] - W <= r){
					r = Xpos[i] + W;
				}
				else{
					completed = false;
				}
			}

			r = Ypos[0] + W;
			for (int i=1; i<TCy;i++){
				//cout << r << endl;
				if (Ypos[i] - W <= r){
					r = Ypos[i] + W;
				}
				else{
					completed = false;
				}
			}

			if (completed){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
		cin >> TCy >> TCx >> W;
	}
	return 0;
}