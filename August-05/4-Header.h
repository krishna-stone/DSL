#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Utility function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// iii. Count nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// iv. Traverse the linked list
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// i. Insert a node at a specific position (1-indexed)
void insertAtPosition(struct Node** head, int data, int position) {
    int total = countNodes(*head);
    if (position < 1 || position > total + 1) {
        printf("Invalid position!\n");
        return;
    }
    
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Inserted %d at position %d.\n", data, position);
        return;
    }
    
    struct Node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", data, position);
}

// ii. Deletion of an element from a specific position (1-indexed)
void deleteAtPosition(struct Node** head, int position) {
    int total = countNodes(*head);
    if (*head == NULL || position < 1 || position > total) {
        printf("Invalid position or empty list!\n");
        return;
    }
    
    struct Node* temp = *head;
    if (position == 1) {
        *head = (*head)->next;
        printf("Deleted element %d from position 1.\n", temp->data);
        free(temp);
        return;
    }
    
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted element %d from position %d.\n", nodeToDelete->data, position);
    free(nodeToDelete);
}

#endif
