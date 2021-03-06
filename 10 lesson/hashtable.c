#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

unsigned int Hash(char *key,int htsize){
    int i;
    unsigned int value=0;
    for(i=0;i<strlen(key);i++)
        value =  (value<<5)+key[i];
    return value%htsize;
}

PHASHTABLE HTinit(int size){
    int i;
    PHASHTABLE ht=malloc(sizeof(HASHTABLE));
    ht->size=size;
    ht->table=malloc(size*sizeof(PNODE));
    for(i=0;i<size;i++)
        ht->table[i]=NULL;
    return ht;
}

void HTinsert(PHASHTABLE t, char* key){
     unsigned int h;
     PNODE ptr,tmp;
     h=Hash(key,t->size);
     if(t->table[h]==NULL){
         tmp=malloc(sizeof(NODE));
         tmp->key=key;
         tmp->next=NULL;
         t->table[h]=tmp;
     } else {
         ptr=t->table[h];
         while(ptr->next!=NULL){
             //no duplicate values
             if(strcmp(key,ptr->key)==0)return;
             ptr=ptr->next;
           }
         //no duplicate values
         if(strcmp(key,ptr->key)==0)return;
         tmp=malloc(sizeof(NODE));
         tmp->key=key;
         tmp->next=NULL;
         ptr->next=tmp;
     }
}

int  HTmember(PHASHTABLE t, char* key){
     unsigned int h;
     PNODE ptr;
     h=Hash(key,t->size);
     if(t->table[h]==NULL)return 0;
     ptr=t->table[h];
     while(ptr!=NULL){
         if(strcmp(key,ptr->key)==0)return 1;
         ptr=ptr->next;
         }
     return 0;
}

void HTdelete(PHASHTABLE t, char* key){
    if(t == NULL || key == NULL) return;

    int place = Hash(key, t->size);
    if(t->table[place] == NULL) return;

    PNODE pNodeDelete = t->table[place];
    PNODE pNode = NULL;

    for(; pNodeDelete != NULL; pNodeDelete = pNodeDelete->next){
        if(strcmp(pNodeDelete->key, key) == 0){
            if(pNode != NULL){
                pNode->next = pNodeDelete->next;
            } else{
                t->table[place] = pNodeDelete->next;
            }

            free(pNodeDelete);
            break;
        }
        pNode = pNodeDelete;
    }
}

void HTprint(PHASHTABLE t){
    if(t == NULL) return;

    for(int i = 0; i < t->size; i++){
        PNODE pNode = t->table[i];
        printf("\n%d: ", i);

        while(pNode != NULL){
            printf("%s ", pNode->key);
            pNode = pNode->next;
        }
    }
}
