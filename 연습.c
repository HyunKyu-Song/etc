#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void word(void){
	printf("------------------------------------------------\n");
	printf("��                                             ��\n");
	printf("��  ��¡��   ����    å��     Ű����     ����  ��\n");
	printf("��                                             ��\n");
	printf("------------------------------------------------\n");
	printf("��                                             ��\n");
	printf("��  å��     ħ��    ������   ��ħ��     ����  ��\n");
	printf("��                                             ��\n");
	printf("------------------------------------------------\n");
	printf("��                                             ��\n");
	printf("��  �̺�     ����    ����     ����ũ     ġŲ  ��\n");
	printf("��                                             ��\n");
	printf("------------------------------------------------\n\n");
} 

int main(void){
	
	clock_t start, end;
	int result, i, j, random;
	
	random = rand()%5000 + 1000;
	
	for(i = 3; i > 0; i--){
		printf("�� ���� �׽�Ʈ��\n");
		Sleep(1000);
		printf("%d\n", i);
		Sleep(300);
		system("cls");
	}
	printf("start\n\n");
	
	for(i = 10; i > 0; i--){
		word();
		printf("\n\n�� %d ��\n", i);
		Sleep(1000);
		system("cls");
	}
	printf("\n\nend");
	Sleep(1000);
	system("cls");
	printf("�ܾ �Է��Ͻÿ�: ");
	
	
	return 0;
}
