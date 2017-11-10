#pragma once
/* nodes.h: Header file for node functions and definitions */

/******************* structure definitions ********************/

// Message structure
typedef struct message {
    char text[140];
    short sender_id;
    short receiver_id;
    char priority;
    short sequence;
    char other[25];
} Message;

// link is a pointer to a Node
typedef struct node* link;

// Node contains a pointer to next node and a Message structure
struct node { link pNext; Message Data; };

// Alias for Node = struct node
typedef struct node Node;

/******************** function prototypes ***********************/

void traverse(link h, void(*visit)(link));

void traverseR(link h, void(*visit)(link));

void visit(link print_node);