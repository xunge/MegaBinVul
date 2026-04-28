#include <stdlib.h>
#include <stddef.h>

typedef enum {
    MOBI_SUCCESS,
    MOBI_DATA_CORRUPT,
    MOBI_MALLOC_FAILED
} MOBI_RET;

typedef struct MOBIData {
    struct MOBIMobiHeader *mh;
} MOBIData;

typedef struct MOBIMobiHeader {
    size_t *huff_rec_index;
    size_t *huff_rec_count;
} MOBIMobiHeader;

typedef struct MOBIPdbRecord {
    size_t size;
    struct MOBIPdbRecord *next;
} MOBIPdbRecord;

typedef struct MOBIHuffCdic {
    size_t index_count;
    size_t index_read;
    void *symbols;
} MOBIHuffCdic;

#define HUFF_RECORD_MAXCNT 100
#define HUFF_RECORD_MINSIZE 10

extern size_t mobi_get_kf8offset(const MOBIData *m);
extern const MOBIPdbRecord *mobi_get_record_by_seqnumber(const MOBIData *m, size_t seqnumber);
extern MOBI_RET mobi_parse_huff(MOBIHuffCdic *huffcdic, const MOBIPdbRecord *record);
extern MOBI_RET mobi_parse_cdic(MOBIHuffCdic *huffcdic, const MOBIPdbRecord *record, size_t index);
extern void debug_print(const char *format, ...);