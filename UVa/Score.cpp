#include <stdio.h>
#include <string.h>

int main(){
	char inp[100];
	int TC,length;

	scanf("%d", &TC);

	for(int i=0;i<TC;i++){
		scanf("%s", inp);
		length = strlen(inp);
		int result = 0;
		int number = 0;
		int j = 0;

		while (j<length){
			if (inp[j] == 'X'){
				number = 0;
			}
			if (inp[j] == 'O'){
				number++;
			}

			result = result + number;
			j++;
		}

		printf("%d\n", result);
	}

	return 0;
}