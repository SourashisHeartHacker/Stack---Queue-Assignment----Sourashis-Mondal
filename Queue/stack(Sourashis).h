#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define DATATYPE int
#define UNDERFLOW INT_MIN

struct node
{
    DATATYPE data;
    struct node *next;
};

struct stack
{
    struct node *top;
    int size;
};

typedef struct node Node;
typedef struct stack Stack;

Node *getNewNode(DATATYPE data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Stack *createStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;

    return s;
}

void push(Stack *s, DATATYPE val)
{
    Node *newNode = getNewNode(val);

    //if stack was not empty
    if (s->top)
        newNode->next = s->top;

    s->top = newNode;
    s->size++;
}

//Deletes the top element of the stack and returns the value . and if the stack is empty, returns
//predefined underflow value
DATATYPE pop(Stack *s)
{
    if (s->top)
    {
        Node *p = s->top;
        DATATYPE temp = p->data;
        s->top = p->next;
        free(p);
        s->size--;

        return temp;
    }
    else
        return UNDERFLOW;
}

///returns the top of stack if stack is not empty;
//else returns predefined underflow value
DATATYPE top(Stack *s)
{
    if (s->top)
        return s->top->data;
    else ///Underflow
        return UNDERFLOW;
}

int sizeStack(Stack *s)
{
    return s->size;
}

int isEmptyStack(Stack *s)
{
    if (s->size == 0)
        return 1;
    else
        return 0;
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
}

void printStackFromBottom(Stack *s)
{
    Stack *temp = createStack();
    int x;
    while (!isEmptyStack(s))
    {
        push(temp, pop(s));
    }

    while (!isEmptyStack(temp))
    {
        x = pop(temp);
        printf("%d  ", x);
        push(s, x);
    }

    free(temp);
}
