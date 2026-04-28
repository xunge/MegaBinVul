#include <stddef.h>

typedef unsigned char BYTE;

typedef struct {
    /* define FSE_CTable structure members here */
} FSE_CTable;

typedef struct {
    /* define seqDef structure members here */
} seqDef;

#define DYNAMIC_BMI2 1

size_t ZSTD_encodeSequences_bmi2(void* dst, size_t dstCapacity,
                                FSE_CTable const* CTable_MatchLength, BYTE const* mlCodeTable,
                                FSE_CTable const* CTable_OffsetBits, BYTE const* ofCodeTable,
                                FSE_CTable const* CTable_LitLength, BYTE const* llCodeTable,
                                seqDef const* sequences, size_t nbSeq, int longOffsets);

size_t ZSTD_encodeSequences_default(void* dst, size_t dstCapacity,
                                   FSE_CTable const* CTable_MatchLength, BYTE const* mlCodeTable,
                                   FSE_CTable const* CTable_OffsetBits, BYTE const* ofCodeTable,
                                   FSE_CTable const* CTable_LitLength, BYTE const* llCodeTable,
                                   seqDef const* sequences, size_t nbSeq, int longOffsets);