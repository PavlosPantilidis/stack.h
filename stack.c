#include "stack.h"

/* Function to initialize a new stack */
struct Stack *initializeStack(void) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    if (!stack) {
        perror("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    stack->top = NULL;
    return stack;
}

/* Function to check if the stack is empty */
int isEmpty(struct Stack *stack) {
    return stack->top == NULL;
}

/* Function to push a new element onto the stack */
void push(struct Stack *stack,void *data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (!newNode) {
        perror("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = stack;
    stack->top = newNode;
}

/* Function to pop the top element from the stack */
void *pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr,"Stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    struct Node *temp = stack->top;
    void *data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

/* Function to get the top element without removing it */
void *top(struct Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr,"Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

/* Function to clone a stack */
struct Stack *cloneStack(struct Stack *stack) {
    struct Stack *clonedStack = initializeStack();
    struct Stack *tempStack = initializeStack();
    struct Node *current = stack->top;

    while (current != NULL) {
        push(tempStack,current->data);
        current = current->next;
    }

    current = tempStack->top;
    while (current != NULL) {
        push(clonedStack,current->data);
        current = current->next;
    }
    return clonedStack;
}

/* Function to destroy a stack and free its memory */
void destroyStack(struct Stack *stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}