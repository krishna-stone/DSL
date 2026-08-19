#include <stdio.h>
#include <stdlib.h>

struct Node {
	int row;
	int col;
	int data;
	struct Node* next; 
};

struct Node *createNode(int row, int col, int val) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		if(!newNode) return NULL;
	newNode->row = row;
	newNode->col = col;
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

void insertNode(struct Node **head, int row, int col, int val) {
	struct Node *newNode = createNode(row, col, val);
	if(*head == NULL) {
		*head = newNode;
		return;
	}
    struct Node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    (*head)->data++;
}

void printMatrix(struct Node *head) {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->row);
        printf("%d ", temp->col);
        printf("%d ", temp->data);
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    int Trow, Tcol;
    printf("Enter the number of rows: ");
    scanf("%d", &Trow);
    printf("Enter the number of columns: ");
    scanf("%d", &Tcol);
    struct Node *head = NULL;
    insertNode(&head, Trow, Tcol, 0);
    for(int i = 0; i < Trow; i++) {
        for(int j = 0; j < Tcol; j++) {
            int val;
            printf("Enter the value at row %d and column %d: ", i+1, j+1);
            scanf("%d", &val);
            if(val != 0) {
                insertNode(&head, i, j, val);
            }
        }
    }
    printMatrix(head);
    return 0;
}
