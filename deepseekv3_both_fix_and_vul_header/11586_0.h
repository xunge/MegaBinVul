#include <stdlib.h>

#define SK_MALLOC_ZERO_INITIALIZE 0x01
#define SK_MALLOC_THROW 0x02
#define SK_SUPPORT_LEGACY_MALLOC_PORTING_LAYER

void* moz_xmalloc(size_t size);
void* moz_xcalloc(size_t nmemb, size_t size);