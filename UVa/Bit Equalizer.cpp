#include <stdio.h>
#include <string.h>
#define MAX 256

int main(){
	int TC;
	scanf("%d", &TC);

	int count = 1;
	while(count <= TC){
		char S[MAX],T[MAX];
		scanf("%s", S);
		scanf("%s", T);
		int length = strlen(S);

		int item_S[3] = {0},item_T[3] = {0};
		int diff[2] = {0,0};

		//finding the occurrence of both strings
		for (int i=0;i<length;i++){
			if (S[i] == '0'){
				item_S[0]++;
			}
			else if(S[i] == '1'){
				item_S[1]++;
			}
			else{
				item_S[2]++;
			}

			if (T[i] == '0'){
				item_T[0]++;
			}
			else {
				item_T[1]++;
			}
		}

		
		//for (int i=0;i<3;i++){
		//	printf("The occurrence of %d: %d %d\n", i, item_S[i], item_T[i]);
		//}

		diff[0] = item_T[0] - item_S[0];
		diff[1] = item_T[1] - item_S[1];

		//printf("The difference : %d %d\n", diff[0], diff[1]);
		int result = 0;
		bool found;
		if (item_S[0] + item_S[2] < item_T[0]){
			found = false;
		}
		else{
			for (int i = 0;i<length;i++){
				if (S[i] == '?'){
					if (diff[int((T[i] - '0'))] > 0){
						S[i] = T[i];
						result++;
						diff[int((T[i]-'0'))]--;						
					}
					else if(T[i] == '0'){
						S[i] = '1';
						result++;
						diff[1]--;
					}
					else{
						S[i] = '0';
						result++;
						diff[0]--;
					}
				}
			}
			found = true;
		}

		//printf("The difference : %d %d\n", diff[0], diff[1]);

		diff[0] = 0;
		diff[1] = 0;
		for (int i=0;i<length;i++){
			if (S[i] != T[i]){
				if (S[i] == '1'){
					diff[1]++;
				}
				else{
					diff[0]++;
				}
			}
		}

		//printf("Another difference, %d\n", difference);

		if (found){
			printf("Case %d: %d\n", count, result + diff[0]);
		}
		else{
			printf("Case %d: -1\n", count);
		}
		//printf("%s\n", S);
		//printf("%s\n", T);
		count++;
	}
	return 0;
}