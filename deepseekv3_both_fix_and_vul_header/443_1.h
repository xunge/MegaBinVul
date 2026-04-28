#include <stddef.h>
#include <stdint.h>

#define FORCE_INLINE_TEMPLATE static inline
#define BYTE uint8_t
#define U32 uint32_t
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MEM_32bits() (sizeof(size_t)==4)
#define CHECK_E(f, e) do { size_t const _f = (f); if (_f == (e)) return (e); } while(0)
#define DEBUGLOG(...) 
#define ERROR(e) (0)

typedef struct {
    size_t litLength;
    size_t matchLength;
    size_t offset;
} seqDef;

typedef struct {
    void* startPtr;
    void* endPtr;
    void* ptr;
} BIT_CStream_t;

typedef struct {
    unsigned stateLog;
} FSE_CState_t;

typedef struct {
    int dummy;
} FSE_CTable;

#define dstSize_tooSmall (0)
#define STREAM_ACCUMULATOR_MIN (0)
#define LLFSELog (0)
#define MLFSELog (0)
#define OffFSELog (0)
#define MINMATCH (0)

extern U32 LL_bits[];
extern U32 ML_bits[];

size_t BIT_initCStream(BIT_CStream_t* bs, void* dst, size_t dstCapacity);
void BIT_addBits(BIT_CStream_t* bs, size_t value, unsigned nbBits);
void BIT_flushBits(BIT_CStream_t* bs);
size_t BIT_closeCStream(BIT_CStream_t* bs);
void FSE_initCState2(FSE_CState_t* state, const FSE_CTable* ct, BYTE symbol);
void FSE_encodeSymbol(BIT_CStream_t* bs, FSE_CState_t* state, BYTE symbol);
void FSE_flushCState(BIT_CStream_t* bs, FSE_CState_t* state);