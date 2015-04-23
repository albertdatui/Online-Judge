#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(){
	int TC,lang1,lang2;
	cin >> TC;
	//cout << TC << endl;
	int count = 1;

	while (count <= TC){
		cin >> lang1 >> lang2;
		vector<string> vec1, vec2;
		set<string> LangSet;
		string str;

		getline(cin, str);
		//cin.clear();

		//cout << lang1 << " " << lang2 << endl;
		for (int i=0;i<lang1;i++){
			getline(cin, str);
			vec1.push_back(str);
		}

		for (int i=0;i<lang2;i++){
			getline(cin,str);
			vec2.push_back(str);
		}

		for (int i=0;i<lang1;i++){
			for (int j=0;j<lang2;j++){
				str = vec1[i] + vec2[j];
				LangSet.insert(str);
			}
		}

		cout << "Case "<< count << ": "<< LangSet.size() << endl;
		count++;
	}

	return 0;
}