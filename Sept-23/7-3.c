#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 50

int Queue[MAX];
int front = -1;
int rear = -1;

void Enqueue(int val){
    if((front == 0 && rear == MAX-1)||(front == rear + 1)){
        printf("Overflow\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
        Queue[rear] = val;
        return;
    }
    if(rear == MAX - 1){
        rear = 0;
        Queue[rear] = val;
        return;
    }
    Queue[++rear] = val;
}

int Dequeue(){
    if(front == -1){
        printf("Underflow\n");
        return -1;
    }
    int item = Queue[front];
    if(front == rear) {
        front = rear = -1;
    }
    if(front == MAX - 1){
        front = 0;
    }
    else {
        front++;
    }
    return item;
}

void Traverse(){
    if(rear == -1){
        printf("Empty Queue\n");
        return;
    }
    if(rear>=front){
        for(int i = front;i=<rear;i++){
            printf(" %d ",Queue[i]);
        }
    }
    if(front>rear){
        for(int i = front; i<MAX;i++){
            printf(" %d ",Queue[i]);
        }
        for(int i = 0; i=<rear;i++){
            printf(" %d ",Queue[i]);
        }
    }
    printf("\n");
}

bool isEmpty(){
    return (bool) (front == -1);
}

bool isFull(){
    return (bool) ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int main(){
    printf("=== MENU ===\n");
    printf("1. Enqueue\n2. Dequeue\n3. Traverse\n4. isEmpty\n5. isFull\n6. Exit\n\n");
    int val,choice;
    while(1){
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d",&val);
                Enqueue(val);
                break;
            case 2:
                printf("Dequeued : %d",Dequeue());
                break;
            case 3:
                Traverse();
                break;
            case 4:
                isEmpty() ? printf("Empty\n") : printf("Not Empty\n");
                break;
            case 5:
                isFull() ? printf("Full\n") : printf("Not Full\n");
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
