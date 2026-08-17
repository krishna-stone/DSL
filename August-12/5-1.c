#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;	
};

struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;    
	return newNode;
}

int countNodes(struct Node *head) {
	int count = 0;
	struct Node* temp = head;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

void insertNode(struct Node **head, int val, int position) {
	int total = countNodes(*head);
	if (position < 1 || position > total + 1) {
	    printf("Invalid position!\n");
	    return;
	}
	  
	struct Node* newNode = createNode(val);
	if (position == 1) {
		if (*head != NULL) {
			(*head)->prev = newNode;
		}
	    newNode->next = *head;
	    (*head) = newNode;
	    printf("Inserted %d at position %d.\n", val, position);
	    return;
	}
	    
	struct Node* temp = *head;
	for (int i = 1; i < position - 1; i++) {
	    temp = temp->next;
	}
	// 1. Point newNode to its correct neighbors
	newNode->next = temp->next;
	newNode->prev = temp;
	
	// 2. If not inserting at the very end, update the next node's prev pointer
	if (temp->next != NULL) {
	    temp->next->prev = newNode;
	}
	
	// 3. Update the previous node's next pointer
	temp->next = newNode;
	printf("Inserted %d at position %d.\n", val, position);
}
// Delete Node (Needs to be modified for double linked list.)
void deleteNode(struct Node **head,int pos) {
	int total = countNodes(*head);
	if (*head == NULL || pos < 1 || pos > total) {
	    printf("Invalid position or empty list!\n");
	    return;
	}
	   
	struct Node* temp = *head;
	
	if (pos == 1) {
	    *head = (*head)->next;
	    if (*head != NULL) {
	    	(*head)->prev = NULL;
	    }
	    printf("Deleted element %d from position 1.\n", temp->data);
	    free(temp);
	    return;
	}
	    
	for (int i = 1; i < pos - 1; i++) {
	    temp = temp->next;
	}
	
	struct Node* nodeToDelete = temp->next;
	temp->next = nodeToDelete->next;
	
	if (nodeToDelete->next != NULL)
	    nodeToDelete->next->prev = temp;
	    
	printf("Deleted element %d from position %d.\n", nodeToDelete->data, pos);
	free(nodeToDelete);
}

// Traverse List
void traverseList(struct Node *head) {
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

int main() {
    struct Node* head = NULL;
    int n, val, pos, choice;

    printf("Enter initial number of nodes (n): ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &val);
        insertNode(&head, val, i);
    }

    while (1) {
        printf("\n--- MENU (4.1) ---\n");
        printf("1. Insert node at specific position\n");
        printf("2. Delete node from specific position\n");
        printf("3. Traverse list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                insertNode(&head, val, pos);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteNode(&head, pos);
                break;
            case 3:
                traverseList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
