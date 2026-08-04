#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int*size, int element, int position){
	if (position < 0 || position > *size){
		printf("!!Invalid Position!!\n");
		return;
	}
	int *newArr = realloc(*arr, (*size + 1) * sizeof(int)); 
	if (!newArr) {
	        printf("Memory allocation failed!\n");
	        return;
	    }
	*arr = newArr;
	for (int i = *size; i > position; i--) {
	    (*arr)[i] = (*arr)[i - 1];
	}
	(*arr)[position] = element;
	(*size)++;
}

void delete(int **arr, int *size, int position) {
    if (*size <= 0) {
        printf("Array is empty! Cannot delete elements.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    int *newArr = realloc(*arr, (*size - 1) * sizeof(int));
    if (newArr==NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    *arr = newArr;
    (*size)--;
}

int linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

void traverseArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {

	int *arr;
	int n;
	int choice;

	printf("Enter the size of array: ");
	scanf("%d", &n);

	arr = (int *)malloc(n * sizeof(int));
	if(arr==NULL){
		printf("Memory Allocation Failed!\n");
		return 0;
	}
	printf("\nEnter Elements of Array:\n");
	for (int i=0; i<n; i++){
		scanf("%d",(arr+i));
	}

	printf("--MENU--\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Linear Search\n");
	printf("4. Traverse\n");
	printf("5. Exit\n");

	while(1){
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				int pos_ins;
				int element;
				printf("Enter element to insert: ");
				scanf("%d",&element);
				printf("Enter position: ");
				scanf("%d",&pos_ins);
				insert(&arr, &n, element, pos_ins);
				printf("Element Entered\n");
				break;
			case 2:
				int pos_del;
				printf("Enter position to delete: ");
				scanf("%d",&pos_del);
				delete(&arr, &n, pos_del);
				printf("Element Deleted\n");
				break;
			case 3:
				int element_sch;
				printf("Enter element to search: ");
				scanf("%d",&element);
				linearSearch(arr, n, element_sch );
				break;
			case 4:
				traverseArray(arr, n);
				printf("\n");
				break;
			case 5:
				return 1;
				break;
			default :
				printf("Error\n");
				break;
		}
	}
	free(arr);
	return 0;
}
