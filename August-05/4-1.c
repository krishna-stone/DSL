#include <stdio.h>
#include <stdlib.h>
#include "4-Header.h"

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
        printf("\n--- MENU (4.1) ---\n");
        printf("1. Insert node at specific position\n");
        printf("2. Delete node from specific position\n");
        printf("3. Count nodes\n");
        printf("4. Traverse list\n");
        printf("5. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
