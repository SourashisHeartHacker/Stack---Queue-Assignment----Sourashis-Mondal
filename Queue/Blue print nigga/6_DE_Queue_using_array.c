#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define UNDERFLOW INT_MIN
#define ERROR INT_MAX
#define N 69 // Capacity of queue

struct DEqueue
{
    int *a;
    int front, rear, capacity;
};

typedef struct DEqueue DEQueue;

void shift_array_right(int *a, int start, int end)
{
    if (start > end)
        return;

    for (int i = end; i >= start; i--)
        a[i + 1] = a[i];
}

DEQueue *CreateDEQueue(int capacity)
{
    DEQueue *q = (DEQueue *)malloc(sizeof(DEQueue));
    q->a = (int *)malloc(sizeof(int) * capacity);
    q->front = q->rear = -1;
    q->capacity = capacity;
}

void DeleteQueue(DEQueue *q)
{
    free(q->a);
    free(q);
}

int isEmpty(DEQueue *q)
{

    if (q->front == -1) ///If no enqueue operation was done on the queue
        return 1;
    if (q->front > q->rear) /// If queue becomes empty after performing dequeue operation
        return 1;
    else
        return 0;
}

int isFull(DEQueue *q)
{
    if (q->rear == q->capacity - 1)
        return 1;
    else
        return 0;
}

void InsertRear(DEQueue *q, int val)
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

void InsertFront(DEQueue *q, int val)
{
    if (isFull(q))
    {
        printf("\nOverflow\n");
        return;
    }

    //if there is no space before front in the array
    if (q->front == 0)
        shift_array_right(q->a, q->front, q->rear);
    ///Corner case:If the queue is empty
    else if (isEmpty(q))
        q->front++;
    //If there is space before the front in the array
    else
        q->front--;

    q->rear++;
    q->a[q->front] = val;
}

int DeleteFront(DEQueue *q)
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

int DeleteRear(DEQueue *q)
{
    if (isEmpty(q))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    int x = q->a[q->rear];
    q->rear--;

    ///Corner case: if queue becomes empty after deletion , then set front = rear = -1
    if (q->rear == -1)
        q->front = -1;

    return x;
}

int first(DEQueue *q)
{
    if (isEmpty(q))
        return ERROR;
    else
        return q->a[q->front];
}

int last(DEQueue *q)
{
    if (isEmpty(q))
        return ERROR;
    else
        return q->a[q->rear];
}

void printFromFront(DEQueue *q)
{
    DEQueue *temp = CreateDEQueue(N);

    while (!isEmpty(q))
    {
        int x = DeleteFront(q);
        printf("%d ", x);
        InsertRear(temp, x);
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
    DEQueue *q = CreateDEQueue(N);

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
        InsertRear(q, x);
    }

    printf("\nQueue from front to rear: ");
    printFromFront(q);

    int choice = -1;
    while (1)
    {
        printf("\n\n\n0.InsertFront");
        printf("\n1.InsertRear");
        printf("\n2.DeleteFront");
        printf("\n3.DeleteRear");
        printf("\n4.isFull");
        printf("\n5.isEmpty");
        printf("\n-1.Exit");

        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == -1)
            break;

        switch (choice)
        {
        case 0:
            printf("\nEnter value : ");
            scanf("%d", &x);
            InsertFront(q, x);
            printf("\nQueue from front to rear: ");
            printFromFront(q);
            break;

        case 1:
            printf("\nEnter value : ");
            scanf("%d", &x);
            InsertRear(q, x);
            printf("\nQueue from front to rear: ");
            printFromFront(q);
            break;

        case 2:
            printf("\nDeleteFront(q)= %d", DeleteFront(q));
            printf("\nQueue from front to rear: ");
            printFromFront(q);
            break;

        case 3:
            printf("\nDeleteRear(q)= %d", DeleteRear(q));
            printf("\nQueue from front to rear: ");
            printFromFront(q);
            break;

        case 4:
            printf("\nisFull(q) = %d", isFull(q));
            break;

        case 5:
            printf("\nisEmpty(q) = %d", isEmpty(q));
            break;

        default:
            printf("\nWrong choice!!!!");
            break;
        }
    }

    return 0;
}