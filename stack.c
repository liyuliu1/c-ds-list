#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_SIZE 3
typedef struct{
	int data[MAX_SIZE];
	int top;
}Stack;
void InitStack(Stack* S){
	S->top=-1;
}
bool IsEmpty(Stack* S){
	return S->top==-1;
}
bool IsFull(Stack* S){
	return S->top==MAX_SIZE-1;
}
bool Push(Stack* S,int value){
	if(IsFull(S)){
	printf("栈满，无法入栈\n");
	return false;
}
	S->top++;
	S->data[S->top]=value;
	return true;
}
bool Pop(Stack* S,int* value){
	if(IsEmpty(S)){
	printf("空栈，无法出栈\n");
	return false;
}
	*value =S->data[S->top];
	S->top--;
	return true;
}
void Print(Stack* S){
	if(IsEmpty(S)){
	printf("空栈\n");
}
	for (int i=S->top;i>=0;i--){
	printf("%d\n",S->data[i]);
}
}
int main(){
	Stack S;
	InitStack(&S);
	Print(&S);
	printf("入栈\n");
	Push(&S,1);
	Push(&S,2);
	Push(&S,3);
	Print(&S);
	Push(&S,4);
	Print(&S);
	int popvalue;
	if(Pop(&S,&popvalue)){
	printf("取出元素%d\n",popvalue);
}
	Pop(&S,&popvalue);
	Print(&S);
	return 0;
}
