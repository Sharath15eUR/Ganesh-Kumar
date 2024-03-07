#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    struct Node* next_next;
    if (current == NULL) {
        return;
    }
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        } else {
            current = current->next;
        }
    }
}


void sortedInsert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    
    if (*head_ref == NULL || (*head_ref)->data >= new_data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        
        while (current->next != NULL && current->next->data < new_data) {
            current = current->next;
        }
  
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    sortedInsert(&head, 4);
    sortedInsert(&head, 3);
    sortedInsert(&head, 3);
    sortedInsert(&head, 2);

    printf("Original Linked List: \n");
    printList(head);

    removeDuplicates(head);

    printf("Linked List after removing duplicates: \n");
    printList(head);

    return 0;
}
