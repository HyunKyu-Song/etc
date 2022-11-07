#include <stdio.h>

int main(void){
	
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {0};
	int i;
	
	printf("[ 복사 전 ]\n");
	printf("a배열 값\n");
	for(i = 0; i < 5; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
	
	printf("b배열 값\n");
	for(i = 0; i < 5; i++){
		printf("%d ", b[i]);
	}
	printf("\n\n\n");
	
	for(i = 0; i < 5; i++){
		b[i] = a[i];
	}
	
	printf("[ 복사 후 ]\n");
	printf("a배열 값\n");
	for(i = 0; i < 5; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
	
	printf("b배열 값\n");
	for(i = 0; i < 5; i++){
		printf("%d ", b[i]);
	}
	
	return 0;
}
