#include <stdio.h>

int main(void){
	
	int arr[5] = {123, 2, 3, 4, 5};
	int * p;
	
	p = arr;
	
	printf("%d\n", *p);
	printf("%d\n", *(p+3));
	
	return 0;
}
