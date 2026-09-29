#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue{
	int data;
	struct Queue* Next;
};

struct Queue* CreateNode(int val){
	struct Queue* NewNode = (struct Queue*)malloc(sizeof(struct Queue));
	NewNode->data = val;
	NewNode->Next = NULL;
	return NewNode;
}

void Enqueue(int val,struct Queue** front, struct Queue** rear){
	struct Queue* NewN = CreateNode(val);
	if(*front == NULL) {
		*front = NewN;
		*rear = NewN;
		return;
	}
	(*rear)->Next = NewN;
	(*rear) = NewN;
}

int Dequeue(struct Queue** front, struct Queue** rear){
    if(*front == NULL){
        printf("Queue underflow\n");
        return -1;
    }
    struct Queue* temp = *front;
    int val = temp->data;
    *front = temp->Next;
    if(*front == NULL) *rear = NULL;
    free(temp);
    return val;
}

bool isEmpty(struct Queue* rear){
	if(rear == NULL) return true;
	return false;
}

void Traverse(struct Queue* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    struct Queue* temp = front;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->Next != NULL) printf(" -> ");
        temp = temp->Next;
    }
    printf("\n");
}

int main(void) {
    struct Queue* front = NULL;
    struct Queue* rear  = NULL;
    int choice, val;
    
    printf("\n===== QUEUE MENU =====\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Is Empty?\n");
    printf("4. Traverse\n");
    printf("5. Exit\n");
	while(1) {
		printf("Enter your choice: ");
        scanf("%d", &choice);

	    switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            Enqueue(val, &front, &rear);
            printf("%d enqueued.\n", val);
            break;
        case 2:
            printf("Dequeued: %d\n", Dequeue(&front,&rear));
            break;
        case 3:
            isEmpty(rear) ? printf("Queue is EMPTY.\n") : printf("Queue is NOT empty.\n");
            break;
        
        case 4:
            Traverse(front);
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
return 0;
}
