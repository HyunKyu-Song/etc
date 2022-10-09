#include <stdio.h>

int main(void){
	
	int arr[100];
	int i;
	
	for(i = 1; i <= 100; i++){
		arr[i] = 0;
	}
	
	for(i = 2; i <= 100; i++){
		if(i == 2 || i == 3 || i == 5 || i == 7){
			arr[i] = 0;
		}
		else if(i % 2 == 0){
			arr[i]++;
		}
		else if(i % 3 == 0){
			arr[i]++;
		}
		else if(i % 5 == 0){
			arr[i]++;
		}
		else if(i % 7 == 0){
			arr[i]++;
		}
	}
	
	
	printf("Ãâ·Â\n");
	printf("------------------------------\n");
	for(i = 2; i <= 100; i++){
		if(arr[i] == 0){
			printf("%d\n", i);
		}
	}
	
	return 0;
}
