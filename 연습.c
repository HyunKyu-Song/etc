#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void word(void){
	printf("------------------------------------------------\n");
	printf("│                                             │\n");
	printf("│  오징어   생수    책상     키보드     전공  │\n");
	printf("│                                             │\n");
	printf("------------------------------------------------\n");
	printf("│                                             │\n");
	printf("│  책상     침대    돋보기   나침반     바퀴  │\n");
	printf("│                                             │\n");
	printf("------------------------------------------------\n");
	printf("│                                             │\n");
	printf("│  이불     샤워    수업     케이크     치킨  │\n");
	printf("│                                             │\n");
	printf("------------------------------------------------\n\n");
} 

int main(void){
	
	clock_t start, end;
	int result, i, j, random;
	
	random = rand()%5000 + 1000;
	
	for(i = 3; i > 0; i--){
		printf("【 기억력 테스트】\n");
		Sleep(1000);
		printf("%d\n", i);
		Sleep(300);
		system("cls");
	}
	printf("start\n\n");
	
	for(i = 10; i > 0; i--){
		word();
		printf("\n\n〔 %d 〕\n", i);
		Sleep(1000);
		system("cls");
	}
	printf("\n\nend");
	Sleep(1000);
	system("cls");
	printf("단어를 입력하시오: ");
	
	
	return 0;
}
