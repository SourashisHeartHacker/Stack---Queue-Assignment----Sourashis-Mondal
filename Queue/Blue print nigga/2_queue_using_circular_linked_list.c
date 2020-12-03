#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define UNDERFLOW INT_MIN
#define ERROR INT_MAX

struct node
{
    int data;
    struct node *next;
};
struct queue
{
    struct node *front, *rear;
    int size;
};

typedef struct queue Queue;
typedef struct node Node;

Node *getNewNode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;

    return p;
}

Queue *CreateQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;

    return q;
}

void DeleteQueue(Queue *q)
{
    Node *p, *r;
    p = r = q->front;
    Node *frontTemp = q->front;
    while (p)
    {
        r = p;
        p = p->next;
        free(r);
        if (p == frontTemp)
            break;
    }

    free(q);
}

int isEmpty(Queue *q)
{

    if (q->front == NULL) ///If no enqueue operation was done on the queue
        return 1;
    else
        return 0;
}

void Enqueue(Queue *q, int val)
{
    Node *newNode = getNewNode(val);

    ///Corner case: For enqueuing first time
    if (isEmpty(q))
        q->front = newNode;

    if (q->rear)
        q->rear->next = newNode;

    q->rear = newNode;
    q->rear->next = q->front;
}

int Dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    //*Corner case:if the queue has single element and it has to be deleted
    if (q->rear->next == q->rear)
    {
        int x = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
        return x;
    }

    int x = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    q->rear->next = q->front;
    free(temp);

    return x;
}

int first(Queue *q)
{
    if (isEmpty(q))
        return ERROR;
    else
        return q->front->data;
}

int last(Queue *q)
{
    if (isEmpty(q))
        return ERROR;
    else
        return q->rear->data;
}

void printFromFront(Queue *q)
{
    Queue *temp = CreateQueue();

    while (!isEmpty(q))
    {
        int x = Dequeue(q);
        printf("%d ", x);
        Enqueue(temp, x);
    }

    //DeleteQueue(q);
    q->front = temp->front;
    q->rear = temp->rear;
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
    printFromFront(q);

    printf("\nDequeue(q)= %d", Dequeue(q));
    printf("\nisEmpty(q)= %d", isEmpty(q));
    ///printf("\nHEllo nigga\n");
    printf("\nDequeue(q)= %d", Dequeue(q));
    printf("\nDequeue(q)= %d", Dequeue(q));
    printf("\nDequeue(q)= %d", Dequeue(q));
    printf("\nDequeue(q)= %d", Dequeue(q));
    printf("\nDequeue(q)= %d", Dequeue(q));

    printf("\nEnqueue(q,6)");
    printf("\nEnqueue(q,9)");

    Enqueue(q, 6);
    Enqueue(q, 9);

    printf("\n\nNow queue becomes(from front to rear): ");
    printFromFront(q);

    printf("\n\n\n");
    return 0;
}