#include <stdio.h>

void swap(int x, int y)
{
	int temp;
	
	temp = x;
	x = y;
	y = temp;
	
	printf("swap 함수 내에서\n");
	printf("a = %d\n", x);
	printf("b = %d\n\n\n", y);
}

int main(){
	
	int a=10, b=20;
	
	printf("변경 전\n");
	printf("a = %d\n", a);
	printf("b = %d\n\n\n", b);
	
	swap(a, b);
	
	//함수 내에서는 변경가능, 함수 밖에서는 변경안됨 
	//이유: call by value 
	printf("변경 후\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	
	return 0;
}
