#pragma once
/* get_message.h: Header file for random quote retriever */

/******************* define constants  ********************/

#define BUFFER_LENGTH 140

/******************* Function prototypes ********************/

// Get random message from message file
int GetMessageFromFile(char szBuf[], int iLen, long* q_start, int q_count);
