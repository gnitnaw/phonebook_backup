#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt_hash_sdbm.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */

static entry_otherdata* moreData;

entry *findName(char lastname[], entry *pHead)
{
    unsigned int nData = 0;
    unsigned int name = SDBMHash(lastname);
    while (pHead != NULL) {
        if (name == pHead->lastName_hash)
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
    e->lastName_hash = SDBMHash(lastName);
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

unsigned int SDBMHash(char *str)
{
    unsigned int hash = 0;
    while (*str) {
        // equivalent to: hash = 65599*hash + (*str++);
        hash = (*str++) + (hash << 6) + (hash << 16) - hash;
    }
    return (hash & 0x7FFFFFFF);
}

