#include <iostream>
#include <map>
#include <string>

using namespace std;

struct classcomp
{
	bool operator() (const string s1, const string s2) const{
		return s1 < s2;
	}
};

int main(){
	map <string, int, classcomp> beauty;
	map <string, int>::iterator it;
	int nline;
	cin >> nline;

	string inp;
	getline(cin, inp);
	while (nline--){
		getline(cin, inp);
		int found_first = inp.find_first_not_of(" ");
		int found_last = inp.find_first_of(" ",found_first + 1);
		inp.erase(inp.begin() + found_last, inp.end());
		inp.erase(inp.begin(), inp.begin()+found_first);

		it = beauty.find(inp);
		if (it != beauty.end()){
			it->second++;
		}
		else{
			beauty.insert(pair<string, int> (inp,1));
		}
	}

	for (map <string, int>::iterator it = beauty.begin(); it != beauty.end(); ++it){
		cout << it->first << " " << it->second << endl;
	}
}