#include <stdio.h>
#include "llist.h"

int main( )
{
    LList L0,L1,L2, newL;
    int i;

    //printf("\nADT List\n");

    L0 = MakeEmpty( NULL );
    L1 = MakeEmpty( NULL );
    L2 = MakeEmpty( NULL );
    newL = MakeEmpty( NULL );

    printf("\nInsertBeg:\n");
    for( i = 0; i < 10; i++ )
    {
        InsertBeg( i, L0 );
        PrintList( L0 );
		printf("\n");
    }

    printf("\nInsertEnd:\n");
    for( i = 0; i < 10; i++ )
    {
        InsertEnd( i, L1 );
        PrintList( L1 );
		printf("\n");
    }

    printf("\nMember:\n");
    PNode P1 = Member(0,L0);
    if(IsLast(P1)) printf("last "); else printf("not last ");

    if(Member(5,L0)) printf("yes-5 "); else printf("no-5 ");
    if(Member(12,L0)) printf("yes-12 "); else printf("no-12 ");
    if(Member(3,L0)) printf("yes-3 "); else printf("no-3 ");

    printf("\n\nDelete:\n");
    for( i = 0; i < 10; i++ )
    {
        printf("\nDelete  %d: ", i);
        Delete( i, L0 );
        PrintList( L0 );
    }
    printf("\nDelete 12: ");
    Delete(12,L0);
    PrintList( L0 );
    printf("\nDelete  0: ");
    Delete(0,L0);
    PrintList( L0 );
    printf("\nDelete  5: ");
    Delete(5,L0);
    PrintList( L0 );

    printf("\n");
    printf("\nL0: ");
    if(IsEmpty(L0)) printf("empty "); else printf("not empty ");
    PrintList(L0);
    printf("\nL1: ");
    PrintList(L1);
    printf("\nL2: ");
    PrintList(L2);

    //|+-----------------------------------------  FastCat():  ---------------------------------------------------+|
    L1 = MakeEmpty( NULL );
    L2 = MakeEmpty( NULL );

    for(i = 0; i < 10; i++){
        InsertBeg(i, L1);
    }
    for(i = 9; i >= 0; i--){
        InsertBeg(i, L2);
    }
    printf("\n");
    printf("\n");
    printf("\tFastCat: \n");
    printf("L1: ");
    PrintList(L1);
    printf("\n");
    printf("L2: ");
    PrintList(L2);
    printf("\n");
    printf("New L1: ");
    FastCat(L1, L2);
    PrintList(L1);
    printf("\n");
    printf("L2: ");
    PrintList(L2);

    //|+-----------------------------------------  FreshCat():  ---------------------------------------------------+|

    L1 = MakeEmpty( NULL );
    L2 = MakeEmpty( NULL );

    for(i = 0; i < 10; i++){
        InsertBeg(i, L1);
    }
    for(i = 9; i >= 0; i--){
        InsertBeg(i, L2);
    }

    printf("\n");
    printf("\n");
    printf("\tFreshCat: \n");
    printf("L1: ");
    PrintList(L1);
    printf("\n");
    printf("L2: ");
    PrintList(L2);
    printf("\n");
    printf("newL: ");
    PrintList(newL);
    printf("\n");

    newL = FreshCat(L1, L2);

    printf("L1: ");
    PrintList(L1);
    printf("\n");
    printf("L2: ");
    PrintList(L2);
    printf("\n");

    //newL = FreshCat(L1, L2);

    printf("newL: ");
    PrintList(newL);
    printf("\n");


    //|+-----------------------------------------  Cut():  ---------------------------------------------------+|
    L1 = MakeEmpty( NULL );
    L2 = MakeEmpty( NULL );

    /*for(i = 9; i >= 0; i--){
        InsertBeg(i, L2);
    }
    for(i = 0; i < 10; i++){
        InsertBeg(i, L2);
    }*/
    for(i = 0; i < 10; i++){
        InsertBeg(i, L2);
    }
    printf("\n \n \n");

    printf("CUT\n");


    L1 = MakeEmpty(L1);
    printf("L1: ");
    PrintList(L1);
    printf("\n");
    printf("L2: ");
    PrintList(L2);
    printf("\n");
    PNode P;
    P = Member(3, L2);
    L1 = Cut(L2, P);
    printf("\nAfter CUT \n");
    printf("L1: ");
    PrintList(L1);
    printf("\n");
    printf("L2: ");
    PrintList(L2);
    printf("\n");



    RemoveList(&L0);
    RemoveList(&L1);
    RemoveList(&L2);
    RemoveList(&newL);

    return 0;
}
