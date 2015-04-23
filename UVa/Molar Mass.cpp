#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 256

int main(){
	int TC;
	scanf("%d", &TC);
	char inp[MAX];
	float mass[] = {12.01,1.008,16.00,14.01};

	while(TC){
		scanf("%s", inp);
		int length = int(strlen(inp));
		float result = 0;
		int prev = 0;
		for (int i=0;i<length;){
			float number = 0;
			if (inp[i] == 'C'){
				prev = 0;
			}
			else if (inp[i] == 'H'){
				prev = 1;
			}
			else if (inp[i] == 'O'){
				prev = 2;
			}
			else{
				prev = 3;
			}
			while(isdigit(inp[i+1])){
				number = number*10 + float((inp[i+1] - '0'));
				i++;
			}

			if (number == 0){
				result = result + mass[prev];
			}
			else{
				result = result + number*mass[prev];
			}
			i++;
		}

		printf("%0.3f\n", result);
		TC--;
	}

	return 0;
}