#include <stddef.h>
#include <string.h>
#include <assert.h>

#define MEM_STATIC static

typedef unsigned char BYTE;
typedef unsigned int U32;
typedef short S16;

typedef enum { set_rle, set_repeat, set_basic, set_compressed } symbolEncodingType_e;

#define MaxSeq 255
#define ERROR(code) (size_t)(code)
#define CHECK_F(code) { size_t const __err = (code); if (FSE_isError(__err)) return __err; }

typedef struct FSE_CTable FSE_CTable;

size_t FSE_buildCTable_rle(FSE_CTable* ct, BYTE symbolValue);
size_t FSE_buildCTable_wksp(FSE_CTable* ct, const S16* norm, U32 max, U32 tableLog, void* workspace, size_t workspaceSize);
size_t FSE_writeNCount(void* buffer, size_t bufferSize, const S16* norm, U32 max, U32 tableLog);
unsigned FSE_isError(size_t code);
size_t FSE_normalizeCount(S16* norm, U32 tableLog, const U32* count, size_t total, U32 max);
U32 FSE_optimalTableLog(U32 maxTableLog, size_t srcSize, U32 maxSymbolValue);

#define DEBUGLOG(lvl, ...) ((void)0)
#define dstSize_tooSmall ERROR(0)
#define GENERIC ERROR(1)