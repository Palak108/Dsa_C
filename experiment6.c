#include <stdio.h>

struct Term {
    int coefficient;
    int powerX;
    int powerY;
};

void addPolynomials(struct Term poly1[], int size1, struct Term poly2[], int size2, struct Term result[], int *sizeResult) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (poly1[i].powerX == poly2[j].powerX && poly1[i].powerY == poly2[j].powerY) {
            result[k].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            result[k].powerX = poly1[i].powerX;
            result[k].powerY = poly1[i].powerY;
            i++; j++; k++;
        } else if (poly1[i].powerX > poly2[j].powerX || 
                   (poly1[i].powerX == poly2[j].powerX && poly1[i].powerY > poly2[j].powerY)) {
            result[k] = poly1[i];
            i++; k++;
        } else {
            result[k] = poly2[j];
            j++; k++;
        }
    }

    while (i < size1) result[k++] = poly1[i++];
    while (j < size2) result[k++] = poly2[j++];

    *sizeResult = k;
}

void displayPolynomial(struct Term poly[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%dx^%dy^%d", poly[i].coefficient, poly[i].powerX, poly[i].powerY);
        if (i < size - 1) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Term poly1[100], poly2[100], result[200];
    int size1, size2, sizeResult;

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &size1);
    for (int i = 0; i < size1; i++) {
        printf("Enter coefficient, power of x, power of y for term %d: ", i + 1);
        scanf("%d%d%d", &poly1[i].coefficient, &poly1[i].powerX, &poly1[i].powerY);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &size2);
    for (int i = 0; i < size2; i++) {
        printf("Enter coefficient, power of x, power of y for term %d: ", i + 1);
        scanf("%d%d%d", &poly2[i].coefficient, &poly2[i].powerX, &poly2[i].powerY);
    }

    addPolynomials(poly1, size1, poly2, size2, result, &sizeResult);

    printf("First Polynomial: ");
    displayPolynomial(poly1, size1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2, size2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result, sizeResult);

    return 0;
}

