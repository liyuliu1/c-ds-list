#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct SNode{
	int data;
	struct SNode* next;
}SNode,*LinkStack;
bool InitStack(LinkStack *S){
	(*S)=(SNode*)malloc(sizeof(SNode));
	if(*S==NULL){
	return false;
}
	(*S)->next=NULL;
	return true;
}
bool IsEmpty(LinkStack S){
	if(S->next==NULL){
	return true;
}
	return false;
}
bool Push(LinkStack S,int value){
	SNode* p=(SNode*)malloc(sizeof(SNode));
	if(p==NULL){
	return false;
}
	p->data=value;
	p->next=S->next;
	S->next=p;
	return true;
}
 bool Pop(LinkStack S,int* value){
	if(IsEmpty(S)){
	return false;
}	SNode* p = S->next;
	*value = p->data;
	S->next=p->next;
	free(p);
	return true;
}
bool GetTop(LinkStack S,int* value){
	if(IsEmpty(S)){
	return false;
}
	*value = S->next->data;
	return true;
}
void Destroy(LinkStack* S){
	SNode* p = *S;
	while(p!=NULL){
	SNode* temp = p->next;
	free(p);
	p = temp;
}
	*S=NULL;
}
int main(){
	LinkStack S;
	if(InitStack(&S)){
	printf("初始化成功\n");
}
	Push(S,10);
	Push(S,20);
	Push(S,30);
	Push(S,40);
	printf("入栈10，20，30，40\n");
	int topval;
	if(GetTop(S,&topval)){
	printf("栈顶元素是%d\n",topval);
}
	int popval;
	if(Pop(S,&popval)){
	printf("出栈元素是%d\n",popval);
}
	Destroy(&S);
	printf("栈已销毁\n");
	return 0;
}
