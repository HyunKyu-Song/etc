#include <stdio.h>

void swap(int x, int y)
{
	int temp;
	
	temp = x;
	x = y;
	y = temp;
	
	printf("swap �Լ� ������\n");
	printf("a = %d\n", x);
	printf("b = %d\n\n\n", y);
}

int main(){
	
	int a=10, b=20;
	
	printf("���� ��\n");
	printf("a = %d\n", a);
	printf("b = %d\n\n\n", b);
	
	swap(a, b);
	
	//�Լ� �������� ���氡��, �Լ� �ۿ����� ����ȵ� 
	//����: call by value 
	printf("���� ��\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	
	return 0;
}
