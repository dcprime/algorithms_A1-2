/******************* queues_main.cpp ************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include "get_message.h"  // Header file includes Prototypes defined in get_message.cpp
#include "queues.h"  // Header file includes Prototypes defined in queues.cpp
#include "nodes.h"  // Header file includes Prototypes defined in nodes.cpp

void main(int argc, char *argv[])
{
    FILE *fp;
    char szBuf[BUFFER_LENGTH] = { NULL };   // array to store retrieved message content
    int iLen = BUFFER_LENGTH;               // number of characters in szBuf
    int mNumber = atoi(argv[1]);            // number of quotes to retrieve
    int q_count = 0;                        // number of quotes in file
    char next_char = '1';                   // manages while loop for file analysis
    int i = 0;                              // int for loop counting
    Node *pNode, *pHead;                    // Node pointers for node creation


    //seed random number generator
    time_t seed;
    seed = time(NULL);
    srand(time(NULL));

    // open quote file and print error if file not found
    if (fopen_s(&fp, "FortuneCookies.txt", "r") != 0) {
        printf("Error opening quote list. Check reference file.");
    }

    // set q_count to be number of quotes in file
    while (next_char != EOF) {
        next_char = fgetc(fp);
        if (next_char == '%') {
            if (fgetc(fp) == '%') {
                q_count++;
            }
        }
    }

    // create an array of q_count size to store start position of each quote
    long* q_start;
    q_start = (long *)calloc(q_count, sizeof(long));

    // move file pointer back to start of file and reset next_char and q_count
    fseek(fp, 0, SEEK_SET);
    next_char = '1';
    q_count = 0;

    // populate q_start with the starting position of each quote
    while (next_char != EOF) {
        next_char = fgetc(fp);
        if (next_char == '%') {
            if (fgetc(fp) == '%') {
                q_start[q_count] = ftell(fp) + 1;
                q_count++;
            }
        }
    }

    fclose(fp); // close the file pointer

    // initize queue
    InitQueue();
    
    // loop to 1)create node, 2)populate message, 3)add node to queue
    for (i = 0; i < mNumber; i++) {
        if (i == 0) {
            pNode = (link)malloc(sizeof(Node)); 	          // Make first Node
            pHead = pNode;				                          // save its location
        }
        else {
            pNode->pNext = (link)malloc(sizeof(Node));      // Make Node i
            pNode = pNode->pNext;			                      // Get pointer to Node i
        }
        GetMessageFromFile(szBuf, iLen, q_start, q_count);  // populate szBuf
        memcpy(pNode->Data.text, szBuf, strlen(szBuf) + 1); // populate Data.text with szBuf
        AddToQueue(pNode);                                  // add Node to queue
    }

    // print the message contents of queue in regular order
    traverse(pHead, visit);
    printf("\n--------------------------- End of traverse ---------------------------\n");

    // print the message contents of queue in reverse order
    traverseR(pHead, visit);
    printf("\n--------------------------- End of traverseR ---------------------------\n");

    // print the message content of each node as it is removed from the queue
    /*for (i = 0; i < mNumber; i++) {
        printf("%s\n", DeQueue()->Data.text);
    }*/

    free(q_start);

    system("pause");
}


