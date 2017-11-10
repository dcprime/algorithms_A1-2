/******************* queues.cpp **********************
*                                                    *
*  Functions adapted from ESE lecture slides         *
*  on creating queue functions                       *
*                                                    *
*****************************************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "nodes.h"
#include "queues.h"

static Node *pHead, *pTail;

void InitQueue(void)
{
    pHead = pTail = NULL;
}

// Returns non-zero if queue is empty. 
int  IsQueueEmpty(void)
{
    return (pHead == NULL);
}

void  AddToQueue(Node *pn)
{
    if (pHead == NULL) {
        pHead = pn; //make first item ‘head’
    }
    else {
        pTail->pNext = pn;// make the last 
    }           //input point to the new item 
    pn->pNext = NULL;
    pTail = pn; // make this last input
} // item the ‘tail’   

// Return item at the head
Node *DeQueue(void)
{
    Node *pTemp;
    if (pHead == NULL) return(NULL);
    pTemp = pHead;
    pHead = pHead->pNext; // make next item new ‘head’
    return(pTemp);	  // return old ‘head’ 	
}
