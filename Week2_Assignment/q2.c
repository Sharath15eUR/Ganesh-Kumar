#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head_ref, char data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void rotateByN(struct Node** head_ref, int N) {
    if (*head_ref == NULL || N == 0) {
        return;
    }

    struct Node* current = *head_ref;
    int count = 1;
    while (count < N && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return;
    }

    struct Node* NthNode = current;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = *head_ref;
    (*head_ref)->prev = current;
    *head_ref = NthNode->next;
    (*head_ref)->prev = NULL;
    NthNode->next = NULL;
}

void printList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;

    insertEnd(&head, 'a');
    insertEnd(&head, 'b');
    insertEnd(&head, 'c');
    insertEnd(&head, 'd');
    insertEnd(&head, 'e');
    insertEnd(&head, 'f');
    insertEnd(&head, 'g');
    insertEnd(&head, 'h');
     
    printList(head);

    int N;
    printf("Enter the number of nodes to rotate by: ");
    scanf("%d", &N);
    rotateByN(&head, N);

    printList(head);

    return 0;
}
