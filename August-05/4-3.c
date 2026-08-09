#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node *next;
};


void insertTerm(struct Node **head, int coeff, int power) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

struct Node* readPolynomial() {
    struct Node *head = NULL;
    int maxPower, coeff;

    printf("Enter the Maximum power of x: ");
    scanf("%d", &maxPower);

    for (int p = maxPower; p >= 0; p--) {
        printf("Enter the coefficient of degree %d: ", p);
        scanf("%d", &coeff);
        insertTerm(&head, coeff, p);
    }

    return head;
}

struct Node* addPolynomials(struct Node *poly1,struct Node *poly2) {
    struct Node *result = NULL;
    struct Node *p1 = poly1, *p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->power == p2->power) {
            insertTerm(&result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->power > p2->power) {
            insertTerm(&result, p1->coeff, p1->power);
            p1 = p1->next;
        } else {
            insertTerm(&result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

void printPolynomial(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->power);
        if (temp->next != NULL)
            printf("+");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    printf("Polynomial-1:\n");
    poly1 = readPolynomial();
    printf("\nPolynomial-2:\n");
    poly2 = readPolynomial();
    sum = addPolynomials(poly1, poly2);
    printf("\nSum: ");
    printPolynomial(sum);
    return 0;
}
