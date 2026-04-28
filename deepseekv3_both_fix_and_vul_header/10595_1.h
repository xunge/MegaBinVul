#include <stdint.h>

typedef uint32_t guint32;

#define DOFOBJECTID_MAX_CLASS_SIZE 0

typedef struct {
    guint32 len;
    void* oid;
} *DOFObjectID;

extern int OALMarshal_UncompressValue(int max_size, guint32* size, void* oid);