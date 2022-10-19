#include <stdio.h>
#define SIZE 5 

/*

출력결과 
    *
   **
  ***
 ****
*****

*/
int main(void){
	
	int i, j;
	
	for(i = 0; i < SIZE; i++){
		for(j = SIZE; j > i+1; j--){
			printf(" ");
		}
		for(j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n"); 
	}
	
	return 0;
}
