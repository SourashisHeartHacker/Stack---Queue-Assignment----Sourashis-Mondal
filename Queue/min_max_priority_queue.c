#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define UNDERFLOW INT_MIN
#define N 69

typedef struct min_max_priority_queue mmpq;
struct min_max_priority_queue
{
    int *a[2];
    int front, rear;
    int capacity;
    int size;
};

mmpq *create_min_max_priority_queue(int capacity)
{
    mmpq *q = (mmpq *)malloc(sizeof(mmpq));
    q->front = q->rear = -1;
    q->capacity = capacity;

    q->a[0] = (int *)malloc(sizeof(int) * capacity);
    q->a[1] = (int *)malloc(sizeof(int) * capacity);

    q->size = 0;

    return q;
}

void shift_array_right(int *a, int start, int end)
{
    if (start > end)
        return;

    for (int i = end; i >= start; i--)
        a[i + 1] = a[i];
}

void shift_array_left(int *a, int start, int end)
{
    if (start > end)
        return;

    for (int i = start; i <= end; i++)
        a[i - 1] = a[i];
}

///Sorted insert ascending
void sorted_insert_ascending(int n, int *a, int val)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] >= val)
            break;
    }

    shift_array_right(a, i, n - 1);
    a[i] = val;
}

void sorted_insert_descending(int n, int *a, int val)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] <= val)
            break;
    }

    shift_array_right(a, i, n - 1);
    a[i] = val;
}

void printArray(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void enqueue_mmpq(mmpq *q, int val)
{
    if (q->size == q->capacity)
    {
        printf("\nOverflow");
        return;
    }

    sorted_insert_ascending(q->size, q->a[0], val);
    sorted_insert_descending(q->size, q->a[1], val);

    if (q->front == -1)
        q->front++;

    q->rear++;
    q->size++;
}

int dequeue_mmpq_min(mmpq *q)
{
    if (q->size == 0)
    {
        printf("\nUNDERFLOW");
        return UNDERFLOW;
    }

    int temp = q->a[0][q->front];

    shift_array_left(q->a[0], q->front + 1, q->rear);
    q->rear--;

    q->size--;

    return temp;
}

int dequeue_mmpq_max(mmpq *q)
{
    if (q->size == 0)
    {
        printf("\nUNDERFLOW");
        return UNDERFLOW;
    }

    int temp = q->a[1][q->front];

    shift_array_left(q->a[1], q->front + 1, q->rear);
    q->rear--;
    q->size--;

    return temp;
}

void print_mmpq(mmpq *q)
{
    printf("\nMin queue: ");
    printArray(q->size, q->a[0]);
    printf("\nMax queue: ");
    printArray(q->size, q->a[1]);
}

int main()
{
    printf("\nHello nigga\n\n");

    // int a[69];

    // sorted_insert_ascending(0, a, 7);
    // sorted_insert_ascending(1, a, 8);
    // sorted_insert_ascending(2, a, 4);
    // sorted_insert_ascending(3, a, 1);
    // sorted_insert_ascending(4, a, 5);
    // sorted_insert_ascending(5, a, 2);

    // printArray(6, a);

    mmpq *q = create_min_max_priority_queue(N);

    enqueue_mmpq(q, 5);
    enqueue_mmpq(q, 6);
    enqueue_mmpq(q, 1);
    enqueue_mmpq(q, 3);
    enqueue_mmpq(q, 4);
    enqueue_mmpq(q, 2);

    print_mmpq(q);

    printf("\n\nq->size= %d\nq->front= %d\nq->rear= %d\n", q->size, q->front, q->rear);

    int x;

    x = dequeue_mmpq_min(q);
    printf("\ndequeue_mmpq_min(q) = %d", x);
    print_mmpq(q);
    printf("\nq->size= %d\nq->front= %d\nq->rear= %d\n", q->size, q->front, q->rear);

    x = dequeue_mmpq_max(q);
    printf("\ndequeue_mmpq_max(q) = %d", x);
    print_mmpq(q);
    printf("\nq->size= %d\nq->front= %d\nq->rear= %d\n", q->size, q->front, q->rear);

    x = dequeue_mmpq_min(q);
    printf("\ndequeue_mmpq_min(q) = %d", x);
    print_mmpq(q);
    printf("\nq->size= %d\nq->front= %d\nq->rear= %d\n", q->size, q->front, q->rear);

    x = dequeue_mmpq_max(q);
    printf("\ndequeue_mmpq_max(q) = %d", x);
    print_mmpq(q);
    printf("\nq->size= %d\nq->front= %d\nq->rear= %d\n", q->size, q->front, q->rear);

    return 0;
}