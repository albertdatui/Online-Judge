#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Comparator
{
	int mods;
	public:
  		const bool operator() (int a, int b) const 
  		{
    		if (a%mods != b%mods) return a%mods < b%mods;
    		else if (abs(a%2) != abs(b%2)) return abs(a%2) > abs(b%2);
    		else if (a%2 == 0 && b%2 == 0) return a < b;
    		else return a > b;
  		}

  	Comparator(int _mods) : mods(_mods) 
  	{}
};

int main()
{
	int N,M;

	while(cin >> N >> M)
	{
		Comparator comp(M);
		if ((N == 0) && (M == 0)) break;
		vector<int> sum;

		int i = 0;
		while (i++ < N)
		{
			int temp; cin >> temp;
			sum.push_back(temp);
		}
		sort(sum.begin(), sum.end(), comp);

		cout << N << " " << M << endl;
		for (int i = 0; i < sum.size(); i++)
		{
			cout << sum[i] << endl;
		}
	}
	cout << N << " " << M << endl;
}