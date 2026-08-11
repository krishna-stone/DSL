#include <stdio.h>
#include <stdlib.h>
#include "4-Header.h"

// i. Search an element in the list
void searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list.\n", key);
}

// ii. Sort the list in ascending order (Bubble Sort)
void sortList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    
    struct Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

// iii. Reverse the list
void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List reversed successfully.\n");
}

int main() {
    struct Node* head = NULL;
    int n, val, pos, choice;

    printf("Enter initial number of nodes (n): ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &val);
        insertAtPosition(&head, val, i);
    }

    while (1) {
        printf("\n--- MENU (4.2) ---\n");
        printf("1. Insert node at position\n");
        printf("2. Delete node from position\n");
        printf("3. Count nodes\n");
        printf("4. Traverse list\n");
        printf("5. Search an element\n");
        printf("6. Sort list ascending\n");
        printf("7. Reverse list\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertAtPosition(&head, val, pos);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(&head, pos);
                break;
            case 3:
                printf("Total nodes: %d\n", countNodes(head));
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &val);
                searchElement(head, val);
                break;
            case 6:
                sortList(&head);
                traverseList(head);
                break;
            case 7:
                reverseList(&head);
                traverseList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
