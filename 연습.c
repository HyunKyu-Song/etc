#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist{
	int data;
	struct linkedlist * next;
}LinkedList;

void Init(LinkedList *head){
	head->next = NULL;
}

void Print(LinkedList *head){
	LinkedList *copy = (LinkedList*)malloc(sizeof(copy));
	
	copy->next = head->next;
	
	while(copy->next != NULL){
		printf("%d ", copy->next->data);
		copy->next = copy->next->next;
	}
}

int main(void){
	
	LinkedList head, tail;
	int n, x;
	
	Init(&head);
	
	while(1){
		printf("\n[1] Insert [2] Delete [3] Exit\n\n");
		printf("입력: ");
		scanf("%d", &n);
		
		switch(n){
			case 1:
				printf("\n데이터 입력: ");
				scanf("%d", &x);
				Insert(&head, &tail, x);
				Print(&head);
				break;
			case 2:
				printf("\n삭제할 데이터 입력: ");
				scanf("%d", &x);
				Insert(&head, &tail, x);
				Print(&head);
				break;
			case 3:
				printf("---------------------------\n\n");
				printf(" 프로그램이 종료되었습니다.\n\n");
				printf("---------------------------\n");
				exit(-1);
		}	
	}
	
	return 0;
}
