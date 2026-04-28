#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef uint16_t U_16;
typedef uint8_t U_8;
typedef intptr_t IDATA;

#define J9SH_MAXPATH 1024
#define J9_ARE_ANY_BITS_SET(value, bits) ((value) & (bits))
#define PORT_ACCESS_FROM_VMC(thread)
#define Trc_SHR_Assert_False(expr)
#define Trc_SHR_CM_getCachedUTFString_entry(thread, len, str)
#define Trc_SHR_CM_getCachedUTFString_FailedMutex(thread, len, str)
#define Trc_SHR_CM_getCachedUTFString_exit1(thread)
#define Trc_SHR_CM_getCachedUTFString_exit2(thread, utf)
#define Trc_SHR_CM_getCachedUTFString_exit3(thread)
#define Trc_SHR_CM_getCachedUTFString_exit4(thread)

struct J9UTF8 {
    U_16 length;
    U_8 data[1];
};

#define J9UTF8_DATA(utf8) ((utf8)->data)
#define J9UTF8_SET_LENGTH(utf8, len) ((utf8)->length = (len))
#define J9UTF8_LENGTH(utf8) ((utf8)->length)

struct J9VMThread;

struct SH_ScopeManager {
    const struct J9UTF8* (*findScopeForUTF)(struct J9VMThread*, const struct J9UTF8*);
};

struct SH_CacheMap {
    struct {
        int (*hasWriteMutex)(struct J9VMThread*);
        int (*enterReadMutex)(struct J9VMThread*, const char*);
        void (*exitReadMutex)(struct J9VMThread*, const char*);
        int (*enterWriteMutex)(struct J9VMThread*, int, const char*);
        void (*exitWriteMutex)(struct J9VMThread*, const char*);
    }* _ccHead;
    
    int (*runEntryPointChecks)(struct J9VMThread*, void*, void*);
    uint32_t* _runtimeFlags;
    void (*increaseUnstoredBytes)(size_t);
    
    SH_ScopeManager* (*getScopeManager)(struct J9VMThread*);
    const struct J9UTF8* (*addScopeToCache)(struct J9VMThread*, const struct J9UTF8*);
    
    const struct J9UTF8* getCachedUTFString(struct J9VMThread*, const char*, U_16);
};

#define RUNTIME_FLAGS_PREVENT_BLOCK_DATA_UPDATE (1 << 0)

void* j9mem_allocate_memory(size_t size, uint32_t category);
void j9mem_free_memory(void* ptr);

#define J9MEM_CATEGORY_CLASSES 0