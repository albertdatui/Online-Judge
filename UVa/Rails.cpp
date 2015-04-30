//#include <vector>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	int N;
//	while (cin >> N)
//	{
//		if (N == 0) break;
//		vector<int> train;
//		vector<int> stack;
//
//		while(1)
//		{	
//			int foo; stack.clear();	train.clear();
//			
//			cin >> foo;
//			if (foo == 0)
//			{
//				cout << endl;
//				break;
//			}
//			train.push_back(foo);
//			
//			for (int i = 1; i < N; i++)
//			{
//				cin >> foo;
//				train.push_back(foo);
//			}
//
//			int index = 0, order = 1;
//			while(index < N)
//			{
//				//cout << "index " << index << " -> " << "order " << order << endl;
//				if (stack.empty()) stack.push_back(order++);
//
//				if (stack.back() == train[index])
//				{
//					stack.pop_back();
//					index++;
//					continue;
//				}
//
//				if (order > N) break;
//				stack.push_back(order++);
//			}
//
//			if (index == N) cout << "Yes" << endl;
//			else cout << "No" << endl;
//		}
//	}
//}