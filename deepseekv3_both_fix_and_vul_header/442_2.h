#include <stddef.h>
#include <string.h>
#include <assert.h>

#define MEM_STATIC static
#define ZSTD_STATIC_ASSERT(cond) typedef char static_assertion_##__LINE__[(cond) ? 1 : -1]
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define STREAM_ACCUMULATOR_MIN 0
#define MaxSeq 0xFF
#define HUF_WORKSPACE_SIZE (1 << 20)
#define MLFSELog 9
#define LLFSELog 9
#define LONGNBSEQ 0x7F00
#define MaxLL 35
#define MaxOff 28
#define DefaultMaxOff 28
#define OffFSELog 9
#define MaxML 52
#define MLFSELog 9
#define dstSize_tooSmall 1
#define ERROR(e) (size_t)(-e)
#define ZSTD_isError(e) ((e) > 0xFFFFFFFFFFFFF000ULL)
#define DEBUGLOG(l, ...)

typedef unsigned char BYTE;
typedef unsigned short U16;
typedef unsigned int U32;
typedef size_t size_t;

typedef enum {
    ZSTD_defaultAllowed,
    ZSTD_defaultDisallowed
} ZSTD_defaultPolicy_e;

typedef enum {
    ZSTD_fast,
    ZSTD_dfast,
    ZSTD_greedy,
    ZSTD_lazy,
    ZSTD_lazy2,
    ZSTD_btlazy2,
    ZSTD_btopt,
    ZSTD_btultra
} ZSTD_strategy;

typedef enum {
    raw,
    rle,
    compressed,
    set_basic,
    set_compressed,
    set_rle
} symbolEncodingType_e;

typedef enum {
    FSE_repeat_none,
    FSE_repeat_check,
    FSE_repeat_valid
} FSE_repeat;

typedef struct {
    int windowLog;
    ZSTD_strategy strategy;
    int targetLength;
} ZSTD_compressionParameters;

typedef struct {
    ZSTD_compressionParameters cParams;
} ZSTD_CCtx_params;

typedef struct FSE_CTable_s FSE_CTable;

typedef struct {
    FSE_CTable* litlengthCTable;
    FSE_CTable* offcodeCTable;
    FSE_CTable* matchlengthCTable;
    FSE_repeat litlength_repeatMode;
    FSE_repeat offcode_repeatMode;
    FSE_repeat matchlength_repeatMode;
} ZSTD_fseCTables_t;

typedef struct {
    void* huf;
    ZSTD_fseCTables_t fse;
} ZSTD_entropyCTables_t;

typedef struct seqDef_s {
    U32 offset;
    U16 litLength;
    U16 matchLength;
} seqDef;

typedef struct {
    const seqDef* sequencesStart;
    const seqDef* sequences;
    const BYTE* litStart;
    const BYTE* lit;
    const BYTE* ofCode;
    const BYTE* llCode;
    const BYTE* mlCode;
} seqStore_t;

static const int LL_defaultNorm[MaxLL+1] = {0};
static const int OF_defaultNorm[MaxOff+1] = {0};
static const int ML_defaultNorm[MaxML+1] = {0};
static const int LL_defaultNormLog = 6;
static const int OF_defaultNormLog = 5;
static const int ML_defaultNormLog = 6;

static void* MEM_writeLE16(void* dst, U16 val) { return dst; }
static size_t HIST_countFast_wksp(U32* count, U32* max, const BYTE* src, size_t srcSize, void* workspace, size_t workspaceSize) { return 0; }

extern size_t ZSTD_compressLiterals(void* const*, void**, ZSTD_strategy, int, void*, size_t, const BYTE*, size_t, void*, size_t, int);
extern void ZSTD_seqToCodes(seqStore_t*);
extern size_t ZSTD_buildCTable(void*, size_t, FSE_CTable*, int, symbolEncodingType_e, U32*, U32, const BYTE*, size_t, const void*, int, int, void*, size_t, void*, size_t);
extern size_t ZSTD_encodeSequences(void*, size_t, FSE_CTable*, const BYTE*, FSE_CTable*, const BYTE*, FSE_CTable*, const BYTE*, const seqDef*, size_t, int, int);
extern int ZSTD_selectEncodingType(FSE_repeat*, U32*, U32, size_t, size_t, int, FSE_CTable*, const void*, int, ZSTD_defaultPolicy_e, ZSTD_strategy);