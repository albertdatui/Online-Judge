#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(){
	int TC;
	cin >> TC;

	while (TC){
		vector < vector <int> > data_list;
		vector <int> blocked;
		// 0 -> S, 1-> X
		char type = 'M';
		int data, id;
		bool first = false;

		while (1){
			bool IGN = false;
			bool GRANT = false;
			bool DEN = false;
			bool exist = false;

			cin >> type;
			if (type == '#'){
				break;
			}

			cin >> id >> data;

			vector <int> input;
			if (type == 'S'){
				input.push_back(0);
			}
			else{
				input.push_back(1);
			}

			input.push_back(id);
			input.push_back(data);
			//cout << input[0] << input[1] << input[2] << endl;

			for (int i=0;i<blocked.size();i++){
				if (input[1] == blocked[i]){
					IGN = true;
				}
			}

			if (!IGN){
				for (int i = 0; i<data_list.size();i++){
					if (input[2] == data_list[i][2]){
						exist = true;
					}
				}				
			}

			if (!exist && !IGN){
				data_list.push_back(input);
				GRANT = true;
			}

			if (!GRANT && !IGN){
				for (int i=0;i<data_list.size();i++){
					//cout << "data contained" << data_list[i][1] << " "<< input[1] << endl;
					if ((data_list[i][1] != input[1]) && (data_list[i][0] == 1 || input[0] == 1) && (data_list[i][2] == input[2])){
						//cout << "there you go" << endl;
						DEN = true;
						blocked.push_back(input[1]);
					}
				}
			}

			if (!DEN && !GRANT & !IGN){
				data_list.push_back(input);
				GRANT = true;
			}

			if (GRANT){			
				cout << "GRANTED" << endl;
			}
			if (DEN){
				cout << "DENIED" << endl;
			}
			if (IGN){
				cout << "IGNORED" << endl;
			}
		}

		TC--;
	
		if (TC){
			cout << endl;
		}
	}
}