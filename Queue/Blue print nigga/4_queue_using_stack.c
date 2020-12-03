/********
   NAME: SOURASHIS MONDAL
   ROLL NO: 001911001031
   DEPARTMENT: IT(UG2, 3rd sem)
**/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack(Sourashis).h"
#define DATATYPE int

struct queue
{
    struct stack *s1, *s2;
};

typedef struct queue Queue;

//
//
//
//
//
//
//
//
//
//
//
//
//
//*IMPLEMENTING QUEUE USING TWO STACKS**//
//
//
//
//
//
//
//
//
//
//
//

Queue *CreateQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->s1 = createStack();
    q->s2 = createStack();

    return q;
}

int isEmptyQueue(Queue *q)
{
    if (isEmptyStack(q->s1) && isEmptyStack(q->s2))
        return 1;
    else
        return 0;
}

void Enqueue(Queue *q, int val)
{
    push(q->s1, val);
}

int Dequeue(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    if (isEmptyStack(q->s2))
        while (!isEmptyStack(q->s1))
            push(q->s2, pop(q->s1));

    return pop(q->s2);
}

void printQueueFromFront(Queue **q)
{
    Queue *temp = CreateQueue();

    while (!isEmptyQueue(*q))
    {
        int x = Dequeue(*q);
        printf("%d ", x);
        Enqueue(temp, x);
    }

    //DeleteQueue(q);
    free(*q);
    *q = temp;
}

int main()
{
    printf("\nHello world\n\n");
    Queue *q = CreateQueue();

    // printf("Enter elements to store in Queue\n(Enter -1 to indicate end of insertion): ");
    // int x = 69;
    // while (1)
    // {
    //     scanf("%d", &x);
    //     if (x == -1)
    //     {
    //         //printf("\nx==-1");
    //         break;
    //     }
    //     Enqueue(q, x);
    // }

    Enqueue(q, 1);
    Enqueue(q, 2);
    Enqueue(q, 3);
    Enqueue(q, 4);
    Enqueue(q, 5);

    // printf("\n\nElements of queue: ");
    // printarray(q->front, q->rear, q->a);
    // printf("\n\n\n");

    printf("\n\nQueue from front: ");
    printQueueFromFront(&q);

    printf("\nDequeue(q)= %d", Dequeue(q));
    printf("\nisEmptyQueue(q)= %d", isEmptyQueue(q));
    ///printf("\nHEllo nigga\n");
    printf("\nDequeue(q)= %d", Dequeue(q));
    printf("\nDequeue(q)= %d", Dequeue(q));
    printf("\nDequeue(q)= %d", Dequeue(q));
    printf("\nDequeue(q)= %d", Dequeue(q));
    printf("\nDequeue(q)= %d", Dequeue(q));

    Enqueue(q, 6);
    Enqueue(q, 9);

    printf("\n\nNow queue becomes(from front to rear): ");
    printQueueFromFront(&q);

    printf("\n\n\n");
    return 0;
}