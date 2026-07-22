#include <stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i < num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int create(int n) {
	int *arr;
	arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Memory allocation failed!");
		return 1;
	}

	for (int i=0; i<n; i++) {
		printf("Enter the element %d: ",i);
		scanf("%d", (arr + i));
	}
	int sum = 0;
	for (int i=0; i<n; i++) {
		if (isPrime(*(arr + i))) {
			sum += (*(arr + i));
		}
	}
	free(arr);
	return sum;
}

int main() {
	int n;
	printf("Enter the size of element: ");
	scanf("%d", &n);

	int result = create(n);
	printf("The sum of prime is : %d\n", result);
	return 0;
}
