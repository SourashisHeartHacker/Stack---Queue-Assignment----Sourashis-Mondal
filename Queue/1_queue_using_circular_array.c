#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define UNDERFLOW INT_MIN
#define ERROR INT_MAX
#define N 6 // Capacity of queue

struct queue
{
    int *a;
    int front, rear, capacity;
};

typedef struct queue Queue;

Queue *CreateQueue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->a = (int *)malloc(sizeof(int) * capacity);
    q->front = q->rear = -1;
    q->capacity = capacity;
}

void DeleteQueue(Queue *q)
{
    free(q->a);
    free(q);
}

int isEmpty(Queue *q)
{

    if (q->front == -1)
        return 1;
    else
        return 0;
}

int isFull(Queue *q)
{
    if ((q->front) % q->capacity == (q->rear + 1) % q->capacity)
        return 1;
    else
        return 0;
}

void Enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        printf("\nOverflow\n");
        return;
    }

    ///Corner case: Enqueuing first time
    if (isEmpty(q))
        q->front++;

    q->rear = (q->rear + 1) % q->capacity;
    q->a[q->rear] = val;
}

///If after dequeuing an element the queue becomes empty, we set front = rear = -1
int Dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    int x = q->a[q->front];

    //Corner case: if there is only one element and it is to be deleted
    if (q->rear == q->front)
        q->rear = q->front = -1;
    else
        q->front = (q->front + 1) % q->capacity;

    return x;
}

int first(Queue *q)
{
    if (isEmpty(q))
        return ERROR;
    else
        return q->a[q->front];
}

int last(Queue *q)
{
    if (isEmpty(q))
        return ERROR;
    else
        return q->a[q->rear];
}

void printFromFront(Queue *q)
{
    Queue *temp = CreateQueue(N);

    while (!isEmpty(q))
    {
        int x = Dequeue(q);
        printf("%d ", x);
        Enqueue(temp, x);
    }

    free(q->a);
    q->a = temp->a;
    q->front = temp->front;
    q->rear = temp->rear;
    //DeleteQueue(temp);
}

void printarray(int start, int end, int *a)
{
    for (int i = start; i <= end; i++)
        printf("%d ", a[i]);
}

int main()
{
    printf("\nHello world\n\n");
    Queue *q = CreateQueue(N);

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
    Enqueue(q, 6);
    Enqueue(q, 7);

    // printf("\n\nElements of queue: ");
    // printarray(q->front, q->rear, q->a);
    // printf("\n\n\n");

    printf("\n\nQueue from front: ");
    printFromFront(q);

    printf("\n\nDequeue(q)= %d", Dequeue(q));
    printf("\nNow queue becomes(from front to rear): ");
    printFromFront(q);

    printf("\n\nDequeue(q)= %d", Dequeue(q));
    printf("\nNow queue becomes(from front to rear): ");
    printFromFront(q);

    printf("\n\nDequeue(q)= %d", Dequeue(q));
    printf("\nNow queue becomes(from front to rear): ");
    printFromFront(q);

    printf("\n\nDequeue(q)= %d", Dequeue(q));
    printf("\nNow queue becomes(from front to rear): ");
    printFromFront(q);

    printf("\n\nDequeue(q)= %d", Dequeue(q));
    printf("\nNow queue becomes(from front to rear): ");
    printFromFront(q);

    printf("\n\nDequeue(q)= %d", Dequeue(q));
    printf("\nNow queue becomes(from front to rear): ");
    printFromFront(q);

    int x = 69;
    Enqueue(q, x);
    printf("\n\nEnqueue(q,%d)", x);
    printf("\nNow queue becomes(from front to rear): ");
    printFromFront(q);

    printf("\nisEmpty(q)= %d", isEmpty(q));
    printf("\nisFull(q)= %d", isFull(q));
    // printf("\nDequeue(q)= %d", Dequeue(q));

    // printf("\n\nNow queue becomes(from front to rear): ");
    // printFromFront(q);

    return 0;
}