#include <stdio.h>

int main(void){
	
	int a[5] = {10, 20, 30, 40, 50};
	int b[5] = {10, 20, 70, 40, 50};
	int i;
	
	for(i = 0; i < 5; i++){
		printf("a[%d]=%d	b[%d]=%d", i, a[i], i, b[i]);
		if(a[i] != b[i]){
			printf("	다릅니다.\n");
			break;
		}
		printf("	같습니다.\n");
	}
	
	return 0;
}
