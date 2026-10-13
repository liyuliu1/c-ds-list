#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INIT_CAPACITY 2
typedef struct{
	int *data;
	int length;
	int capacity;
}Seqlist;
void InitList(Seqlist *L,int initcapacity){
	L->data=(int*)malloc(sizeof(int)*initcapacity);
	if(L->data==NULL){
	printf("内存分配失败\n");
	exit(1);
}
	L->length=0;
	L->capacity=initcapacity;
	printf("初始化成功，容量为%d\n",initcapacity);
}
void Resize(Seqlist *L){
	if(L->length==L->capacity){
	int newcapacity=L->capacity*2;
	int *newdata=(int*) realloc(L->data,sizeof(int)*newcapacity);
	if(newdata==NULL){
	printf("申请内存失败\n");
	exit(1);
}
	L->data=newdata;
	L->capacity=newcapacity;
	printf("已重新申请内存，新的内存空间为%d\n",L->capacity);
}
}
void Append(Seqlist *L,int value){
	Resize(L);
	L->data[L->length]=value;
	L->length++;
}
bool Insert(Seqlist *L,int pos,int value){
	if(pos<0||pos>L->length){
	printf("插入位置不合法");
	return false;
}
	Resize(L);
	for(int i=L->length+1;i>=pos;i--){
	L->data[i]=L->data[i-1];
}
	L->data[pos]=value;
	L->length++;
	return true;
}
bool Delete(Seqlist *L,int pos, int *deletevalue){
	if(pos<0||pos>L->length){
	printf("删除位置不合法");
	return false;
}
	*deletevalue=L->data[pos];
	for(int i=pos;i<L->length-1;i++){
	L->data[i]=L->data[i+1];
	L->length--;
	return true;
}
}
bool Print(Seqlist *L){
	printf("当前表长度为%d,容量为%d\n",L->length,L->capacity);
	for(int i=0;i<L->length;i++){
	printf("下标%d元素为：%d\n",i,L->data[i]);
}
}
bool Destroy(Seqlist *L){
	if(L->data!=NULL){
	free(L->data);
	L->data=NULL;
}
	L->length=0;
	L->capacity=0;
	printf("顺序表已销毁\n");
}
int main(){
int delvalue;
Seqlist L;
InitList(&L,INIT_CAPACITY);
Append(&L,1);
Append(&L,2);
Print(&L);
Append(&L,3);
Print(&L);
Insert(&L,2,20);
Print(&L);
if(Delete(&L,2,&delvalue)){
	printf("被删除元素为%d",delvalue);
}
Destroy(&L);
return 0;
}
