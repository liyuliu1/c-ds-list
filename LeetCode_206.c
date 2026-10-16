#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
bool InitList(LinkList* L){
	*L=(LNode*)malloc(sizeof(LNode));
	if(*L==NULL){
	printf("内存申请失败\n");
	return false;
}
	return true;
}
bool AddList(LinkList L,int value){
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL){
	printf("内存申请失败\n");
	return false;
}
	s->data=value;
	s->next=NULL;
	LNode *p=L;
	while(p->next!=NULL){
	p=p->next;
}
	p->next=s;
	return true;
}
void PrintList(LinkList L){
	LNode *s=L->next;
	while(s!=NULL){
	printf("%d\n",s->data);
	s=s->next;
}
}
LinkList ReverseList(LinkList L){
	LNode *prev=NULL;
	LNode *curr=L->next;
	LNode *next=NULL;
	while(curr!=NULL){
	next = curr->next;
	curr->next=prev;
	prev=curr;
	curr=next;
}
	L->next=prev;
	return L;
}


int main(){
	LinkList L;
	if(!InitList(&L)){
	printf("初始化失败\n");
	return 1;
}
	AddList(L,1);
	AddList(L,2);
	AddList(L,3);
	AddList(L,4);
	AddList(L,5);
	AddList(L,6);
	PrintList(L);
	printf("反转\n");
	ReverseList(L);
	PrintList(L);
	return 0;
}
