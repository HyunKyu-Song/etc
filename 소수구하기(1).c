#include <stdio.h>

int main(void){
	
	int arr[100];
	int i, j;
	
	for(i = 1; i <= 100; i++){
		arr[i] = 0;
	}

	for(i = 2; i <= 100; i++){
		for(j = 1; j <= i; j++){
			if(i % j == 0){
				arr[i]++; 
			}
		}
	}
	
	for(i = 1; i <= 100; i++){
		if(arr[i] == 2){
			printf("%d\n", i);
		}
	}
	
	return 0;
}
