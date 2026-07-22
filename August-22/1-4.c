#include <stdio.h>

struct complex {
    float real;
    float imag;
};

struct complex addition(struct complex c1, struct complex c2) {
	struct complex result;
	result.real = c1.real + c2.real;
	result.imag = c1.imag + c2.imag;
	return result;
}

void multiply(struct complex *c1, struct complex *c2, struct complex *result) {
	result->real = c1->real * c2->real;
	result->imag = c2->imag * c1->imag;
}


int main() {
	struct complex num1, num2, sum, product;

	int choice;

	while(1) {
		printf("\n--Menu--\n");
		printf("1. Addition of complex number\n");
		printf("2. Multiplication of complex number\n");
		printf("3. Exit\n");
		printf("Enter yout choice: ");
		scanf("%d", &choice);
		if (choice == 3) {break;}	

		switch(choice) {
			case 1 :
				printf("\nEnter first complex number: \n");
				printf("Real part: ");
				scanf("%f", &num1.real);
				printf("Imaginary part: ");
				scanf("%f", &num1.imag);
				
				printf("\nEnter second complex number: \n");
				printf("Real part: ");
				scanf("%f", &num2.real);
				printf("Imaginary part: ");
				scanf("%f", &num2.imag);

				sum = addition(num1, num2);
				printf("Sum of complex num : %.2f + %.2fi", sum.real, sum.imag );
				break;
			case 2 :
				printf("\nEnter first complex number: \n");
				printf("Real part: ");
				scanf("%f", &num1.real);
				printf("Imaginary part: ");
				scanf("%f", &num1.imag);
				
				printf("\nEnter second complex number: \n");
				printf("Real part: ");
				scanf("%f", &num2.real);
				printf("Imaginary part: ");
				scanf("%f", &num2.imag);

				
				multiply(&num1, &num2, &product);
				printf("Product of complex num : %.2f + %.2fi\n", product.real, product.imag );
				break;
			default : 
				printf("Error\n");
				break;
		}
	}
	
	
	return 0;
}
