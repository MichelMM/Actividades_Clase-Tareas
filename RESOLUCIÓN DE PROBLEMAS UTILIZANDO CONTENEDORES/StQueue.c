#include <stdio.h>
#include <stdlib.h>
#include "StQueue.h"

struct strNode{
	Type data;
	struct strNode *prior,*next;
};

typedef struct strNode Node;

struct strStack{
	Node *top;
	int size;
};

struct strQueue{
	Node *first;
	Node *last;
	int size;
};


Stack createStack(){
	Stack new=(Stack)malloc(sizeof(struct strStack));
	if(new==NULL)
		return NULL;
	new->top=NULL;
	new->size=0;
	return new;
}

void destroyStack(Stack who){
	while(isEmptyStack(who)!=true)
		popStack(who);
	free(who);
}

bool pushStack(Stack who, Type data){
	Node *newNode=(Node *)malloc(sizeof(Node));
	if(newNode==NULL)
		return false;
	newNode->prior=who->top;
	newNode->data=data;  //Cuidado aquí
	who->size+=1;
	who->top=newNode;
	return true;
}

Type popStack(Stack who){
	if (who->top==NULL)
		return NULL;
	Type temp;
	Node *tempNode;
	temp=who->top->data;
	who->size--;
	tempNode=who->top;
	who->top=who->top->prior;
	free(tempNode);
	return temp;
}

Type topStack(Stack who){
	if (who->top==NULL)
		return NULL;
	return who->top->data;
}

bool isEmptyStack(Stack who){
	if (who->size==0)
		return true;
	else
		return false;
}

bool isEmptyQueue(Queue who){
	if (who->size==0)
		return true;
	return false;
}

int sizeQueue(Queue who){
	return who->size;
}

Queue createQueue(){
	Queue new=(Queue)malloc(sizeof(struct strQueue));
	new->first=NULL;
	new->last=NULL;
	new->size=0;
	return new;
}

void destroyQueue(Queue who){
	while(isEmptyQueue(who)==false)
		pollQueue(who);
}

void offerQueue(Queue who, Type data){
	Node *newNode=(Node *)malloc(sizeof(struct strNode));
	newNode->next=NULL;
	newNode->data=data;
	if(isEmptyQueue(who)==true){
		who->first=newNode;
		who->last=newNode;
	}
	else{
		who->last->next=newNode;
		who->last=newNode;
	}
	who->size++;
}

Type pollQueue(Queue who){
	Node *tempNode;
	Type tempData;
	if(isEmptyQueue(who)==false){
		tempNode=who->first;
		tempData=who->first->data;
		who->first=who->first->next;
		free(tempNode);
		who->size--;
		if(isEmptyQueue(who)==true)
			who->last=NULL;
		return tempData;
	}
	return NULL;
}

Type peekQueue(Queue who){
	if(isEmptyQueue(who)==false)
		return who->first->data;
	else
		return NULL;
}
