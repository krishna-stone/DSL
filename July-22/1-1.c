#include <stdio.h>

void compare(int* num1, int* num2) {
	if (*num1 > *num2) {
		printf("%d is greater than %d\n",*num1, *num2);
	} else if (*num1 < *num2){
		printf("%d is less than %d\n", *num1, *num2);
	} else {
		printf("Both are equal\n");
	}
}

int main() {
	int num1, num2;
	printf("Enter two numbers: ");
	scanf("%d %d",&num1, &num2);
	compare(&num1, &num2);
	return 0;
}
