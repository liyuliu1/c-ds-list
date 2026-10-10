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