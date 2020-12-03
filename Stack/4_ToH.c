#include "stack(Sourashis).h"

void printTowers(Stack *s1, Stack *s2, Stack *s3, int *id)
{
    Stack *t;

    printf("\nTower1 : ");
    if (id[0] == (int)s1)
        t = s1;
    else if (id[0] == (int)s2)
        t = s2;
    else if (id[0] == (int)s3)
        t = s3;
    printStackFromBottom(t);

    printf("\nTower2 : ");
    if (id[1] == (int)s1)
        t = s1;
    else if (id[1] == (int)s2)
        t = s2;
    else if (id[1] == (int)s3)
        t = s3;
    printStackFromBottom(t);

    printf("\nTower3 : ");
    if (id[2] == (int)s1)
        t = s1;
    else if (id[2] == (int)s2)
        t = s2;
    else if (id[2] == (int)s3)
        t = s3;
    printStackFromBottom(t);
}

void Toh(int n, Stack *s1 /*From*/, Stack *s3 /*To*/, Stack *s2 /*Using*/, int *id)
{
    if (n == 1)
    {
        push(s3, pop(s1));
        printTowers(s1, s2, s3, id);
        printf("\n\n");
        return;
    }
    Toh(n - 1, s1, s2, s3, id);

    push(s3, pop(s1));
    printTowers(s1, s2, s3, id);
    printf("\n\n");

    Toh(n - 1, s2, s3, s1, id);
}

void print_steps_ToH(int n)
{
    Stack *s1 = createStack();
    Stack *s2 = createStack();
    Stack *s3 = createStack();

    ///This is to identify stacks
    int *id = (int *)malloc(sizeof(int) * 3);
    id[0] = (int)s1;
    id[1] = (int)s2;
    id[2] = (int)s3;

    for (int i = n; i >= 1; i--)
    {
        push(s1, i);
    }

    printTowers(s1, s2, s3, id);
    printf("\n");

    Toh(n, s1, s3, s2, id);

    free(s1);
    free(s2);
    free(s3);
    free(id);
}

int main()
{
    printf("\nHello world\n\n");

    print_steps_ToH(3);
    return 0;
}