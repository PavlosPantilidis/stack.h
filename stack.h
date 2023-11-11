#ifndef STACK_H
#define STACK_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>

/* Typedef */
typedef struct Stack* Stack;
typedef struct Stack* stack;

/* Structs */
struct Node {
    void *data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

/* Functions */
struct Stack *initializeStack(void);
int isEmpty(struct Stack *stack);
void push(struct Stack *stack,void *data);
void *pop(struct Stack *stack);
void *top(struct Stack *stack);
struct Stack *cloneStack(struct Stack *stack);
void destroyStack(struct Stack *stack);

#endif