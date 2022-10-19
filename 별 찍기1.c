#include <stdio.h>
#define SIZE 5

/*

출력결과 
*****
*****
*****
*****
*****

*/
int main(void){
	
	int i, j;
	
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++){
			printf("*");
		}
		printf("\n"); 
	}
	
	
	return 0;
}
