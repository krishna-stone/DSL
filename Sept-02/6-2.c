#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
	int data;
	struct Node* Next;
};

struct Node* CreateNode(int val){
	struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
	NewNode->data = val;
	NewNode->Next = NULL;
	return NewNode;
}

void Push(int val,struct Node** top){
	struct Node* NewN = CreateNode(val);
	if(*top == NULL) {
		*top = NewN;
		return;
	}
	NewN->Next = *top;
	*top = NewN;
}

bool isEmpty(struct Node* top){
	return (bool)(top == NULL) ;
}

int pop(struct Node** top){
	if(*top == NULL){
		printf("Underflow\n");
		return -1;
	}
    struct Node* temp = *top;
    int item = temp->data;
    *top = temp->Next;
    free(temp);
    return item;
}

void traverse(struct Node* top){
	if(top == NULL){
		printf("Stack is Empty.\n");
		return;
	}
	struct Node* temp = top;
	while(temp != NULL){
		printf("%d -> ",temp->data);
		temp = temp->Next;
	}
	printf("NULL\n");
}

int main(){
	struct Node* top = NULL;
	printf("==== MENU ====\n");
	printf("1. PUSH\n2. POP\n3. TRAVERSE\n4. IS EMPTY\n5. EXIT\n");
	int choice;
	while(1){
		printf("Choice: ");
		scanf("%d", &choice);
		switch(choice) {
		    case 1:
	        	printf("Enter value: ");
	        	int val;
	    	    scanf("%d",&val);
	    	    Push(val, &top);
		        break;
		    case 2:
	    	    printf("Item Deleted: %d\n", pop(&top));
		        break;
		    case 3:
	    	    traverse(top);
		        break;
		    case 4:
	        	printf("Is Empty: ");
	    	    isEmpty(top) ? printf("True\n") : printf("False\n");
		        break;
		    case 5:
	    		exit(0);
	    		break;
		}
	}
	return 0;
}
