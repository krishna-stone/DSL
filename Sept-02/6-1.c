#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

int stack[MAX];
int top = -1;
void push(int val){
	if(top == MAX-1){
		return;
	}
	stack[++top] = val;
}

int pop() {
	if(top == -1){
		printf("UNDERFLOW\n");
		return 0;
	}
	return stack[top--];
}

bool isEmpty() {
	return (bool)(top == -1);
}
bool isFull() {
	return (bool)(top == MAX-1);
}
void display() {
	printf("Stack: ");
	for(int i=top;i>-1;i--){
		printf("%d  ",stack[i]);
	}
	printf("\n");
}

int main(){
		printf("====MENU====\n");
		printf("1. PUSH\n2. POP\n3. IS EMPTY\n4. IS FULL\n5. DISPLAY\n6. EXIT\n");
	while(1){
		int choice;
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				int num;
				printf("Enter the element to push: ");
				scanf("%d",&num);
				push(num);
				printf("\n");
				break;
			case 2:
				printf("Item: %d\n",pop());
				break;
			case 3:
				printf("Empty Stack: ");
				isEmpty() ? printf("True\n") : printf("False\n");
				break;
			case 4:
				printf("Full Stack: ");
				isFull() ? printf("True\n") : printf("False\n");
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
		}
	}
	return 0;
}
