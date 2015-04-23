#include <iostream>
#include <vector>
using namespace std;

int main(){
	int num_probs, subs, num_team;

	cin >> num_probs >> num_team >> subs;
	vector < vector<int> > last_blood (num_probs, vector<int> (num_team + 1));
	//0->a, 1->b , ....

	for (int i=0; i<num_probs; i++){
		for (int j=0;j<num_team; j++){
			last_blood[i][j] = -1;
		}
	}

	while(subs){
		int t , team;
		string verdict;
		char probs;

		cin >> t >> team >> probs >> verdict;
		//cout << t << " " << team << " " << probs << " " << verdict << endl;

		if (verdict == "Yes"){
			probs = probs - 'A';
			if (last_blood[int(probs)][team-1] == -1){
				last_blood[int(probs)][team-1] = t;
				last_blood[int(probs)][num_team] = team-1;
			}
		}
		subs--;
	}

	for (int i=0; i<num_probs;i++){

		if (last_blood[i][last_blood[i][num_team]] == -1){
			cout << char('A' + i) << " - -" << endl;
		}
		else{
			cout << char('A' + i) << " " << last_blood[i][last_blood[i][num_team]] << " " << last_blood[i][num_team] + 1 << endl;
		}
	}

	return 0;
}