#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to check if the linked list has a cycle
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

 struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow pointer by one step
        fast = fast->next->next;    // Move fast pointer by two steps

        if (slow == fast) {
            return true;            // Cycle detected
        }
    }

    return false;                   // No cycle
}

// Helper function to create a new list node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Example 1
    struct ListNode* head1 = createNode(3);
    head1->next = createNode(2);
    head1->next->next = createNode(0);
    head1->next->next->next = createNode(-4);
    head1->next->next->next->next = head1->next; // Creating a cycle

    printf("Example 1: %s\n", hasCycle(head1) ? "true" : "false");

    // Example 2
    struct ListNode* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = head2; // Creating a cycle

    printf("Example 2: %s\n", hasCycle(head2) ? "true" : "false");

    // Example 3
    struct ListNode* head3 = createNode(1);

    printf("Example 3: %s\n", hasCycle(head3) ? "true" : "false");

return 0;
}
