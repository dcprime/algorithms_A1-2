/******************* get_message.cpp ************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "queues.h"

int GetMessageFromFile(char szBuf[], int iLen, long* q_start, int q_count) {

    FILE *fp;

    int rand_num;
    int i = 0;
    char next_char = '1';           // manages while loop for file analysis

    // open quote file and return 1 if file not found
    if (fopen_s(&fp, "FortuneCookies.txt", "r") != 0) {
        return(1);
    }

    rand_num = (rand() % (q_count - 1) + 1);

    fseek(fp, q_start[rand_num], SEEK_SET);

    // loop to populate szBuf with iLen chars or until "%%
    for (i = 0; i < (iLen - 1); i++) {
        szBuf[i] = fgetc(fp);
        if (szBuf[i] == '%' && szBuf[i - 1] == '%') {
            break;
        }
    }

    szBuf[i - 1] = '\0'; // end the character array

    fclose(fp); // close the file pointer

    return (0);   //successful retrieval of quote
}

