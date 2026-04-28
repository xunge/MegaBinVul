#include <stdlib.h>
#include <stddef.h>

#define MAX_SIZE_T ((size_t)-1)
#define RESERVE_SIZE (sizeof(MEMHDR))
#define MEMTAG 0x5aa5
#define MALLOC_TYPE 1
#define DEBUG_MEMORY
#define MEM_LIST
#define TEST_POINT

typedef struct _MEMHDR {
    unsigned int mh_tag;
    size_t mh_size;
    unsigned int mh_type;
    const char *mh_file;
    int mh_line;
    unsigned long mh_number;
    struct _MEMHDR *mh_next;
    struct _MEMHDR *mh_prev;
} MEMHDR;

extern int xmlMemInitialized;
extern void xmlInitMemory(void);
extern void xmlGenericError(void *ctx, const char *msg, ...);
extern void *xmlGenericErrorContext;
extern void xmlMemoryDump(void);
extern void xmlMutexLock(void *mutex);
extern void xmlMutexUnlock(void *mutex);
extern void *xmlMemMutex;
extern unsigned long block;
extern size_t debugMemSize;
extern size_t debugMemBlocks;
extern size_t debugMaxMemSize;
extern void debugmem_list_add(MEMHDR *p);
extern unsigned long xmlMemStopAtBlock;
extern void xmlMallocBreakpoint(void);
extern void *xmlMemTraceBlockAt;