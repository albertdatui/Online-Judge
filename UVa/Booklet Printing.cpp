#include <iostream>
#include <string>

using namespace std;

int main()
{
	int pages;
	while (cin >> pages)
	{
		if (pages == 0) return 0;

		int sheet;
		sheet = (pages%4 == 0)? pages / 4 : pages/4 + 1;

		cout << "Printing order for " << pages << " pages:" << endl;
		int counter = 0;
		for (int i = 1; i <= sheet; i++)
		{
			cout << "Sheet " << i << ", front: ";
			if ((sheet*4 - counter > pages))
			{
				cout << "Blank" << ", " << counter + 1 << endl;;
			}
			else
			{
				cout << sheet*4 - counter << ", " << counter + 1 << endl;
			}
			counter++;
			
			if (counter >= pages) break;

			cout << "Sheet " << i << ", back: " << counter + 1 << ", ";
			if((sheet*4 - counter > pages))
			{
				cout << "Blank" << endl;
			}
			else
			{
				cout << (sheet*4 - counter) << endl;
			}
			
			counter++;
		}
	}
}