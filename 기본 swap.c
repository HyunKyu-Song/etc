#include <stdio.h>

int main(){
	
	int a=10, b=20;
	int temp;
	
	printf("변경 전\n");
	printf("a = %d\n", a);
	printf("b = %d\n\n\n", b);
	
	temp = a;
	a = b;
	b = temp;
	
	printf("변경 후\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	
	return 0;
}
