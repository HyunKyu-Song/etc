#include <stdio.h>

void swap(int *px, int *py) //a, b의 주소를 매개변수로 받아 포인터 변수를 사용 
{
	int temp;
	
	temp = *px;
	*px = *py;
	*py = temp;
}

int main(){
	
	int a=10, b=20;

	printf("변경 전\n");
	printf("a = %d\n", a);
	printf("b = %d\n\n\n", b);
	
	swap(&a, &b); //swap함수 인자에 a, b 주소를 넣음 
	
	//주소를 보냈기 때문에 함수 밖에서도 변경됨 
	//call by reference
	printf("변경 후\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	
	return 0;
}
