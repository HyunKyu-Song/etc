#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct std{
	int num;
	char name[10];
	float grade;
}STD;

int main(void){
	
	STD s;
	char str[10];
	
	printf("�й�: ");
	scanf("%d", &s.num);
	/*
	printf("�̸�: ");
	scanf("%s", &s.name);
	*/
	strcpy(s.name, "song");
	//s.name = "song";
	
	
	printf("����: ");
	scanf("%f", &s.grade);
	
	printf("\n\n�й�: %d\n�̸�: %s\n����: %.1f", s.num, s.name, s.grade);
	
	return 0;
}
