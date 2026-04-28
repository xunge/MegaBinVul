#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef enum {
    MOBI_SUCCESS,
    MOBI_MALLOC_FAILED
} MOBI_RET;

typedef struct MOBIIndexTag {
    uint32_t tagid;
    uint32_t tagvalues_count;
    uint32_t *tagvalues;
} MOBIIndexTag;

typedef struct MOBIIndexEntry {
    char *label;
    size_t tags_count;
    MOBIIndexTag *tags;
} MOBIIndexEntry;

typedef struct MOBIIndx {
    MOBIIndexEntry *entries;
    void *cncx_record;
} MOBIIndx;

typedef struct MOBITrie MOBITrie;

#define INDX_TAGARR_INFL_PARTS_V1 0

char *mobi_get_cncx_string_flat(void *cncx_record, uint32_t offset, uint32_t len);
MOBI_RET mobi_trie_insert_reversed(MOBITrie **root, char *base, char *inflected);