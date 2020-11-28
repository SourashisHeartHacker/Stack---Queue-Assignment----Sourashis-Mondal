#pragma once

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
    //free(temp);

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

    //DeleteQueue(q);
    q->front = temp->front;
    q->rear = temp->rear;
}
