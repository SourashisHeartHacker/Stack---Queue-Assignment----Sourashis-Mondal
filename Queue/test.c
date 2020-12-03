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

typedef struct node Node;

Node *getNewNode(int val)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;

    return p;
}

int main()
{
    printf("\n\nHello world\n");
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = 69;
    p->next = NULL;

    printf("\nEnd");

    return 0;
}