#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 100

int Queue[N];
int front = -1;
int rear = -1;

void Enqueue(int val){
	if(front == -1){
		rear = front = 0;
		Queue[rear] = val;
		return;
	}
	if(rear == N-1){
		printf("Overflow\n");
		return;
	}
	Queue[++rear] = val;
}

int Dequeue(){
	if (front == -1) {
		printf("Underflow\n");
		return -1;
	}
	return Queue[front++];
}

bool isEmpty(){
	if(front == -1) return true;
	return false;
}
bool isFull(){
	if(rear == N-1) return true;
	return false;
}
void Traverse(){
	if(rear == -1){
		printf("Empty Queue.\n");
		return;
	}
	int temp = front;
	for(int i = temp; i<=rear;i++){
		printf(" %d ",Queue[i]);
	}
	printf("\n");
}

int main(){ 

	printf("==== MENU ====\n");
	printf("1. ENQUEUE\n2. DEQUEUE\n3. TRAVERSE\n4. IS EMPTY\n5. IS FULL\n6. EXIT\n");
	int choice;
	while(1){
	printf("Choice: ");
	scanf("%d", &choice);
		switch(choice) {
		    case 1:
	        	printf("Enter value: ");
	        	int val;
	    	    scanf("%d",&val);
	    	    Enqueue(val);
		        break;
		    case 2:
	        	int item = Dequeue();
	    	    printf("Item Deleted: %d\n", item);
		        break;
		    case 3:
	    	    Traverse();
		        break;
		    case 4:
	        	printf("Is Empty: ");
	    	    isEmpty() ? printf("True\n") : printf("False\n");
		        break;
		    case 5:
		    	printf("Is Full: ");
		    	isFull() ? printf("True\n") : printf("False\n");
		    	break;
		    case 6:
		    	printf("Exiting.....\n");
	    		exit(0);
	    		break;
		    }
	}
	return 0;
}
