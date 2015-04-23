#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool isAllGreen(vector<int>& _traffic, int _time);

int main()
{
	int x,y,z, time;
	vector<int> traffic;
	while((cin >> x >> y >> z) && (x || y || z)) {
		traffic.clear();
		traffic.push_back(x); traffic.push_back(y);
		while (z != 0) {
			traffic.push_back(z);
			cin >> z;
		}

		bool sync = false;
		for (time = 1; time <= 18000 && !sync; time++) {
			if (isAllGreen(traffic, time)) sync = true;
		}
		time--;

		if (sync) {
			cout << setfill('0');
			cout << setw(2) << int(time/3600)%12 << ":" << setw(2) << int(time/60)%60 << ":" << setw(2) << int(time%60) << endl;
		}
		else {
			cout << "Signals fail to synchronise in 5 hours" << endl;
		}
	}

	return 0;
}

bool isAllGreen(vector<int>& _traffic, int _time) {
	int green = 0;
	bool orange = false;

	for (int i = 0; i < _traffic.size(); i++) {
		if ((_time % (_traffic[i]*2) < (_traffic[i] - 5))) green++;

		if (_time > _traffic[i]) orange = true;
	}

	if ((green == _traffic.size()) && orange) return true;
	return false;
}