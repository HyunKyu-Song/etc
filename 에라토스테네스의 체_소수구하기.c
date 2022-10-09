#include <stdio.h>

int main(void){
	
	int arr[100];
	int i, j;
	
	for(i = 2; i <= 100; i++){
		arr[i] = 0;
	}
	
	for(i = 2; i <= 100; i++){
		if(arr[i] == 0){
			for(j = 2; j <= 100; j++){
				if(i*j <= 100) 
					arr[i*j]++;
			}
		}
	}
	
	for(i = 2; i <= 100; i++){
		if(arr[i] == 0){
			printf("%d\n", i);
		}
	}
	
	return 0;
}
