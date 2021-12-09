    #include "llist.h"
    #include "err.h"
    #include <stdlib.h>

    struct Node
    {
        PNode	Next;
        TElem	Elem;
    };

    struct LnkList
    {
        PNode	First;
        PNode	Last;
    };

    // Makes empty list
    // if not NULL pointer given as parameter, remove the pointed list
    LList MakeEmpty(LList L)
    {
        LList PL;
        if(L != NULL) RemoveList(&L);
        PL = malloc(sizeof(struct LnkList));
        if(PL == NULL) Error("MakeEmpty: out of memory!");
        PL->First = NULL;
        PL->Last = NULL;
        return PL;
    }

    // Removes nonempty list
    // Receives a pointer to LList, not LList itself
    void RemoveList(LList *PL)
    {
        PNode T,P;
        if(PL == NULL) Error("RemoveList: incorrect pointer!");
        LList L = *PL;
        if(L == NULL) return;
        P = L->First;
        while(P != NULL){
            T = P->Next;
            free(P);
            P = T;
        }
        free(L);
        *PL = NULL;
    }

    // Removing the element X from the list L
    void Delete( TElem X, LList L )
    {
        PNode P,C;
        if(L == NULL) Error("Delete: incorrect list!");
        if(Member(X,L)){
            P = L->First;
            C = L->First;
            while(C != NULL){
                if(C->Elem == X){
                    if(C->Next == NULL) L->Last = P;                // the last element of a list
                    if(C->Next == NULL && P == C) L->Last = NULL;   // the only element of a list
                    if(P == C) L->First = C->Next;                  // the first element of a list
                    else P->Next = C->Next;
                    free(C);
                    break;
                }
                P = C;
                C = C->Next;
            }
        }
//        if(!IsEmpty(L)) printf("[DELETE: First: %d, Last: %d] ", L->First->Elem, L->Last->Elem);
//        else printf("[DELETE: First: -, Last: -] ");
    }

    // True if list L is empty
    int IsEmpty(LList L)
    {
        if(L == NULL) Error("IsEmpty: incorrect list!");
        return L->First == NULL;
    }

    // True if P is the last position in a list
    int IsLast(PNode P)
    {
        if(P == NULL) Error( "IsLast: incorrect pointer on input!" );
        return P->Next == NULL;
    }

    // Returns position of element X in list L, NULL if not found
    PNode Member( TElem X, LList L )
    {
        PNode P;
        if(L == NULL) Error("Member: incorrect list!");
        P = L->First;
        while(P != NULL){
            if(P->Elem == X) break;
            P = P->Next;
        }
        return P;
    }

    // Inserting element X at the beginning of the list L
    void InsertBeg( TElem X, LList L )
    {
        PNode T;
        if(L == NULL) Error("InsertBeg: incorrect list!");
        T = malloc(sizeof(struct Node));
        if(T == NULL) Error("InsertBeg: out of memory!");
        T->Elem = X;
        T->Next = L->First;
        if(IsEmpty(L)) L->Last = T;
        L->First = T;
    }

    // Inserting element X at the end of the list L
    void InsertEnd( TElem X, LList L )
    {
        PNode T;
        if(L == NULL) Error("InsertEnd: incorrect list!");
        T = malloc(sizeof(struct Node));
        if(T == NULL) Error("InsertEnd: out of memory!");
        T->Elem = X;
        T->Next = NULL;
        if(IsEmpty(L)) {
            L->First = T;
            L->Last = T;
        }
        else {
            L->Last->Next = T;
            L->Last = T;
        }
    }

    // Returns pointer to the first node of the list L
    PNode First( LList L )
    {
        if(L == NULL) Error("First: incorrect list!");
        return L->First;
    }

    // Returns the pointer to following node
    PNode Next( PNode P )
    {
        if(P == NULL) Error( "Next: incorrect pointer on input!" );
        return P->Next;
    }

    // Returns a pointer to the LList structure
    LList Head( LList L )
    {
        return L;
    }

    // Returns elements at the specified position of a list
    TElem Get( PNode P )
    {
        if(P == NULL) Error( "Get: incorrect pointer on input!" );
        return P->Elem;
    }

    // Prints elements of the list L
    void PrintList( LList L ){
        if(L == NULL) {
            printf("PrintList: incorrect list!\n");
            return;
        }
        PNode P = First( L );
        if(IsEmpty( L )) printf( "Empty list" );
        else
        {
            while(P != NULL)
            {
                printf("%d ", Get(P));
                P = Next(P);
            }
            //printf("\n");
        }
    }

    void FastCat(LList L1, LList L2){
        if((L1 == NULL) || (L2 == NULL)){
            Error("FastCat: incorrect list!\n");
        }

        L1->Last->Next = L2->First;
        L1->Last = L2->Last;
        L2->Last = NULL;
        L2->First = NULL;
    }

    LList FreshCat( LList L1, LList L2 ){
        if((L1 == NULL) || (L2 == NULL)){
            Error("FreshCat: incorrect list!\n");
        }

        LList newL = MakeEmpty(NULL);
        PNode check = L1->First;

        int vCheck;
        while (check != NULL){
            vCheck = Get(check);
            InsertEnd(vCheck, newL);
            check = check->Next;
        }

        PNode N = First(L2);

        newL->Last->Next = N;
        while(N != NULL){
            N = Next(N);
        }
        newL->Last = N;


        return newL;
    }


    LList Cut( LList L, PNode P ){
        if(L == NULL){
            Error("Cut: incorrect list!\n");
            return NULL;
        }
        if(P == NULL){
            Error("Cut: incorrect P!\n");
            return L;
        }

        LList changedL = MakeEmpty(NULL);
        PNode check = L->First;

        int vCheck;
        while (check != NULL){
            vCheck = Get(check);

            if(P->Elem == check->Elem){
                check = check->Next;
                while(check != NULL){
                    vCheck = Get(check);
                    InsertEnd(vCheck, changedL);
                    check = check->Next;
                    Delete(vCheck, L);
                }
                break;
            }
            check = check->Next;
        }



        return changedL;
    }

















