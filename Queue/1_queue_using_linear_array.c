#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define UNDERFLOW INT_MIN
#define ERROR INT_MAX
#define N 69 // Capacity of queue

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

    if (q->front == -1) ///If no enqueue operation was done on the queue
        return 1;
    if (q->front > q->rear) /// If queue becomes empty after performing dequeue operation
        return 1;
    else
        return 0;
}

int isFull(Queue *q)
{
    if (q->rear == q->capacity - 1)
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

    ///Corner case: If the queue is empty
    if (isEmpty(q))
        q->front++;

    q->rear++;
    q->a[q->rear] = val;
}

int Dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    int x = q->a[q->front];
    q->front++;

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

    printf("Enter elements to store in Queue\n(Enter -1 to indicate end of insertion): ");
    int x = 69;
    while (1)
    {
        scanf("%d", &x);
        if (x == -1)
        {
            //printf("\nx==-1");
            break;
        }
        Enqueue(q, x);
    }

    // Enqueue(q, 1);
    // Enqueue(q, 2);
    // Enqueue(q, 3);
    // Enqueue(q, 4);
    // Enqueue(q, 5);

    // printf("\n\nElements of queue: ");
    // printarray(q->front, q->rear, q->a);
    // printf("\n\n\n");

    printf("\n\nQueue from front: ");
    printFromFront(q);

    printf("\nDequeue(q)= %d", Dequeue(q));
    printf("\nisEmpty(q)= %d", isEmpty(q));
    printf("\nisFull(q)= %d", isFull(q));
    printf("\nDequeue(q)= %d", Dequeue(q));

    printf("\n\nNow queue becomes(from front to rear): ");
    printFromFront(q);

    
    return 0;
}