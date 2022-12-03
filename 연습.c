#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist{
	int data;
	struct linkedlist * next;
}LinkedList;

void Init(LinkedList *head)
{
	head->next = NULL;
}

void Insert(LinkedList *head, LinkedList *tail, int val)
{
	LinkedList *newnode = (LinkedList*)malloc(sizeof(newnode));
	
	newnode->data = val;
	newnode->next = NULL;
	
	if(head->next == NULL)
		head->next = newnode;
	else
		tail->next->next = newnode;
		
	tail->next = newnode;
} 

void Delete(LinkedList *head, LinkedList *tail, int target)
{
	LinkedList *rem, *prev;
	
	rem = head->next;
	prev = NULL;
	
	while(rem->data != target){
		prev = rem;
		rem = rem->next;
	}
	
	if(prev == NULL){
		head->next = head->next->next;
	}
	else{
		prev->next = rem->next;
		
		if(rem->next == NULL){
			tail->next = prev;
		}
	} 
	
	free(rem);
} 

void Print(LinkedList *head)
{
	LinkedList *copy = (LinkedList*)malloc(sizeof(copy));
	
	copy->next = head->next;
	
	printf("\n[ 출력결과 ]\n"); 
	while(copy->next != NULL){
		printf("%d ", copy->next->data);
		copy->next = copy->next->next;
	}
	printf("\n\n");
}

int main(void){
	
	LinkedList head, tail;
	int n, x;
	
	Init(&head);
	
	while(1){
		printf("\n[1] Insert [2] Delete [3] Print [4] Exit\n\n");
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
				Delete(&head, &tail, x);
				Print(&head);
				break;
			case 3:
				Print(&head);
				break;
			case 4:
				printf("---------------------------\n\n");
				printf(" 프로그램이 종료되었습니다.\n\n");
				printf("---------------------------\n");
				exit(-1);
		}	
	}
	
	return 0;
}
