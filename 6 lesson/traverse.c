#include <stdio.h>
#include <stdbool.h>
#include "traverse.h"
#include "lstack.h"

static int *value;
static int *left;
static int *middle;
static int *right;

void SetBT(int* V,int* L,int* R){
    value=V;
    left=L;
    right=R;
}

void SetTT(int* V,int* L,int *M,int* R){
    //MyPrintf("   SetTT - DOPLNIT");
    value = V;
    left = L;
    right = R;
    middle = M;
}

void inorder(int root){
    if(left[root]!=0)inorder(left[root]);
    printf("%d ",value[root]);
    if(right[root]!=0)inorder(right[root]);
}

void preorder(int root){
    printf("%d ",value[root]);
    if(left[root]!=0)preorder(left[root]);
    if(right[root]!=0)preorder(right[root]);
}

void postorder(int root){
    if(left[root]!=0)postorder(left[root]);
    if(right[root]!=0)postorder(right[root]);
    printf("%d ",value[root]);
}

void printCurrentLevel(int root, int level){
    if(root == 0 || level < 1) return;

    if(level == 1){
        printf("%d ", value[root]);
    } else if(level > 1){
        printCurrentLevel(left[root], level - 1);
        printCurrentLevel(right[root], level - 1);
    }
}

int heightTree(int root){
    if(root == 0) return 0;

    int leftHeight = heightTree(left[root]);
    int rightHeight = heightTree(right[root]);

    if(leftHeight > rightHeight){
        return (leftHeight + 1);
    } else{
        return (rightHeight + 1);
    }
}

void levelorder(int root){
    int height = heightTree(root);
    int i;

    for(i = 1; i <= height; i++){
        printCurrentLevel(root, i);
    }
}

void inorderNR(int v){
    LStack S;
    S = CreateStack();
    LT:  while(left[v]!=0){
    Push(v,S);
    v=left[v];
}
    NODE:printf("%d ",value[v]);
    if(right[v]!=0){
        v=right[v];
        goto LT;
    }
    if(!IsEmptyStack(S)){
        v=Top(S);
        Pop(S);
        goto NODE;
    }
    RemoveStack( &S );
}

void preorderNR(int v){
    printf("%d ", v);

    LStack S;
    S = CreateStack();

    LT:
    while(left[v] != 0){
        Push(v, S);
        v = left[v];
        printf("%d ", v);
    }

    NODE:
    if(right[v] != 0){
        v = right[v];
        printf("%d ", v);
        goto LT;
    }
    if(!IsEmptyStack(S)){
        v = Top(S);
        Pop(S);
        goto NODE;
    }
    RemoveStack(&S);
}

void preorderTT(int root){
    printf("%d ", value[root]);

    if(left[root] != 0) preorderTT(left[root]);
    if(middle[root] != 0) preorderTT(middle[root]);
    if(right[root] != 0) preorderTT(right[root]);
}

void postorderTT(int root){
    if(left[root] != 0) postorderTT(left[root]);
    if(middle[root] != 0) postorderTT(middle[root]);
    if(right[root] != 0) postorderTT(right[root]);

    printf("%d ", value[root]);
}


