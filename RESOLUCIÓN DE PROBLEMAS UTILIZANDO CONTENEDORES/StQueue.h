/*
 * StQueue.h
 *
 *  Created on: 02/07/2018
 *      Author: Michel
 */

#ifndef STQUEUE_H_
#define STQUEUE_H_

typedef enum {false, true} bool;
typedef void * Type;
typedef struct strStack *Stack;
typedef struct strQueue *Queue;

//Pilas
Stack createStack();
void destroyStack(Stack);
bool pushStack(Stack, Type);
Type popStack(Stack);
Type topStack(Stack);
bool isEmptyStack(Stack);

//Filas
Queue createQueue();
void destroyQueue(Queue);
void offerQueue(Queue, Type);
Type pollQueue(Queue);
Type peekQueue(Queue);
bool isEmptyQueue(Queue);
int sizeQueue(Queue);

#endif /* STQUEUE_H_ */
