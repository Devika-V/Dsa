#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

int main() {
    Term sparse[MAX], transpose[MAX];
    int rows, cols, nonZero, k = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &nonZero);

    printf("Enter non-zero elements (row col value):\n");
    for (int i = 0; i < nonZero; i++) {
        scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].value);
    }

    // Transpose: swap row and col
    for (int i = 0; i < nonZero; i++) {
        transpose[i].row = sparse[i].col;
        transpose[i].col = sparse[i].row;
        transpose[i].value = sparse[i].value;
    }

    // Optional: sort transpose by row then column
    for (int i = 0; i < nonZero - 1; i++) {
        for (int j = i + 1; j < nonZero; j++) {
            if (transpose[i].row > transpose[j].row ||
               (transpose[i].row == transpose[j].row && transpose[i].col > transpose[j].col)) {
                Term temp = transpose[i];
                transpose[i] = transpose[j];
                transpose[j] = temp;
            }
        }
    }

    printf("\nOriginal Sparse Matrix:\n");
    printf("Row Col Value\n");
    for (int i = 0; i < nonZero; i++) {
        printf("%3d %3d %5d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    printf("\nTransposed Sparse Matrix:\n");
    printf("Row Col Value\n");
    for (int i = 0; i < nonZero; i++) {
        printf("%3d %3d %5d\n", transpose[i].row, transpose[i].col, transpose[i].value);
    }

    return 0;
}

