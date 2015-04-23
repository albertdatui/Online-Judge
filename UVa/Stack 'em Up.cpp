#include <iostream>
#include <vector>
#include <string>

using namespace std;

string CARD[53] = {"",
	"2 of Clubs","3 of Clubs","4 of Clubs","5 of Clubs","6 of Clubs","7 of Clubs","8 of Clubs","9 of Clubs","10 of Clubs","Jack of Clubs","Queen of Clubs",
	"King of Clubs", "Ace of Clubs",
	"2 of Diamonds","3 of Diamonds","4 of Diamonds","5 of Diamonds","6 of Diamonds","7 of Diamonds","8 of Diamonds","9 of Diamonds","10 of Diamonds","Jack of Diamonds",
	"Queen of Diamonds", "King of Diamonds", "Ace of Diamonds",
	"2 of Hearts","3 of Hearts","4 of Hearts","5 of Hearts","6 of Hearts","7 of Hearts","8 of Hearts","9 of Hearts","10 of Hearts","Jack of Hearts","Queen of Hearts",
	"King of Hearts", "Ace of Hearts",
	"2 of Spades","3 of Spades","4 of Spades","5 of Spades","6 of Spades","7 of Spades","8 of Spades","9 of Spades","10 of Spades","Jack of Spades","Queen of Spades",
	"King of Spades", "Ace of Spades"
};

int main()
{
	int TC;
	cin >> TC;

	while(TC--)
	{
		vector<int> cards(52);
		vector<int> temp;
		for (int i = 0; i < 52; i++)
		{
			cards[i] = i + 1;
		}

		int N;
		cin >> N;

		vector<vector<int>> shuffle(N, vector<int>(52));
		int number = 0;

		while (number < N)
		{
			for (int i = 0; i < 52; i++)
			{
				int temp;
				cin >> temp;
				shuffle[number][i] = temp - 1;
			}
			number++;
		}
		string s;
		getline(cin,s);

		getline(cin, s);
		while (s != "")
		{
			temp = cards;

			for (int i = 0; i < 52; i++)
			{
				cards[i] = temp[shuffle[atoi(s.c_str()) - 1][i]];
			}
			getline(cin, s);
		}

		for (int i = 0; i < 52; i++)
		{
			cout << CARD[cards[i]] << endl;
		}
		if (TC != 0)
		{
			cout << endl;
		}
	}
}