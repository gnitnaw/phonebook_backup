#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt_hash_bkdr.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */

static entry_otherdata* moreData;

entry *findName(char lastname[], entry *pHead)
{
    unsigned int name = BKDRHash(lastname);
    while (pHead != NULL) {
        if (name == pHead->lastName_hash) {
            return pHead;
        }
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    e->lastName_hash = BKDRHash(lastName);
//    free(e->pNext);
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

unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;

    while (*str) {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

