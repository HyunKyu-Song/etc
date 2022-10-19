#include <stdio.h>
#define SIZE 100 
//최대 공약수 구하 기

int main(void){
	
	int i, j = 0, reset = 0;
	int x, y, small, big;
	int arr[SIZE];
	
	scanf("%d %d", &x, &y);
	
	if(x >= y){
		big = x;
		small = y;
	}
	else{
		big = y;
		small = x;
	}
	
	for(i = 2; i <= small; i++){
		if(reset == 1){
			i = 2;
			reset = 0;
		}
		if(small % i == 0 && big % i == 0){
			small /= i;
			big /= i;
			arr[j] = i;
			printf("\n\nsmall %d\n", small);
			printf("big %d\n", big);
			printf("arr[%d] = %d\n\n", j, i);
			j++;
			reset = 1;
		}
	}
	
	for(i = 0; i < j; i++){
		printf("arr[%d] = %d\n", i, arr[i]);
	}
	
	return 0;
}
