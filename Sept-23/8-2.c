#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int pri;
    
};

void Enqueue(){
    
}

void Dequeue(){
    
}

void Display(){
    
}

int main(){
    printf("=== MENU ===\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\n");
    int val,choice;
    while(1){
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter Value: ");
                scanf("%d",&val);
                printf("Enter Priority: ");
                scanf("%d",&Priority);
                Enqueue(val,Priority);
                break;
            case 2:
                printf("Dequeued : %d",Dequeue());
                break;
            case 3:
                Display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}