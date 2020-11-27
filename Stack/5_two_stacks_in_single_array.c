#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define UNDERFLOW INT_MIN
#define OVERFLOW INT_MAX
#define N 6

struct twoStacks
{
    int *a;
    int top1, top2, capacity;
    int size1, size2;
};

typedef struct twoStacks TwoStack;

TwoStack *CreateTwoStack(int capacity)
{
    TwoStack *s = (TwoStack *)malloc(sizeof(TwoStack));
    s->a = (int *)malloc(sizeof(int) * capacity);
    s->capacity = capacity;
    s->size1 = s->size2 = 0;
    s->top1 = -1;
    s->top2 = capacity;

    return s;
}

int isEmptyStack1(TwoStack *s)
{
    if (s->top1 == -1)
        return 1;
    else
        return 0;
}

int isEmptyStack2(TwoStack *s)
{
    if (s->top2 == s->capacity)
        return 1;
    else
        return 0;
}

int isStackArrayFull(TwoStack *s)
{
    if (s->top1 + 1 == s->top2)
        return 1;
    else
        return 0;
}

void pushStack1(TwoStack *s, int val)
{
    if (isStackArrayFull(s))
    {
        printf("\nOVERFLOW\n");
        return;
    }

    s->a[++s->top1] = val;
    s->size1++;
}

void pushStack2(TwoStack *s, int val)
{
    if (isStackArrayFull(s))
    {
        printf("\nOVERFLOW\n");
        return;
    }

    s->a[--s->top2] = val;
    s->size2++;
}

int popStack1(TwoStack *s)
{
    if (isEmptyStack1(s))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    int x = s->a[s->top1--];
    s->size1--;
    return x;
}

int popStack2(TwoStack *s)
{
    if (isEmptyStack2(s))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    int x = s->a[s->top2++];
    s->size2--;
    return x;
}

int top1(TwoStack *s)
{
    if (isEmptyStack1(s))
        return UNDERFLOW;
    else
        return s->a[s->top1];
}

int top2(TwoStack *s)
{
    if (isEmptyStack2(s))
        return UNDERFLOW;
    else
        return s->a[s->top2];
}

int size1(TwoStack *s)
{
    return s->size1;
}

int size2(TwoStack *s)
{
    return s->size2;
}

void printStack1FromBottom(TwoStack *s)
{
    for (int i = 0; i <= s->top1; i++)
        printf("%d ", s->a[i]);
}

void printStack2FromBottom(TwoStack *s)
{
    for (int i = s->capacity - 1; i >= s->top2; i--)
        printf("%d ", s->a[i]);
}

int main()
{
    printf("\nHello wrold\n\n");
    TwoStack *s = CreateTwoStack(N);

    pushStack1(s, 1);
    pushStack1(s, 2);
    pushStack1(s, 3);
    pushStack1(s, 4);
    printf("\nFirst stack from bottom: ");
    printStack1FromBottom(s);

    pushStack2(s, 5);
    pushStack2(s, 6);
    pushStack2(s, 7);
    printf("\nSecond stack from bottom: ");
    printStack2FromBottom(s);

    printf("\npopStack1()= %d", popStack1(s));
    printf("\npopStack1()= %d", popStack1(s));
    printf("\nFirst stack from bottom: ");
    printStack1FromBottom(s);

    //printf("\npopStack2()= %d", popStack2(s));
    printf("\npopStack2()= %d", popStack2(s));
    printf("\nSecond stack from bottom: ");
    printStack2FromBottom(s);

    return 0;
}