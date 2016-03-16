#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#include "phonebook_opt_newSize.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */

static entry_otherdata* moreData;
static int iBlock = 0;
static int iElement = 0;

entry_single *findName(char lastname[], entry *pHead)
{
    int i;
    while (pHead != NULL) {
        for (i=0; i<BLOCK_SIZE; ++i) {
            //printf("%s\n", lastname);
            if (strcasecmp(lastname, pHead->block[i].lastName) == 0) {
                return &pHead->block[i];
            }
        }
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    //printf("%s\n", lastName);
    strcpy(e->block[iElement++].lastName, lastName);
    if (iElement==BLOCK_SIZE) {
        e->pNext = (entry *) malloc(sizeof(entry));
        iElement = 0;
        iBlock += 1;
        e = e->pNext;
        e->pNext = NULL;
    }

    return e;
}


void freeEntry(entry *pHead)
{
    free(moreData);
    entry *e;
    while(pHead->pNext !=NULL) {
        e = pHead->pNext;
        free(pHead);
        pHead = e;
    }
    free(pHead);
    e = NULL;
    pHead = NULL;
}

