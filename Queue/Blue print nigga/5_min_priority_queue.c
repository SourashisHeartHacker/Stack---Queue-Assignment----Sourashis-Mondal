#include <stdio.h>
#include <stdlib.h>
#define DATATYPE int
#define N 69

struct priority_queue
{
    int *a;
    int front, rear, size, max_enqueue;
    int *b; ///auxiliary array to store indices
};

typedef struct priority_queue pqueue;

pqueue *create_pqueue(int max_enqueue)
{
    pqueue *q = (pqueue *)malloc(sizeof(pqueue));
    q->a = (int *)malloc(sizeof(int) * max_enqueue);
    q->b = (int *)malloc(sizeof(int) * max_enqueue);

    q->front = q->rear = -1;
    q->size = 0;

    return q;
}

void enqueue(pqueue *q, int val)
{
    ///overflow
    if (q->rear == q->max_enqueue - 1)
    {
        printf("\nOverflow");
        return;
    }

    //if the queue is empty
    if (q->front == -1)
        q->front++;

    q->rear++;
    q->a[q->rear] = val;
    q->b[q->rear] = q->rear;

    //q->size++;

    ///insert index in sorted manner of elements of the pqueue into the auxiliary array
    int i, j;
    for (i = 0; i < q->rear; i++)
        if (val <= q->a[q->b[i]])
            break;

    ///Shifting
    for (j = q->rear - 1; j >= i; j--)
        q->b[j + 1] = q->b[j];

    q->b[j + 1] = q->rear;

    q->size++;
}

int dequeue(pqueue *q)
{
    if (q->size == 0)
    {
        printf("\nUnderflow\n");
        return -1;
    }

    int x = q->a[q->b[0]];

    ///Delete 0th element from b and shift the rest
    for (int i = 0; i <= q->rear - 1; i++)
        q->b[i] = q->b[i + 1];

    q->size--;

    return x;
}

void printarray(int n, int *a)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    printf("\nHello worold\n");

    pqueue *q = create_pqueue(N);

    // for (int i = 0; i < 10; i++)
    //     enqueue(q, i);

    // enqueue(q, 0);
    // enqueue(q, 1);
    // enqueue(q, 2);

    enqueue(q, 69);
    enqueue(q, 96);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 100);
    enqueue(q, 5);

    printarray(q->size, q->a);
    printf("\n");
    printarray(q->size, q->b);

    printf("\n\nDeque(q)= %d", dequeue(q));
    printf("\nDeque(q)= %d", dequeue(q));
    printf("\nDeque(q)= %d", dequeue(q));
    printf("\nq->a   =  ");
    printarray(q->size, q->a);
    printf("\nq->b =  ");
    printarray(q->size, q->b);

    return 0;
}

