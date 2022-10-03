#include <stdio.h>

int main(){
	
	int *p;
	int a = 100;
	
	p = &a;
	
		
	printf("a = %d\n", a);
	printf("&a = %d\n", &a);
	printf("p = %d\n", p);
	printf("*p = %d\n", *p);
	printf("&p = %d\n\n\n", &p);
	
	*p = 200;
	
	printf("a = %d\n", a);
	printf("&a = %d\n", &a);
	printf("p = %d\n", p);
	printf("*p = %d\n", *p);
	printf("&p = %d\n", &p);
	
	
	return 0;
}
