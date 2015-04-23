#include <stdio.h>
#define G 9810
#include <math.h>

float get_time(float height);
float get_distance(float velocity, float t);

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC){
		float length, distance, height, velocity;

		scanf("%f %f %f %f", &length, &distance, &height, &velocity);
		float t;
		t = get_time(height);

		float actual_distance = get_distance(velocity, t);

		//printf("%f\n", actual_distance);

		if ((actual_distance>(distance+500.0)) && (actual_distance<(distance+length-500.0))){
			printf("POOL\n");
		}
		else if((actual_distance<(distance-500.0)) || (actual_distance>(distance+length+500.0))){
			printf("FLOOR\n");
		}
		else{
			printf("EDGE\n");
		}
		TC--;
	}
	return 0;
}

float get_time(float height){
	float t = float(sqrt(2*float(height)/G));
	//printf("%f\n", t);
	return t;
}

float get_distance(float velocity, float t){
	float dist = velocity*t;
	//printf("%f\n", dist);
	return dist;
}