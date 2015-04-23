#include <iostream>
using namespace std;

int main(){
	int TC;
	cin >> TC;

	while(TC--){
		long inp1, inp2;
		cin >> inp1 >> inp2;

		if (inp1 > inp2){
			cout << ">" << endl;
		}
		else if (inp2 > inp1){
			cout << "<" << endl;
		}
		else{
			cout << "=" << endl;
		}
	}
}