#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

int main() {
    int matrix[MAX][MAX];
    Term sparse[MAX];
    int rows, cols, k = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }

    printf("\nSparse Matrix Representation (row col value):\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    return 0;
}

