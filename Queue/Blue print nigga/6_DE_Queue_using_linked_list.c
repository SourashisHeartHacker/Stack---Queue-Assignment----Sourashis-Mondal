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
struct DEqueue
{
    struct node *front, *rear;
    int size;
};

typedef struct DEqueue DEQueue;
typedef struct node Node;

Node *getNewNode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;

    return p;
}

DEQueue *CreateDEQueue()
{
    DEQueue *q = (DEQueue *)malloc(sizeof(DEQueue));
    q->front = q->rear = NULL;
    q->size = 0;

    return q;
}

void DeleteQueue(DEQueue *q)
{
    Node *p, *r;
    p = r = q->front;

    while (p)
    {
        r = p;
        p = p->next;
        free(r);
    }

    free(q);
}

int isEmpty(DEQueue *q)
{

    if (q->front == NULL) ///If no enqueue operation was done on the queue
        return 1;
    else
        return 0;
}

void InsertRear(DEQueue *q, int val)
{
    Node *newNode = getNewNode(val);

    ///Corner case: For enqueuing first time
    if (isEmpty(q))
        q->front = newNode;

    if (q->rear)
        q->rear->next = newNode;

    q->rear = newNode;
    q->size++;
}

void InsertFront(DEQueue *q, int val)
{
    Node *newNode = getNewNode(val);

    ///Corner case: For enqueuing first time
    if (isEmpty(q))
        q->front = q->rear = newNode;
    else
    {
        newNode->next = q->front;
        q->front = newNode;
    }
    q->size++;
}

int DeleteFront(DEQueue *q)
{
    if (isEmpty(q))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    int x = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    //free(temp);
    q->size--;
    return x;
}

int DeleteRear(DEQueue *q)
{
    if (isEmpty(q))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    Node *temp = q->rear;
    q->size--;

    ///case 1: if the queue contains single element
    if (q->front == q->rear)
        q->front = q->rear = NULL;
    else
    {
        Node *p = q->front;
        while (1)
        {
            if (p->next == q->rear)
            {
                p->next = NULL;
                q->rear = p;
                break;
            }
        }
    }

    int x = temp->data;
    free(temp);

    return x;
}
int first(DEQueue *q)
{
    if (isEmpty(q))
        return ERROR;
    else
        return q->front->data;
}

int last(DEQueue *q)
{
    if (isEmpty(q))
        return ERROR;
    else
        return q->rear->data;
}

void printFromFront(DEQueue *q)
{
    DEQueue *temp = CreateDEQueue();

    while (!isEmpty(q))
    {
        int x = DeleteFront(q);
        printf("%d ", x);
        InsertRear(temp, x);
    }

    DeleteQueue(q);
    q->front = temp->front;
    q->rear = temp->rear;
}

int main()
{
    printf("\nHello world\n\n");
    DEQueue *q = CreateDEQueue();

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
        printf("\n4.isEmpty");
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
            printf("\nisEmpty(q) = %d", isEmpty(q));
            break;

        default:
            printf("\nWrong choice!!!!");
            break;
        }
    }

    return 0;
}