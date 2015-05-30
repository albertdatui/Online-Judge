#include <iostream>
#include <vector>
#include <cmath>
#include <map>

#define max(a,b,c) ((a > b)? ((a > c)? (a) : (c)) : ((b > c)? (b) : (c)))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, int> mii;

void st_build(vi& st, const vi& freq, int vertex, int L, int R);
void st_create(vi& st, const vi& freq);
int rmq(vi& st, const vi& freq, int vertex, int L, int R, int i, int j);
int rmq(vi& st, const vi& freq, int i, int j);
int st_rmq(vi& st, const vi& freq, const vii& bound, int i, int j);

int main()
{
	int N, query;

	vi freq, st;
	vii bound;
	mii arr;
	while (cin >> N && N)
	{
		freq.clear(); arr.clear(); bound.clear();
		cin >> query;

		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;

			pair<mii::iterator, bool> ret;
			ret = arr.insert(pair<int, int>(temp,1));
			if (ret.second == false)
				ret.first->second++;
		}

		for (mii::iterator it = arr.begin(); it != arr.end(); ++it)
		{
			int count = it->second, i = count;
			int start, end;
			while (i)
			{
				if (i == count) start = freq.size();
				freq.push_back(count);
				bound.push_back(pair<int, int>(start, start+count-1));
				i--;
			}
		}

		st_create(st, freq);

		while(query--)
		{
			int i , j;
			cin >> i >> j;
			i--; j--;
			cout << st_rmq(st, freq, bound, i, j) << endl;
		}
	}
}

void st_build(vi& st, const vi& freq, int vertex, int L, int R)
{
	if (L == R)
		st[vertex] = L;
	else
	{
		int indexLeft = 2 * vertex, indexRight = 2 * vertex + 1;
		st_build(st, freq, indexLeft , L          , (L+R)/2);
		st_build(st, freq, indexRight, (L+R)/2 + 1, R      );
		int left = st[indexLeft], right = st[indexRight];
		int leftVal = freq[left], rightVal = freq[right];
		st[vertex] = (leftVal <= rightVal)? right : left;
	}
}

void st_create(vi& st, const vi& freq)
{	
	int len = (int) (2*pow(2.0, floor((log((double)freq.size()) / log(2.0)) + 1)));
	st.assign(len, -1);
	st_build(st, freq, 1, 0, (int) freq.size() -1);
}

int rmq(vi& st, const vi& freq, int vertex, int L, int R, int i, int j)
{
	//cout << i << " " << j << "->" << L << " " << R << endl;

	if (i > j) return -1;
	if (i > R || j < L) return -1;
	if (L >= i && R <= j) 
		return st[vertex];

	int p1 = rmq(st, freq, 2*vertex    , L          , (L+R) / 2, i, j);
	int p2 = rmq(st, freq, 2*vertex + 1, (L+R)/2 + 1, R        , i, j);

	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	if (freq[p1] > freq[p2]) return p1;
	else return p2;
}

int rmq(vi& st, const vi& freq, int i, int j)
{
	return rmq(st, freq, 1, 0, (int)freq.size() - 1, i, j);
}

int st_rmq(vi& st, const vi& freq, const vii& bound, int i, int j)
{
	int first = -1, last = -1, range = -1;
	ii temp;

	if (i > bound[i].first)
	{
		temp.first = i;
		temp.second = ((bound[i].second > j)? j : bound[i].second);
		first = temp.second - temp.first + 1;
		i = temp.second + 1;
	}

	if (j < bound[j].second)
	{
		temp.first = ((bound[j].first < i)? i : bound[j].first);
		temp.second = j;
		last = temp.second - temp.first + 1;
		j = temp.first - 1;
	}

	range = rmq(st, freq, i, j);
	int ans = ((range == -1)? 0 : freq[range]);
	//cout << first << " " << last << " " << freq[range] << endl;
	return max(first, last, ans);
}