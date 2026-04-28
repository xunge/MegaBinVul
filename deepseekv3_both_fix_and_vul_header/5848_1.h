#include <stdio.h>

typedef enum {
    XML_BUFFER_ALLOC_EXACT,
    XML_BUFFER_ALLOC_DOUBLEIT,
    XML_BUFFER_ALLOC_HYBRID,
    XML_BUFFER_ALLOC_IMMUTABLE,
    XML_BUFFER_ALLOC_IO,
    XML_BUFFER_ALLOC_BOUNDED
} xmlBufferAllocationScheme;

struct _xmlBuffer {
    xmlBufferAllocationScheme alloc;
};

typedef struct _xmlBuffer xmlBuffer;
typedef xmlBuffer *xmlBufferPtr;

struct _xmlBuf {
    xmlBufferAllocationScheme alloc;
    int error;
    xmlBufferPtr buffer;
    char *content;
    char *contentIO;
};

typedef struct _xmlBuf xmlBuf;
typedef xmlBuf *xmlBufPtr;

extern void xmlGenericError(void *ctx, const char *msg);
extern void *xmlGenericErrorContext;