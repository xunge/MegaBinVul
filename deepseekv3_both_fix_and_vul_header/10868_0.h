#include <stddef.h>

typedef struct SWF_ACTION SWF_ACTION;
typedef struct SWF_ACTIONCONSTANTPOOL SWF_ACTIONCONSTANTPOOL;

struct SWF_ACTION {
    void *ConstantPool;
    size_t Count;
};

extern SWF_ACTION *sact;
extern void *pool;
extern size_t poolcounter;

#define OUT_BEGIN(x)