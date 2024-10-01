#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int top;
} Stack;

void init(Stack *stack)
{
    stack->top = -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX - 1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1; // Error value
    }
    return stack->arr[stack->top--];
}

void display(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->arr[i]);
    }
}

int main()
{
    Stack stack;
    init(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack contents:\n");
    display(&stack);

    printf("Popped element: %d\n", pop(&stack));

    printf("Stack contents after pop:\n");
    display(&stack);

    return 0;
}
