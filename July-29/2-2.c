#include <stdio.h>
#include <stdlib.h>

int nonzero(int **arr, int *n) {
	int count=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n ;j++) {
			if (arr[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
}

void upperTriangle(int **arr, int *n) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++){
			if (i<j) {
				printf("%d ", arr[i][j]);
			} else {
				printf(" ");
			}
		}
	}
}

void diagonal(int **arr, int *n) {
	for (int i=0; i<n; i++) {
		printf("Elements above the diagonal: \n");
	}
	for (int j=0; j<n; j++) {
		printf("Elements below the diagonal: \n");		
	}
	
	}
}
