#include <stdio.h>
#include "lstack.h"

int main( )
{
    /*LStack S0,S1;

    S0 = CreateStack();
    S1 = CreateStack();

    printf("\nADT Stack\n");

    printf("\nPush: ");
    for(int i=1; i<=5;i++)
    {
        Push(i,S0);
        Push(i,S1);
        printf("%d ", i);
    }

    printf("\nPrintStack: ");
    printf("\nS0: ");
    PrintStack(S0);
    printf("\nS1: ");
    PrintStack(S1);

    printf("\nMakeEmpty: [MakeEmptyStack(S1)]");
    MakeEmptyStack(S1);

    printf("\nIsEmpty: ");
    if(IsEmptyStack(S0)) printf("S0 empty "); else printf("S0 not empty ");
    if(IsEmptyStack(S1)) printf("S1 empty "); else printf("S1 not empty ");

    RemoveStack(&S0);
    RemoveStack(&S1);
    printf("\n");*/

    LStack S0,S1;

    S0 = CreateStack();
    S1 = CreateStack();

    printf("\nADT Stack\n");

    printf("\nPush: ");
    for(int i=1; i<=5;i++)
    {
        Push(i,S0);
        Push(i,S1);
        printf("%d ", i);
    }

    printf("\nPrintStack: ");
    printf("\nS0: ");
    PrintStack(S0);
    printf("\nS1: ");
    PrintStack(S1);

    printf("\n");
    for (int i = 0; i <= 3; i++) // work correctly
    {
        TElem N = Top(S0);
        Pop(S0);
        printf("%d - number of top \n", N);

    }
    printf("\nPrintStack after Cycle: with POP");
    printf("\nS0: ");
    PrintStack(S0);
    TElem Z;
    for (int i = 0; i <= 3; i++) // work correctly
    {
        Z = TopAndPop(S1);
        printf("%d - number of top \n", Z);
        printf("\nStatk");
        PrintStack(S1);
        printf("\n");
    }




    printf("\n");

    return 0;
}
