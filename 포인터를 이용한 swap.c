#include <stdio.h>

void swap(int *px, int *py) //a, b�� �ּҸ� �Ű������� �޾� ������ ������ ��� 
{
	int temp;
	
	temp = *px;
	*px = *py;
	*py = temp;
}

int main(){
	
	int a=10, b=20;

	printf("���� ��\n");
	printf("a = %d\n", a);
	printf("b = %d\n\n\n", b);
	
	swap(&a, &b); //swap�Լ� ���ڿ� a, b �ּҸ� ���� 
	
	//�ּҸ� ���±� ������ �Լ� �ۿ����� ����� 
	//call by reference
	printf("���� ��\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	
	return 0;
}
