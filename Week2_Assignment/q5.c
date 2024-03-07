#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
}

char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->data[stack->top--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void reverseString(char *str) {
    int len = strlen(str);
    Stack stack;
    initialize(&stack);
    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }
    for (int i = 0; i < len; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; 
    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
