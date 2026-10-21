#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 5
typedef struct Queue{
	int data[MAXSIZE];
	int rear;
	int front;
}SqQueue;
void InitQueue(SqQueue* Q){
	Q->front=0;
	Q->rear=0;
}
int IsEmpty(SqQueue Q){return Q.front==Q.rear;}
int IsFull(SqQueue Q){return Q.front==(Q.rear+1)%MAXSIZE;}
bool EnQueue(SqQueue* Q,int value){
	if(IsFull(*Q)){
	return false;
}
	Q->data[Q->rear]=value;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return true;
}
bool DeQueue(SqQueue* Q,int *value){
	if(IsEmpty(*Q)){
	return false;
}
	*value=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return true;
}
bool GetHead(SqQueue Q,int* value){
	if(IsEmpty(Q))return false;
	*value=Q.data[Q.front];
	return true;
}
int Length(SqQueue Q){
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

void PrintQueue(SqQueue Q){
	int i=Q.front;
	while(i!=Q.rear){
	printf("%d\n",Q.data[i]);
	i=(i+1)%MAXSIZE;
}
	printf("\n");
}
int main(){
	SqQueue Q;
	int Devalue;
	InitQueue(&Q);
	printf("front=%d, rear=%d\n",Q.front,Q.rear);
	EnQueue(&Q,10);
	EnQueue(&Q,20);
	EnQueue(&Q,30);
	PrintQueue(Q);
	if(DeQueue(&Q,&Devalue)){
	printf("%d出队\n",Devalue);
}
	DeQueue(&Q,&Devalue);
	printf("长度%d\n",Length(Q));
	PrintQueue(Q);
	EnQueue(&Q, 40);
	EnQueue(&Q, 50);
	PrintQueue(Q);
	printf("长度%d\n",Length(Q));
	PrintQueue(Q);
	return 0;
}
