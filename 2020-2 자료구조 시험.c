/*
1. 내림차순 정렬 
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
2. 배열 스택 
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
3. 배열 큐 
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
8. 배수 카운트 하기 
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
