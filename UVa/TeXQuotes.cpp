#include <iostream>
#include <string>

using namespace std;

int main(){
	string inp;

	bool backstroke = true;
	while(getline(cin, inp)){
		int i = 0;

		while (i < inp.length()){
			if (inp[i] == '\"' & backstroke){
				inp.replace(i,1,"``");
				backstroke = false;
			}
			else if(inp[i] == '\"'){
				inp.replace(i,1,"\'\'");
				backstroke = true;
			}
			i++;
		}

		cout << inp << endl;
	}
}