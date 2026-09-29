#include <stdio.h>

int main() {
    int Trow, Tcol;
    printf("Enter the number of rows: ");
    scanf("%d", &Trow);
    printf("Enter the number of columns: ");
    scanf("%d", &Tcol);

    int arr[Trow*Tcol+1][3];
    arr[0][0] = Trow;
    arr[0][1] = Tcol;
    arr[0][2] = 0;
    int k = 0;
    for(int i = 1; i < Trow; i++) {
        for(int j = 0; j < 3; j++) {
            int val;
            printf("Enter the value for [%d][%d]: ", i-1, j);
            scanf("%d", &val);
            if(val != 0){
                arr[i][0] = i-1;
                arr[i][1] = j;
                arr[i][2] = val;
                k++;
            }
        }
    }
    arr[0][2] = k;
    printf("Row\tCol\tValue\n");
    for(int i = 0; i <= arr[0][2]+1; i++) {
            printf("%d\t%d\t%d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
    return 0;
}
