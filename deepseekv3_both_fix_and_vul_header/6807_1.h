#include <stdlib.h>
#include <string.h>

typedef struct _MEMHDR {
    unsigned long mh_number;
    unsigned int mh_tag;
    size_t mh_size;
    const char *mh_file;
    int mh_line;
    int mh_type;
} MEMHDR;

#define MEMTAG 0x5aa5
#define REALLOC_TYPE 0
#define MAX_SIZE_T ((size_t)-1)
#define RESERVE_SIZE (sizeof(MEMHDR))
#define CLIENT_2_HDR(p) ((MEMHDR *)((char *)(p) - RESERVE_SIZE))
#define HDR_2_CLIENT(p) ((void *)((char *)(p) + RESERVE_SIZE))
#define TEST_POINT

extern int xmlMemInitialized;
extern unsigned long xmlMemStopAtBlock;
extern void *xmlMemTraceBlockAt;
extern size_t debugMemSize;
extern size_t debugMaxMemSize;
extern int debugMemBlocks;
extern void *xmlGenericErrorContext;
extern void *xmlMemMutex;

void xmlInitMemory(void);
void *xmlMallocLoc(size_t size, const char *file, int line);
void xmlMallocBreakpoint(void);
void Mem_Tag_Err(MEMHDR *p);
void xmlMemoryDump(void);
void xmlGenericError(void *ctx, const char *msg, ...);
void xmlMutexLock(void *mutex);
void xmlMutexUnlock(void *mutex);