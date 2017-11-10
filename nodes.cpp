/******************* nodes.cpp ***********************
*                                                    *
*  traverse and traverseR functions adapted from     *
*  W6Algorithms_RecursiveMethods.pptx slides on      *
*  Recursive Methods                                 *
*                                                    *
*****************************************************/


#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "nodes.h"

// Execute a function on each node in order
void traverse(link h, void(*visit)(link)) {
    if (h == NULL) return;
    (*visit)(h);  // calls ‘visit’ before recursive call
    traverse(h->pNext, visit);
}

// Execute a function on each node in reverse
void traverseR(link h, void(*visit)(link)) {
    if (h == NULL) return;
    traverseR(h->pNext, visit);
    (*visit)(h);
}

// Print the message content of a node
void visit(link print_node) {
    printf("%s\n", print_node->Data.text);
}