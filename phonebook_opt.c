#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */

entry *findName(char lastname[], entry *pHead)
{
while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}

void freeEntry(entry *pHead)
{
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

