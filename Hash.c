#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define TABLESIZE 7
typedef struct HashNode{
	int key;
	int value;
	struct HashNode *next;
}HashNode,*HashList;
typedef struct HashTable{
	 HashList buckets[TABLESIZE];
	int count;
}HashTable;
//初始化哈希表
void InitHash(HashTable *h){
	for(int i=0;i<TABLESIZE;i++){
	h->buckets[i]=NULL;
}
	h->count=0;
}
//哈希函数
int Hash(int key){
	return key%TABLESIZE;
};
//插入（头插）
void InsertHash(HashTable *h,int key,int value){
	int idx=Hash(key);
	HashNode *curr=h->buckets[idx];
	while(curr){
	if(curr->key==key){
	curr->value=value;
}
	curr=curr->next;
}
	HashNode *node=malloc(sizeof(HashNode));
	node->key=key;
	node->value=value;
	node->next=h->buckets[idx];
	h->buckets[idx]=node;
	h->count++;
}
//删除元素
bool Delete(HashTable *h,int key){
	int idx=Hash(key);
	HashNode *prv=NULL;
	HashNode *p=h->buckets[idx];
	while(p && p->key != key){
	prv=p;
	p=p->next;
	if(!p){
	return false;
}
}
	if(prv==NULL){
	h->buckets[idx]=p->next;
}
	prv->next=p->next;
	free(p);
	h->count--;
	return true;
}
//查找元素
int Find(HashTable h,int key){
	int idx=Hash(key);
	HashNode *p=h.buckets[idx];
	while(p){
	if(p->key==key){
	return p->value;
}
	p=p->next;
}
	return -1;
}
//打印哈希表
void Print(HashTable *h){
	int i=0;
	HashNode *p=NULL;
	for(i=0;i<TABLESIZE;i++){
	p=h->buckets[i];
	while(p){
	printf("%d\n",p->value);
	p=p->next;
}
}
	printf("\n");
}
//销毁哈希表
void Destroyhash(HashTable *h);
int main(){
	HashTable h;
	InitHash(&h);
//同一位置插入两个数据
	InsertHash(&h,1,10);
	InsertHash(&h,8,20);
	Print(&h);
	Find(h,1);
//删除key=1元素
	Delete(&h,1);
	Print(&h);
	return 0;
}
