#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
}*top;

struct Node* createNode(int val){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

void push(struct Node** top,int val){
	struct Node* newN = createNode(val);
	if(*top == NULL){
		*top = newN;
		return;
	}
	struct Node* temp = *top;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newN;
}

int pop(struct Node** top){
	if(*top == NULL){
		printf("Empty Stack\n");
		return -1;
	}
	struct Node* temp = *top;
	while(temp->next != NULL){
		temp = temp->next;
	}
	free(temp);
}

void traverse(struct Node* top){
	if(top == NULL){
		printf("Empty Stack\n");
		return;
	}
	struct Node* temp = top;
	traverse(temp->next);
	printf("%d->",temp->data);
}

int main(){
	printf("===MENU===\n");
	printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
	int val,choice;
	while(1){
		printf("Choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter value: ");
				scanf("%d",&val);
				push(&top,val);
				break;
			case 2:
				printf("Poped: %d\n",pop(&top));
				break;
			case 3:
				traverse(top);
				printf("\n");
				break;
			case 4:
				exit(0);
		}
	}
	return 0;
}
