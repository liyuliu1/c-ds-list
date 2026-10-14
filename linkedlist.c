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
	(*L)->next=NULL;
	 return true;
}
bool TailList(LinkList L,int value){
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
bool HeadList(LinkList L,int value){
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
	LNode *p;
	p=L->next;
	while(p!=NULL){
	printf("%d\n",p->data);
	p=p->next;
}

}
int main(){
	LinkList L;
	if(!InitList(&L)) return 1;
	printf("初始化成功\n");
	printf("头插\n");
	HeadList(L,2);
	Print(L);
	HeadList(L,3);
	HeadList(L,4);
	printf("尾插\n");
	TailList(L,5);
	Print(L);
}
