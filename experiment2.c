#include <stdio.h>

int main() {
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rowMajor[9], columnMajor[9], k = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            rowMajor[k++] = arr[i][j];

    k = 0;
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < 3; i++)
            columnMajor[k++] = arr[i][j];

    printf("Row-Major: ");
    for (int i = 0; i < 9; i++) printf("%d ", rowMajor[i]);
    
    printf("\nColumn-Major: ");
    for (int i = 0; i < 9; i++) printf("%d ", columnMajor[i]);

    return 0;
}
