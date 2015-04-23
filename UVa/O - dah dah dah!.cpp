#include <iostream>
#include <string>
#include <map>
#include <cstring>

using namespace std;

int main(){
	map <string, string> morse;
	morse[".-"] = "A";	morse[".---"] = "J";	morse["..."] = "S";		morse[".----"] = "1";	morse[".-.-.-"]  =	".";	morse["---..."] =	":";
	morse["-..."] = "B";morse["-.-"] = "K";		morse["-"] = "T";		morse["..---"] = "2";	morse["--..--"]  =	",";	morse["-.-.-."] =	";";
	morse["-.-."] = "C";morse[".-.."] = "L";	morse["..-"] = "U";		morse["...--"] = "3";	morse["..--.."]  =	"?";	morse["-...-"] =	"=";
	morse["-.."] = "D";	morse["--"] = "M";		morse["...-"] = "V";	morse["....-"] = "4";	morse[".----."] =	"\'";	morse[".-.-."] =	"+";
	morse["."] = "E";	morse["-."] = "N";		morse[".--"] = "W";		morse["....."] = "5";	morse["-.-.--"]  =	"!";	morse["-....-"] =	"-";
	morse["..-."] = "F";morse["---"] = "O";		morse["-..-"] =  "X";	morse["-...."] = "6";	morse["-..-."]  =	"/";	morse["..--.-"] =	"_";
	morse["--."] = "G";morse[".--."] = "P";		morse["-.--"] = "Y";	morse["--..."] = "7";	morse["-.--."]  =	"(";	morse[".-..-."]=	"\"";
	morse["...."] = "H";morse["--.-"] = "Q";	morse["--.."] = "Z";	morse["---.."] = "8";	morse["-.--.-"]  =	")";	morse[".--.-."] =	"@";
	morse[".."] = "I";	morse[".-."] = "R";		morse["-----"] = "0";	morse["----."] = "9";	morse[".-..."]  =	"&";

	int TC;
	int i = 1;
	string inp;
	cin >> TC;
	getline(cin, inp);

	while (i <= TC){
		getline(cin, inp);
		cout << "Message #" << i << endl;
		string info = "";
		for (int j = 0; j < inp.length(); j++){
			if (inp[j] == ' '){
				if (inp[j+1] == ' '){
					cout << morse[info];
					j = j + 1;
					info = "";
					cout << " ";
				}
				else{
					cout << morse[info];
					info = "";
				}
			}
			else{
				info += inp[j];
			}
		}
		cout << morse[info] << endl;
		if (i != TC){
			cout << endl;
		}
		i++;
	}
}