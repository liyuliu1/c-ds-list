#include <stdio.h>
#include <stdlib.h>

#define INIT_CAPACITY 2
typedef struct {
	int *data;
	int length;
	int capacity;
}SeqList;
void InitList(SeqList *L,int initcapacity) {
	L->data=(int*)malloc(sizeof(int)*initcapacity);
	if(L->data==NULL){
		printf("无法分配空间\n");
	exit(1);
}
	L->length=0;
	L->capacity=initcapacity;
	printf("初始化成功，容量为%d\n",initcapacity);
}
int main(){
	SeqList L;
	InitList (&L, INIT_CAPACITY);
	return (0);
}
