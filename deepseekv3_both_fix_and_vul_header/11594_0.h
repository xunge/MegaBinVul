#include <stdlib.h>

#define SK_MALLOC_ZERO_INITIALIZE 0x1
#define SK_MALLOC_THROW 0x2
#define SK_SUPPORT_LEGACY_MALLOC_PORTING_LAYER

void* throw_on_failure(size_t size, void* p);