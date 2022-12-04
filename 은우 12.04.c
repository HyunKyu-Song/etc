#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct list {
    struct list* link;
    int data;
}List;

void init(List* head) {
    head = NULL;
}

void insert(List* head, int id, element data) {
	int i;
    List* newnode = (List*)(malloc(sizeof(List)));
    newnode->data = data;
    newnode->link = NULL;
    List* next = head;

    if (head == NULL) {
        head = newnode;
        printf("\n\n첫 노드가 쓰레기값이 들어갔어\n\n");
    }

    else {
        for (i = 0; i < id; i++) {
            next=next->link;
        }
        newnode->link = next->link;
        next->link = newnode;
    }
}

void delet(List* head, element data) {
    List* remove = head;
    List* before = NULL;

    while (remove->data != data) {
        before = remove;
        remove = remove->link;
    }
    before->link = remove->link;
    free(remove);
}


void print(List* head) {
	List* newnode;
	
    for (newnode = head; newnode != NULL; newnode = newnode->link) {
        printf("%d->", newnode->data);
    }
}

int main() {
    List head;
    element data = 0;
    int id;
    int n;

    init(&head);

    while (1) {
        printf("\n1.넣 2.빼 3.출력 \n\n");
        scanf_s("%d", &n);

        if (n == 1) {
            printf("data: ");
            scanf_s("%d", &data);
            printf("id번째 삽입(0부터): ");
            scanf_s("%d", &id);
            insert(&head, id, data);
        }

        else if (n == 2) {
            printf("data: ");
            scanf_s("%d", &data);
            delet(&head, data);
        }

        else if (n == 3) {
            print(&head);
        }

    }

    return 0;
}
