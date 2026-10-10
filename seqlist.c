#include <stdio.h>
#define MAXSIZE 100
typedef struct {
    int length;
    int data[MAXSIZE];
}SeqList;
void InitList(SeqList *L){
    L->length=0;
}