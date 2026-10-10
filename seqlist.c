#include <stdio.h>
#define MAXSIZE 100
typedef struct {
    int length;
    int data[MAXSIZE];
}SeqList;
void InitList(SeqList *L){
    L->length=0;
}
void printList(SeqList *L){
    for(int i=0;i<L->length;i++){
        printf("xiabiao%d=%d\n",i,L->data[i]);
    }
    printf("shuzulength=%d",L->length);
}
int AppendSeq(SeqList *L,int e){
    if(L->length>=MAXSIZE)
        return 0;
        L->data[L->length]=e;
        L->length++;
       return 1;
}
int InsertSeq(SeqList *L, int pos, int e){
    if(pos<0||pos>L->length)
    return 0;
    if(L->length>=MAXSIZE)
    return 0;
    for(int i=L->length;i>pos;i--){
        L->data[i]=L->data[i-1];
    }
    L->data[pos]=e;
    L->length++;
    return 1;
}