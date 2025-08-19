#include <stdio.h>

#define MAX 100

// Structure to represent a term
typedef struct {
    int coeff;
    int exp;
} Term;

Term poly1[MAX], poly2[MAX], result[MAX];
int n1, n2, n3 = 0;

// Function to add two sparse polynomials
void addPolynomials() {
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (poly1[i].exp > poly2[j].exp) {
            result[n3++] = poly1[i++];
        } else if (poly1[i].exp < poly2[j].exp) {
            result[n3++] = poly2[j++];
        } else {
            result[n3].exp = poly1[i].exp;
            result[n3].coeff = poly1[i].coeff + poly2[j].coeff;
            n3++;
            i++;
            j++;
        }
    }

    // Copy remaining terms
    while (i < n1) result[n3++] = poly1[i++];
    while (j < n2) result[n3++] = poly2[j++];
}

// Display polynomial
void display(Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if (i < n - 1) printf(" + ");
    }
    printf("\n");
}

int main() {
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter terms (coeff exponent) in descending order of exponent:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &poly1[i].coeff, &poly1[i].exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter terms (coeff exponent) in descending order of exponent:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &poly2[i].coeff, &poly2[i].exp);
    }

    addPolynomials();

    printf("\nFirst Polynomial: ");
    display(poly1, n1);
    printf("Second Polynomial: ");
    display(poly2, n2);
    printf("Sum Polynomial: ");
    display(result, n3);

    return 0;
}

