#include <stdlib.h>
#include <string.h>

typedef struct _MEMHDR {
    unsigned int mh_tag;
    size_t mh_size;
    int mh_type;
    const char *mh_file;
    int mh_line;
    unsigned long mh_number;
} MEMHDR;

#define MEMTAG 0x5aa5
#define STRDUP_TYPE 0
#define MAX_SIZE_T ((size_t)-1)
#define RESERVE_SIZE (sizeof(MEMHDR))
#define HDR_2_CLIENT(p) ((void *)((char *)(p) + RESERVE_SIZE))

extern int xmlMemInitialized;
extern void *xmlGenericErrorContext;
extern void *xmlMemMutex;
extern unsigned long block;
extern size_t debugMemSize;
extern size_t debugMemBlocks;
extern size_t debugMaxMemSize;
extern unsigned long xmlMemStopAtBlock;
extern void *xmlMemTraceBlockAt;

void xmlInitMemory(void);
void xmlGenericError(void *ctx, const char *msg, ...);
void xmlMemoryDump(void);
void xmlMutexLock(void *mutex);
void xmlMutexUnlock(void *mutex);
void xmlMallocBreakpoint(void);
void debugmem_list_add(MEMHDR *p);

#define TEST_POINT