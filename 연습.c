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
	
	printf("학번: ");
	scanf("%d", &s.num);
	/*
	printf("이름: ");
	scanf("%s", &s.name);
	*/
	strcpy(s.name, "song");
	//s.name = "song";
	
	
	printf("학점: ");
	scanf("%f", &s.grade);
	
	printf("\n\n학번: %d\n이름: %s\n학점: %.1f", s.num, s.name, s.grade);
	
	return 0;
}
