#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertNode(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    struct node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

int main() {
    struct node *head = NULL;
    printf("Enter no of elements: ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the value for node %d: ", i + 1);
        int val;
        scanf("%d", &val);
        insertNode(&head,val);
    }

	if (head == NULL) {
        printf("The list is empty.\n");
        return 0;
    }
	struct node* temp = head;
	do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
    return 0;
}
