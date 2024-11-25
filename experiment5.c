#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    int id;
    char description[100];
    char status[10];
    struct Task* next;
};

struct Task* head = NULL;

void addTask(int id, char description[], char status[]) {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    newTask->id = id;
    strcpy(newTask->description, description);
    strcpy(newTask->status, status);
    newTask->next = head;
    head = newTask;
}

void removeTask(int id) {
    struct Task *temp = head, *prev = NULL;

    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) return;

    if (!prev) head = temp->next;
    else prev->next = temp->next;

    free(temp);
}

void markTaskCompleted(int id) {
    struct Task* temp = head;
    while (temp) {
        if (temp->id == id) {
            strcpy(temp->status, "Completed");
            return;
        }
        temp = temp->next;
    }
}

void displayTasks() {
    struct Task* temp = head;
    while (temp) {
        printf("ID: %d, Description: %s, Status: %s\n", temp->id, temp->description, temp->status);
        temp = temp->next;
    }
}

int main() {
    int choice, id;
    char description[100], status[10];

    while (1) {
        printf("1. Add Task\n2. Remove Task\n3. Mark Task Completed\n4. Display Tasks\n5. Exit\n");
        scanf("%d", &choice);

        if (choice == 5) break;

        if (choice == 1) {
            printf("Enter Task ID: ");
            scanf("%d", &id);
            printf("Enter Description: ");
            scanf(" %[^\n]s", description);
            printf("Enter Status: ");
            scanf("%s", status);
            addTask(id, description, status);
        } else if (choice == 2) {
            printf("Enter Task ID: ");
            scanf("%d", &id);
            removeTask(id);
        } else if (choice == 3) {
            printf("Enter Task ID: ");
            scanf("%d", &id);
            markTaskCompleted(id);
        } else if (choice == 4) displayTasks();
    }
    return 0;
}
