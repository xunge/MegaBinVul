#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define INDX_INFLBUF_SIZEMAX 1024
#define INDX_INFLTAG_SIZEMAX 8192

typedef enum {
    MOBI_SUCCESS,
    MOBI_DATA_CORRUPT,
    MOBI_MALLOC_FAILED,
    MOBI_ERROR
} MOBI_RET;

typedef struct {
    uint32_t *cncx_record;
    size_t entries_count;
    struct MOBIIndexEntry *entries;
} MOBIIndx;

typedef struct MOBIIndexEntry {
    char *label;
} MOBIIndexEntry;

#define INDX_TAGARR_ORTH_INFL 0
#define INDX_TAGARR_INFL_GROUPS 0
#define INDX_TAGARR_INFL_PARTS_V2 0

size_t mobi_get_indxentry_tagarray(uint32_t **array, const MOBIIndexEntry *entry, int tag);
char *mobi_get_cncx_string(uint32_t *cncx_record, uint32_t offset);
MOBI_RET mobi_decode_infl(unsigned char *decoded, int *length, unsigned char *rule);
void debug_print(const char *format, ...);