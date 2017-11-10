#pragma once
/* queues.h: Header file for queue functions and definitions */

#include "nodes.h"  // Header file includes Prototypes defined in nodes.cpp

/******************** function prototypes ***********************/

// initialize the queue
void InitQueue(void);

// check if queue is empty
int  IsQueueEmpty(void);

// add Node to queue
void  AddToQueue(Node *);

// remove 1st Node from queue and return pointer to it
Node *DeQueue(void);