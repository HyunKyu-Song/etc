#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node * next;
}NODE;

void Init(NODE *node, NODE *link)
{	
	node = (NODE*)malloc(sizeof(node));
	
	node = NULL;
	link = node;
}

void Insert(NODE *node, NODE *link, int data)
{
	NODE * newnode;
	
	newnode = (NODE*)malloc(sizeof(newnode));
	newnode->num = data;
	newnode->next = NULL;
	
	if(node == NULL){
		node->next = newnode;
		link = newnode;
	}
	else{
		link->next = newnode;
		link = newnode;
	}
}

void Print(NODE *node)
{
	int i;
	//NODE *copy;
	
	//copy = node;
	
//	for(i = 0; i < 3; i++){
//		printf("%d ", copy->num);
//		copy = copy->next;
//	}
//	node = node->next;
//	
//	for(i = 0; i < 3; i++){
//		printf("%d ", node->num);
//		node = node->next;
//	}
	node = node->next;
	printf("%d ", node->num);
}

int main(void){
	
	NODE * node;
	NODE * link;
	
	Init(node, link);	
	
	Insert(node, link, 10);
	Insert(node, link, 20);
	Insert(node, link, 30);
	
	Print(node);
	
	return 0;
}
