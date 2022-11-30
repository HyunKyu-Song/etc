#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist{
	int data;
	struct linkedlist * next;
}LinkedList;

void init(LinkedList *head)
{
	head->next = NULL;
}

void Insert(LinkedList *head, LinkedList *tail, int value)
{
	LinkedList *newnode;
	
	newnode = (LinkedList*)malloc(sizeof(newnode));
	/*
	newnode = (LinkedList*)malloc(sizeof(newnode)*2); 
	//���� ũ�⺸�� Ŀ�� �޸� ������ Delete�ϱ� ���� *2 ����
	*/
	newnode->data = value;
	newnode->next = NULL;
	
	if(head->next == NULL){
		head->next = newnode;
		tail->next = newnode;
	}
	else{
		tail->next->next = newnode;
		tail->next = newnode;
	}
}

void Delete(LinkedList *head, LinkedList *tail, int value)
{
	LinkedList *p, *rem;
	
	rem = head->next;
	p = NULL;
	
	while(rem->data != value){
		p = rem;
		rem = rem->next;
	}
	
	if(p == NULL){
		head->next = head->next->next;
	}
	else{
		p->next = rem->next;
		tail->next = p;
	}
	
	free(rem);
}

void Print(LinkedList *head)
{
	LinkedList *copy;
	
	copy = (LinkedList*)malloc(sizeof(copy));
	
	copy->next = head->next;
	
	printf("\n����� ������: \n");
	while(copy->next != NULL){
		printf("%d ", copy->next->data);
		copy->next = copy->next->next;
	}
}

int main(void){
	
	LinkedList head, tail;
	int n, data;
	
	init(&head);
	
	while(1){
		printf("\n\n[1] Insert\n[2] Delete\n[3] Print\n[4] Exit\n\n");
		scanf("%d", &n);
		
		switch(n){
			case 1:
				printf("������ ������: ");
				scanf("%d", &data);
				Insert(&head, &tail, data);
				break;
			case 2:
				printf("���� �� ������: ");
				scanf("%d", &data);
				Delete(&head, &tail, data);
				break;
			case 3:
				Print(&head);
				break;
			case 4:
				printf("\n-----------------------------\n\n");
				printf(" ���α׷��� ����Ǿ����ϴ�.\n\n");
				printf("-----------------------------");
				exit(-1);
		}
	}
	
	return 0;
}
