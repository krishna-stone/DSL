#include <stdio.h>

int countNonZero(int n, int arr[n][n]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

void Upper(int n, int arr[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                printf("%d ", arr[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void Diagonals(int n, int a[n][n]) {
    printf("Elements just ABOVE the main diagonal: ");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", a[i][i + 1]);
    }
    printf("\n");

    printf("Elements just BELOW the main diagonal: ");
    for (int i = 1; i < n; i++) {
        printf("%d ", a[i][i - 1]);
    }
    printf("\n");
}

int main(void) {
    int n;

    printf("Enter the size of the square matrix (N x N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    int a[n][n];

    printf("Enter the elements of the %dx%d matrix row-wise:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
	printf("\n--- MATRIX OPERATIONS MENU ---\n");
    printf("1. Count Non-Zero Elements\n");
    printf("2. Display Upper Triangular Matrix\n");
    printf("3. Display Elements Above and Below Main Diagonal\n");
    printf("4. Exit\n");
    int choice;
    do {
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        printf("\n");
        switch (choice) {
            case 1:
                printf("Number of non-zero elements = %d\n", countNonZero(n, a));
                break;
            case 2:
                printf("Upper Triangular Matrix:\n");
                Upper(n, a);
                break;
            case 3:
                Diagonals(n, a);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
