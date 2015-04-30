#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	while(true)
	{
		int n;
		scanf("%d", &n);
		vector<int> ages(101, 0);
		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			int foo;
			scanf("%d", &foo);
			ages[foo]++;
		}

		int current = 0;
		for (int i = 0; i < 101; i++)
		{
			ages[i] += current;
			current = ages[i];
		}

		current = 0;
		for (int i = 0; i < 101; i++)
		{
			while(current != ages[i])
			{
				printf("%d", i);
				if (current == (n-1))
					printf("\n");
				else
					printf(" ");
				current++;
			}
		}
	}
}