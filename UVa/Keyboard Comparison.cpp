#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 1200
#define ROW 4
#define COLUMN 14

double distance(int, int, int, int);

int main(){
	char input[MAX];

	char keyboard_shift[ROW][COLUMN] = {{'~','!','@','#','$','%','^','&','*','(',')','_','+','\0'},
								  		{'\0','Q','W','E','R','T','Y','U','I','O','P','{','}','|'},
								  		{'\0','A','S','D','F','G','H','J','K','L',':','"','\0','\0'},
								  		{'\0','Z','X','C','V','B','N','M','<','>','?','\0','\0','\0'}};

	char keyboard[ROW][COLUMN] = {{'`','1','2','3','4','5','6','7','8','9','0','-','=','\0'},
								  {'\0','q','w','e','r','t','y','u','i','o','p','[',']','\\'},
								  {'\0','a','s','d','f','g','h','j','k','l',';','\'','\0','\0'},
								  {'\0','z','x','c','v','b','n','m',',','.','/','\0','\0','\0'}};

	char dvorak_keyboard[ROW][COLUMN] =  {{'`','1','2','3','q','j','l','m','f','p','/','[',']','\0'},
								  		  {'\0','4','5','6','.','o','r','s','u','y','b',';','=','\\'},
								  		  {'\0','7','8','9','a','e','h','t','d','c','k','-','\0','\0'},
								  		  {'\0','0','z','x',',','i','n','w','v','g','\'','\0','\0','\0'}};

	char dvorak_keyboard_shift[ROW][COLUMN] =  {{'~','!','@','#','Q','J','L','M','F','P','?','{','}','\0'},
								  		  		{'\0','$','%','^','>','O','R','S','U','Y','B',':','+','|'},
								  		  		{'\0','&','*','(','A','E','H','T','D','C','K','_','\0','\0'},
								  		  		{'\0',')','Z','X','<','I','N','W','V','G','"','\0','\0','\0'}};

	int two_hand[8][2] = {{2,1},{2,2},{2,3},{2,4},{2,7},{2,8},{2,9},{2,10}}; //a,s,d,f,j,k,l,;
	//printf("The two hand : %c %c %c %c %c %c %c\n", keyboard[two_hand[0][0]][two_hand[0][1]],keyboard[two_hand[1][0]][two_hand[1][1]],
												  //keyboard[two_hand[2][0]][two_hand[2][1]],
												  //keyboard[two_hand[3][0]][two_hand[3][1]],keyboard[two_hand[4][0]][two_hand[4][1]],
												  //keyboard[two_hand[5][0]][two_hand[5][1]],keyboard[two_hand[6][0]][two_hand[6][1]]);
	
	int one_hand[4][2] = {{2,4},{2,5},{2,6},{2,7}}; //f,g,h,j
	//printf("The one hand : %c %c %c %c\n", keyboard[one_hand[0][0]][one_hand[0][1]],keyboard[one_hand[1][0]][one_hand[1][1]],
												  //keyboard[one_hand[2][0]][one_hand[2][1]],
												  //keyboard[one_hand[3][0]][one_hand[3][1]]);
	int dvorak[4][2] = {{2,5},{2,6},{2,7},{2,8}}; //e,h,t,d
	//printf("The dvorak hand : %c %c %c %c\n", dvorak_keyboard[dvorak[0][0]][dvorak[0][1]],dvorak_keyboard[dvorak[1][0]][dvorak[1][1]],
												  //dvorak_keyboard[dvorak[2][0]][dvorak[2][1]],
												  //dvorak_keyboard[dvorak[3][0]][dvorak[3][1]]);

	while (gets(input)){
		int length = int(strlen(input));
		double two_min,one_min,dvorak_min,two_hand_result,one_hand_result,dvorak_result;

		two_hand_result = 0.0;
		one_hand_result = 0.0;
		dvorak_result = 0.0;

		for (int i=0;i<length;i++){
			two_min = 0.0;
			one_min = 0.0;
			dvorak_min = 0.0;

			for (int j=0;j<ROW;j++){
				for (int k=0;k<COLUMN;k++){
					if (input[i] == keyboard[j][k]){
						for (int l=0;l<8;l++){
							//printf("Two Hand : %d %d %d %d\n", two_hand[l][0], two_hand[l][1], j, k);
							if (l == 0){
								two_min = distance(two_hand[l][0], two_hand[l][1], j, k);
							}
							else{
								if (two_min > distance(two_hand[l][0], two_hand[l][1], j, k)){
									two_min = distance(two_hand[l][0], two_hand[l][1], j, k);
								}
							}
						}

						for (int l=0;l<4;l++){
							//printf("One Hand : %d %d %d %d\n", one_hand[l][0], one_hand[l][1], j, k);
							if (l == 0){
								one_min = distance(one_hand[l][0], one_hand[l][1], j, k);
							}
							else{
								if (one_min > distance(one_hand[l][0], one_hand[l][1], j, k)){
									one_min = distance(one_hand[l][0], one_hand[l][1], j, k);
								}
							}
						}
					}

					if (input[i] == keyboard_shift[j][k]){
						for (int l=0;l<8;l++){
							//printf("Two Hand : %d %d %d %d\n", two_hand[l][0], two_hand[l][1], j, k);
							if (l == 0){
								two_min = distance(two_hand[l][0], two_hand[l][1], j, k);
							}
							else{
								if (two_min > distance(two_hand[l][0], two_hand[l][1], j, k)){
									two_min = distance(two_hand[l][0], two_hand[l][1], j, k);
								}
							}
						}

						for (int l=0;l<4;l++){
							//printf("One Hand : %d %d %d %d\n", one_hand[l][0], one_hand[l][1], j, k);
							if (l == 0){
								one_min = distance(one_hand[l][0], one_hand[l][1], j, k);
							}
							else{
								if (one_min > distance(one_hand[l][0], one_hand[l][1], j, k)){
									one_min = distance(one_hand[l][0], one_hand[l][1], j, k);
								}
							}
						}
					}

					if (input[i] == dvorak_keyboard[j][k]){
						for (int l=0;l<4;l++){
							//printf("Dvorak : %d %d %d %d\n", dvorak[l][0],dvorak[l][1],j,k);
							if (l == 0){
								dvorak_min = distance(dvorak[l][0],dvorak[l][1],j,k);
							}
							else{
								if (dvorak_min > distance(dvorak[l][0],dvorak[l][1],j,k)){
									dvorak_min = distance(dvorak[l][0],dvorak[l][1],j,k);
								}
							}
						}
					}

					if (input[i] == dvorak_keyboard_shift[j][k]){
						for (int l=0;l<4;l++){
							//printf("Dvorak : %d %d %d %d\n", dvorak[l][0],dvorak[l][1],j,k);
							if (l == 0){
								dvorak_min = distance(dvorak[l][0],dvorak[l][1],j,k);
							}
							else{
								if (dvorak_min > distance(dvorak[l][0],dvorak[l][1],j,k)){
									dvorak_min = distance(dvorak[l][0],dvorak[l][1],j,k);
								}
							}
						}
					}
				}
			}

			//printf("%c distance is : %0.2f %0.2f %0.2f\n", input[i] ,two_min, one_min, dvorak_min);

			dvorak_result += 2.0*dvorak_min;
			two_hand_result += 2.0*two_min;
			one_hand_result += 2.0*one_min;
		}

		printf("%0.2lf %0.2lf %0.2lf\n", two_hand_result, one_hand_result, dvorak_result);
	}
	return 0;
}

double distance(int hand_r, int hand_c, int board_r, int board_c){
	return sqrt((hand_r-board_r)*(hand_r-board_r) + (hand_c-board_c)*(hand_c-board_c));
}