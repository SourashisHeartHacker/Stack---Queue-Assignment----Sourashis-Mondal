#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue(Sourashis).h"

//
//
//
//
//
//
//
//
//
///**IMPLEMENTING STACK USING QUEUE**///
//
//
//
//
//
//
//

struct stack
{
    Queue *q1, *q2;
};

typedef struct stack Stack;

Stack *createStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->q1 = CreateQueue();
    s->q2 = CreateQueue();

    return s;
}

int isEmptyStack(Stack *s)
{
    if (isEmptyQueue(s->q1) && isEmptyQueue(s->q2))
        return 1;
    else
        return 0;
}

void push(Stack *s, int val)
{
    Enqueue(s->q1, val);
}

int top(Stack *s)
{
    if (isEmptyStack(s))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    int last;
    while (!isEmptyQueue(s->q1))
    {
        last = Dequeue(s->q1);
        Enqueue(s->q2, last);
    }

    ///Swap
    Queue *temp = s->q2;
    (s->q2) = s->q1;
    (s->q1) = temp;

    return last;
}

int pop(Stack *s)
{
    if (isEmptyStack(s))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    int last;
    while (!isEmptyQueue(s->q1))
    {
        last = Dequeue(s->q1);
        if (isEmptyQueue(s->q1))
            break;
        Enqueue(s->q2, last);
    }

    ///Swap
    Queue *temp = s->q2;
    s->q2 = s->q1;
    s->q1 = temp;

    return last;
}

void printStackFromTop(Stack *s)
{
    Stack *temp = createStack();
    int x;
    while (!isEmptyStack(s))
    {
        x = pop(s);
        printf("%d  ", x);
        push(temp, x);
    }

    while (!isEmptyStack(temp))
    {
        push(s, pop(temp));
    }

    //free(temp);
    printf("\n\nEnd printFromTop\n\n");
}

int main()
{
    printf("Hello world69\n\n");

    printf("Enter elements to store in stack\n(Enter -1 to indicate end of insertion): ");
    int x = 69;
    Stack *s = createStack();
    // while (1)
    // {
    //     scanf("%d", &x);
    //     if (x == -1)
    //     {
    //         //printf("\nx==-1");
    //         break;
    //     }
    //     push(s, x);
    // }



    for (int i = 1; i <= 5; i++)
        push(s, i);

    printf("\nStack from top to bottm: ");
    printStackFromTop(s);

    //printf("\nsize(s)= %d", size(s));
    printf("\ntop(s)= %d", top(s));
    printf("\nisEmptyStack(s)=%d", isEmptyStack(s));

    printf("\npop(s)= %d", pop(s));
    printf("\ntop(s)= %d", top(s));
    printf("\npop(s)= %d", pop(s));
    printf("\npop(s)= %d", pop(s));
    printf("\npop(s)= %d", pop(s));
    printf("\nStack from top to bottom: ");
    printStackFromTop(s);
    printf("\npop(s)= %d", pop(s));
    printf("\npop(s)= %d", pop(s));
    //printf("\nsize(s)= %d", size(s));

    return 0;
}
