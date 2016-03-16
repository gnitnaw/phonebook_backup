#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define BLOCK_SIZE	5000
#define OPT_NEW_SIZE

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
// #define OPT 1
typedef struct __PHONE_BOOK_OTHERDATA {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} entry_otherdata;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    entry_otherdata *other;
} entry_single;

typedef struct __PHONE_BOOK_ENTRY_BLOCK {
    entry_single block[BLOCK_SIZE];
    struct __PHONE_BOOK_ENTRY_BLOCK *pNext;
} entry;

entry_single *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);
void freeEntry(entry *e);
#endif
