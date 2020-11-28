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

    while (p)
    {
        r = p;
        p = p->next;
        free(r);
    }

    free(q);
}

int isEmptyQueue(Queue *q)
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
    if (isEmptyQueue(q))
        q->front = newNode;

    if (q->rear)
        q->rear->next = newNode;

    q->rear = newNode;
}

int Dequeue(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("\nUNDERFLOW\n");
        return UNDERFLOW;
    }

    int x = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    //l̥free(temp);

    return x;
}

int first(Queue *q)
{
    if (isEmptyQueue(q))
        return ERROR;
    else
        return q->front->data;
}

int last(Queue *q)
{
    if (isEmptyQueue(q))
        return ERROR;
    else
        return q->rear->data;
}

void printFromFront(Queue *q)
{
    Queue *temp = CreateQueue();

    while (!isEmptyQueue(q))
    {
        int x = Dequeue(q);
        printf("%d ", x);
        Enqueue(temp, x);
    }

    DeleteQueue(q);
    q->front = temp->front;
    q->rear = temp->rear;
}

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

    free(temp);
    //printf("\n\nEnd printFromTop\n\n");
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