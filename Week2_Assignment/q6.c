#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertSorted(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);

    if (*head_ref == NULL || (*head_ref)->data >= data) {
        newNode->next = *head_ref;
        if (*head_ref != NULL)
            (*head_ref)->prev = newNode;
        *head_ref = newNode;
    } else {
        struct Node* current = *head_ref;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next != NULL)
            current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }
}

void printList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int val;
    struct Node* head = NULL;

    insertSorted(&head, 5);
    insertSorted(&head, 10);
    insertSorted(&head, 7);
    insertSorted(&head, 3);
    insertSorted(&head, 1);

    printList(head);
    printf("Enter the value : ");
    scanf("%d",&val);
    insertSorted(&head, val);
    printList(head);
    return 0;
}
