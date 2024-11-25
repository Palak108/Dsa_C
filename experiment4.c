#include <stdio.h>
#define MAX 100

int queue[MAX], front = 0, rear = -1;

void enqueue(int customer) {
    if (rear == MAX - 1) return;
    queue[++rear] = customer;
}

int dequeue() {
    if (front > rear) return -1;
    return queue[front++];
}

void display() {
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, customer;

    while (1) {
        printf("1. Add Customer\n2. Serve Customer\n3. Display Queue\n4. Exit\n");
        scanf("%d", &choice);

        if (choice == 4) break;

        if (choice == 1) {
            printf("Enter Customer ID: ");
            scanf("%d", &customer);
            enqueue(customer);
        } else if (choice == 2) printf("Served Customer: %d\n", dequeue());
        else if (choice == 3) display();
    }
    return 0;
}
