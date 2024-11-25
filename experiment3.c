#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int book) {
    if (top == MAX - 1) return;
    stack[++top] = book;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int peek() {
    if (top == -1) return -1;
    return stack[top];
}

void display() {
    for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, book;

    while (1) {
        printf("1. Add Book\n2. Remove Book\n3. View Most Recent Book\n4. Display All Books\n5. Exit\n");
        scanf("%d", &choice);

        if (choice == 5) break;

        if (choice == 1) {
            printf("Enter Book ID: ");
            scanf("%d", &book);
            push(book);
        } else if (choice == 2) printf("Removed Book: %d\n", pop());
        else if (choice == 3) printf("Most Recent Book: %d\n", peek());
        else if (choice == 4) display();
    }
    return 0;
}
