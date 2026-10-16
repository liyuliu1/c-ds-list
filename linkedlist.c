#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct LNode{
	int data;
	struct LNode *next;
} LNode,*LinkList;
bool Initlist(LinkList* L){
	*L=(LNode*)malloc(sizeof(LNode));
	if(*L==NULL){
	printf("内存申请失败\n");
	return false;
}
	(*L)->next=NULL;
	return true;
}
bool Tailappend(LinkList L,int value){
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL){
	printf("内存申请失败\n");
	return false;
}
	LNode *p=L;
	while(p->next!=NULL){
	p=p->next;
}
	s->data=value;
	s->next=NULL;
	p->next=s;
	return true;
}
bool Headappend(LinkList L,int value){
	LNode *s=(LNode*)malloc(sizeof(LNode));
	if(s==NULL){
	printf("内存申请失败\n");
	return false;
}
	s->data=value;
	s->next=L->next;
	L->next=s;
	return true;
}
void Print(LinkList L){
	LNode *p=L->next;
	while(p!=NULL){
	printf("%d->",p->data);
	p=p->next;
}
}
void Destroylist(LinkList* L){
	LNode* p=*L;
	LNode* q;
	while(p!=NULL){
	q=p->next;
	free(p);
	p=q;
}
	*L=NULL;
	printf("链表已销毁,内存已释放\n");
}
int main(){
	LinkList L;
	if(!Initlist(&L)){
	printf("初始化失败\n");
	return 1;
}
	printf("尾插\n");
	Tailappend(L,1);
	Tailappend(L,2);
	Print(L);
	printf("头插\n");
	Headappend(L,3);
	Headappend(L,4);
	Print(L);
	Destroylist(&L);
	return 0;
}
