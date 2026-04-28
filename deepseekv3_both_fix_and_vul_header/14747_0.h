#include <stdlib.h>

#define kMaxNativeFds 1024
#define kMaxNativeInts 1024

typedef struct native_handle {
    int version;
    int numFds;
    int numInts;
} native_handle_t;