/********
   NAME: SOURASHIS MONDAL
   ROLL NO: 001911001031
   DEPARTMENT: IT(UG2, 3rd sem)
**/

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

int size(Stack *s)
{
    return s->size;
}

int isEmpty(Stack *s)
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
    while (!isEmpty(s))
    {
        x = pop(s);
        printf("%d  ", x);
        push(temp, x);
    }

    while (!isEmpty(temp))
    {
        push(s, pop(temp));
    }
}

void printStackFromBottom(Stack *s)
{
    Stack *temp = createStack();
    int x;
    while (!isEmpty(s))
    {
        push(temp, pop(s));
    }

    while (!isEmpty(temp))
    {
        x = pop(temp);
        printf("%d  ", x);
        push(s, x);
    }
}

///Creats a stack and stores first n Fibonacci numbers and returns the stack
Stack *Fibonacci(int n)
{
    Stack *s = createStack();
    if (n <= 0)
        return s;

    push(s, 0);
    if (n == 1)
        return s;
    push(s, 1);
    if (n == 2)
        return s;

    for (int i = 3; i <= n; i++)
    {
        int a = pop(s);
        int b = pop(s);

        int res = a + b;
        push(s, b);
        push(s, a);
        push(s, res);
    }

    return s;
}

int main()
{
    printf("Enter n to get first n Fibonacci numbers: ");
    int n;
    scanf("%d", &n);

    printf("\nFirst n Fibonacci numbers are: ");
    Stack *s = Fibonacci(n);
    printStackFromBottom(s);

    return 0;
}