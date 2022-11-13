#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void){
	
	int x=10, y=20;
	
	printf("[swap Àü]\n");
	printf("x = %d	y = %d", x, y);
	
	swap(&x, &y);
	
	printf("\n\n[swap ÈÄ]\n");
	printf("x = %d	y = %d", x, y);
	
	return 0;
}
