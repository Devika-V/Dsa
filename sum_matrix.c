#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

Term mat1[MAX], mat2[MAX], result[MAX];
int n1, n2, n3 = 0;

// Function to add two sparse matrices
void addSparseMatrices() {
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (mat1[i].row < mat2[j].row ||
           (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[n3++] = mat1[i++];
        } else if (mat1[i].row > mat2[j].row ||
                  (mat1[i].row == mat2[j].row && mat1[i].col > mat2[j].col)) {
            result[n3++] = mat2[j++];
        } else {
            result[n3].row = mat1[i].row;
            result[n3].col = mat1[i].col;
            result[n3].value = mat1[i].value + mat2[j].value;
            if (result[n3].value != 0) n3++;
            i++;
            j++;
        }
    }

    while (i < n1) result[n3++] = mat1[i++];
    while (j < n2) result[n3++] = mat2[j++];
}

// Display sparse matrix
void displayMatrix(Term mat[], int n) {
    printf("Row Col Value\n");
    for (int i = 0; i < n; i++) {
        printf("%3d %3d %5d\n", mat[i].row, mat[i].col, mat[i].value);
    }
}

int main() {
    printf("Enter number of non-zero elements in first matrix: ");
    scanf("%d", &n1);
    printf("Enter elements (row col value):\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d %d", &mat1[i].row, &mat1[i].col, &mat1[i].value);
    }

    printf("Enter number of non-zero elements in second matrix: ");
    scanf("%d", &n2);
    printf("Enter elements (row col value):\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d %d", &mat2[i].row, &mat2[i].col, &mat2[i].value);
    }

    addSparseMatrices();

    printf("\nFirst Matrix:\n");
    displayMatrix(mat1, n1);

    printf("\nSecond Matrix:\n");
    displayMatrix(mat2, n2);

    printf("\nSum Matrix:\n");
    displayMatrix(result, n3);

    return 0;
}

