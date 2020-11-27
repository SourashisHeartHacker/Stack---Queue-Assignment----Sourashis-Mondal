#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define UNDERFLOW INT_MIN
#define N 69 ///Capacity of stack

struct stack
{
    int *a;
    int top;
    int capacity;
};

typedef struct stack Stack;

Stack *createStack(int capacity)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->capacity = capacity;
    s->a = (int *)malloc(sizeof(int) * capacity);

    return s;
}

void push(Stack *s, int val)
{
    if (s->top == s->capacity - 1)
    {
        printf("\nOverflow\n");
        return;
    }

    s->a[++(s->top)] = val;
}

int pop(Stack *s)
{
    if (s->top == -1)
        return UNDERFLOW;

    int x = s->a[s->top];
    s->top--;
    return x;
}

int top(Stack *s)
{
    if (s->top == -1)
        return UNDERFLOW;
    else
        return s->a[s->top];
}

int isEmpty(Stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int isFull(Stack *s)
{
    if (s->top == s->capacity - 1)
        return 1;
    else
        return 0;
}

int size(Stack *s)
{
    return s->top + 1;
}

void printStackFromTop(Stack *s)
{
    Stack *temp = createStack(N);
    int x;
    while (!isEmpty(s))
    {
        x = pop(s);
        printf("%d  ", x);
        push(temp, x);
    }

    while (!isEmpty(temp))
    {
        push(s, pop(temp));
    }

    free(temp);
}

void printStackFromBottom(Stack *s)
{
    Stack *temp = createStack(N);
    int x;
    while (!isEmpty(s))
    {
        push(temp, pop(s));
    }

    while (!isEmpty(temp))
    {
        x = pop(temp);
        printf("%d  ", x);
        push(s, x);
    }

    free(temp);
}

int main()
{
    printf("Hello world69\n\n");

    printf("Enter elements to store in stack\n(Enter -1 to indicate end of insertion): ");
    int x = 69;
    Stack *s = createStack(N);
    while (1)
    {
        scanf("%d", &x);
        if (x == -1)
        {
            //printf("\nx==-1");
            break;
        }
        push(s, x);
    }

    printf("\nStack from top to bottm: ");
    printStackFromTop(s);

    printf("\nsize(s)= %d", size(s));
    printf("\ntop(s)= %d", top(s));
    printf("\nisEmpty(s)=%d", isEmpty(s));

    printf("\npop(s)= %d", pop(s));
    printf("\ntop(s)= %d", top(s));
    printf("\nsize(s)= %d", size(s));

    return 0;
}