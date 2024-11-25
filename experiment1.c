#include <stdio.h>

void insertAtBeginning(int arr[], int *n, int element) {
    for (int i = *n; i > 0; i--) arr[i] = arr[i - 1];
    arr[0] = element;
    (*n)++;
}

void insertAtEnd(int arr[], int *n, int element) {
    arr[*n] = element;
    (*n)++;
}

void insertAtPosition(int arr[], int *n, int element, int position) {
    for (int i = *n; i > position; i--) arr[i] = arr[i - 1];
    arr[position] = element;
    (*n)++;
}

int main() {
    int arr[100], n = 0, choice, element, position;

    while (1) {
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Exit\n");
        scanf("%d", &choice);

        if (choice == 4) break;

        printf("Enter Element: ");
        scanf("%d", &element);

        if (choice == 1) insertAtBeginning(arr, &n, element);
        else if (choice == 2) insertAtEnd(arr, &n, element);
        else if (choice == 3) {
            printf("Enter Position: ");
            scanf("%d", &position);
            insertAtPosition(arr, &n, element, position);
        }

        printf("Array: ");
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
