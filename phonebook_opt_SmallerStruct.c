#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt_SmallerStruct.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */

static entry_otherdata* moreData;

entry *findName(char lastname[], entry *pHead)
{
    unsigned int nData = 0;
    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
        ++nData;
    }
    moreData = (entry_otherdata*) malloc(sizeof(entry_otherdata)*nData);
    pHead->other = &moreData[nData-1];
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    free(e->pNext);
    e->pNext = NULL;

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

