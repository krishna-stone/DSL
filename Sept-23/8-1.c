#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50

int Deque[MAX];
int front = -1;
int rear = -1;

void Enqueue_rear(int val){
    if((front == 0 && rear == MAX-1)||(front == rear + 1)){
        printf("Overflow\n");
        return;
    }
    if(front == -1){
        front = rear = 0;
        Deque[rear] = val;
        return;
    }
    if(rear == MAX - 1){
        rear = 0;
        Deque[rear] = val;
        return;
    }
}

int Dequeue_front(){
    if(front == -1){
        printf("Underflow\n");
        return -1;
    }
    int item = Deque[front];
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

int peek(){
    printf("%d", Deque[front]);
}

bool isEmpty(){
    return (bool) (front == -1);
}

bool isFull(){
    return (bool) ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

int main(){
    printf("=== MENU ===\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. isFull\n6. Exit\n\n");
    int val,choice;
    while(1){
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d",&val);
                Enqueue_rear(val);
                break;
            case 2:
                printf("Dequeued : %d",Dequeue_front());
                break;
            case 3:
                peek();
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
