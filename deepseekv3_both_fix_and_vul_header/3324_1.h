#include <stdint.h>
#include <stdlib.h>

typedef int BOOL;
#define FALSE 0
#define TRUE 1

typedef uint32_t UINT32;

typedef struct _LICENSE_BLOB {
    int type;
} LICENSE_BLOB;

typedef struct _SCOPE_LIST {
    UINT32 count;
    LICENSE_BLOB* array;
} SCOPE_LIST;

typedef struct _wStream {
    size_t (*GetRemainingLength)(struct _wStream*);
    void (*Read_UINT32)(struct _wStream*, UINT32*);
} wStream;

#define BB_SCOPE_BLOB 0

BOOL license_read_binary_blob(wStream* s, LICENSE_BLOB* blob);