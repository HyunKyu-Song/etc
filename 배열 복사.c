#include <stdio.h>

int main(void){
	
	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {0};
	int i;
	
	printf("[ ���� �� ]\n");
	printf("a�迭 ��\n");
	for(i = 0; i < 5; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
	
	printf("b�迭 ��\n");
	for(i = 0; i < 5; i++){
		printf("%d ", b[i]);
	}
	printf("\n\n\n");
	
	for(i = 0; i < 5; i++){
		b[i] = a[i];
	}
	
	printf("[ ���� �� ]\n");
	printf("a�迭 ��\n");
	for(i = 0; i < 5; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n");
	
	printf("b�迭 ��\n");
	for(i = 0; i < 5; i++){
		printf("%d ", b[i]);
	}
	
	return 0;
}
