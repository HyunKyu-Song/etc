#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef int element;
typedef struct list {
   struct list *link;
   int data  ;
}List;

void init(List* head) {
   head->link = NULL;
}


void insert(List* head, List* tail, element data) {
   List* newnode = (List*)(malloc(sizeof(newnode)));
   newnode->data = data;
   newnode->link = NULL;

   if (head->link == NULL) {
      head->link = newnode;
      tail->link = newnode;
   }
   else {
      tail->link->link = newnode;
      tail->link = newnode;
   }
}


   /*else {
      if (head->data > newnode->data) {
         newnode->link = head;
         newnode->link = tail;
         head = newnode;
      }
      for (tail = head; tail->link; tail = tail->link) {
         if (tail->data< newnode->data && tail->link->data > newnode->data) {
            newnode->link = tail->link;
            tail->link = newnode;
         }
      }
      tail->link = newnode;
   }*/

/*
void delect(List* head, List* tail, element data) {
   List* newnode;
   List* cur;
   List* pre;

   if (head->link == NULL) {
      printf("error");
   }

   else if(tail->data == data) {
      tail = cur->link;
      tail->link = NULL;
      free(cur);
   }

   for(; cur; cur=cur->link){
      if (cur->data == data) {
         pre->link = cur->link;
         cur->link = NULL;
         free(cur);
      }
      pre = cur;
   }
}
*/

/*
void print(List* head, element data) {
   List* ptr;
   for (ptr = head; ptr; ptr = ptr->link) {
      if (ptr->data == data);
   }

   for (ptr = head; ptr->link; ptr = ptr->link) {
      printf("%d->", ptr->data);
   }
   printf("NULL");
}
*/
void print(List *head)
{
	List *copy;
	
	copy = (List*)malloc(sizeof(copy));
	
	copy->link = head->link;
	
	printf("\n\n[ 출력결과 ]\n");
	while(copy->link != NULL){
		printf("%d ", copy->link->data);
		copy->link = copy->link->link;
	}
	printf("\n\n\n");
}

int main() {
   List head;
   element data = 0;
   List tail;
   int n;
   
   init(&head);

   while (1){
   		printf("\n1.넣 2.빼 3.출력\n");
		scanf_s("%d", &n);

      if (n == 1) {
         scanf_s("%d", &data);
         insert(&head, &tail, data);
      }

      else if(n == 2) {
         scanf_s("%d", &data);
         //delete(&head, &tail, data);
      }

      else if(n == 3) {
         print(&head);
      }

   }

   return 0; 
}


/*
1
#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist{
	int data;
	struct linkedlist * next;
}LinkedList;

void init(LinkedList *head, LinkedList *tail)
{
	head->next = NULL;
	tail->next = head;
}

void Insert(LinkedList *head, LinkedList *tail, int n)
{
	LinkedList *newnode;
	
	newnode = (LinkedList*)malloc(sizeof(newnode));
	newnode->data = n;
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

void Print(LinkedList *head)
{
	while(head->next != NULL){
		printf("%d ", head->next->data);
		head->next = head->next->next;
	}
}

int main(void){
	
	LinkedList head, tail;
	int n;
	
	init(&head, &tail);
	
	while(1){
		printf("저장할 데이터: ");
		scanf("%d", &n);
		
		if(n == -1){
			break;
		}
		
		Insert(&head, &tail, n);
	}
	Print(&head);
	
	return 0;
}
*/

/*
2
#include <stdio.h>
#define SIZE 8

void sort(int arr[], int n)
{
	int i, j, k, temp, max;
	
	for(i = 0; i < n-1; i++){
		max = i;
		for(j = i; j < n; j++){
			if(arr[max] < arr[j])
				max = j;
		}
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
		for(k = 0; k < n; k++){
			printf("%d ", arr[k]);
		}
		printf("\n");
	}
}

int main(void){
	
	int arr[SIZE] = {2, 8, 7, 4, 3, 1, 9, 5};
	int i;
	
	printf("[ 정렬 전]\n");
	for(i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	
	sort(arr, SIZE);
	
	printf("\n\n[ 정렬 후]\n");
	for(i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}
*/

/*
3
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct stack{
	char arr[SIZE];
	int top;
}Stack;

void Init(Stack *s)
{
	s->top = -1;
}

void Push(Stack *s, char data)
{
	s->arr[++(s->top)] = data;
}

void Pop(Stack *s)
{
	(s->top)--;
}

void Print(Stack *s)
{
	int i;
	
	printf("\n\n[ 출력결과 ]\n");
	for(i = 0; i <= s->top; i++){
		printf("%c ", s->arr[i]);
	}
	printf("\n\n");
}

int main(void){
	
	Stack s;
	int n;
	char data;
	
	Init(&s);
	
	while(1){
		printf("[1] Push [2] Pop [3] Exit\n\n");
		scanf("%d", &n);
		
		switch(n){
			case 1:
				printf("data: ");
				scanf(" %c", &data);
				Push(&s, data);
				Print(&s);
				break;
			case 2:
				Pop(&s);
				Print(&s);
				break;
			case 3:
				exit(-1);
		}
	}
	
	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct queue{
	char arr[SIZE];
	int front, rear;
}Queue;

void Init(Queue *q)
{
	q->front = -1;
	q->rear = -1;
}

void Push(Queue *q, char data)
{
	q->arr[++(q->rear)] = data;
}

void Pop(Queue *q)
{
	q->arr[++(q->front)];
}

void Print(Queue *q)
{
	int i;
	
	printf("\n\n[ 출력결과 ]\n");
	for(i = (q->front)+1; i <= q->rear; i++){
		printf("%c ", q->arr[i]);
	}
	printf("\n\n");
}

int main(void){
	
	Queue q;
	int n;
	char data;
	
	Init(&q);
	
	while(1){
		printf("[1] Push [2] Pop [3] Exit\n\n");
		scanf("%d", &n);
		
		switch(n){
			case 1:
				printf("data: ");
				scanf(" %c", &data);
				Push(&q, data);
				Print(&q);
				break;
			case 2:
				Pop(&q);
				Print(&q);
				break;
			case 3:
				exit(-1);
		}
	}
	
	return 0;
}
*/

/*
8
#include <stdio.h>
#define SIZE 15

int main(void){
	
	int i, k;
	int cnt=0;
	int arr[SIZE] = {0, };
	
	for(i = 0; i < SIZE; i++){
		printf("k의 값을 입력: ");
		scanf("%d", &k);
		
		arr[i] = k;
		
		if(k % 3 == 0){
			cnt++;
		}
	}
	
	printf("\n\n[ 전체원소 출력 ]\n");
	for(i = 0; i < SIZE; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\ncnt = %d", cnt);
	
	return 0;
}
*/
