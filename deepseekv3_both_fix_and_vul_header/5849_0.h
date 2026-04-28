#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;
typedef struct _xmlBuf xmlBuf;
typedef xmlBuf *xmlBufPtr;

struct _xmlBuf {
    xmlChar *content;
    xmlChar *contentIO;
    size_t size;
    size_t use;
    int error;
    int alloc;
};

#define XML_BUFFER_ALLOC_IMMUTABLE 1
#define XML_BUFFER_ALLOC_BOUNDED 2
#define XML_BUFFER_ALLOC_IO 3
#define XML_MAX_TEXT_LENGTH (1024 * 1024)

#define CHECK_COMPAT(buf)
#define UPDATE_COMPAT(buf)

void xmlBufMemoryError(xmlBufPtr buf, const char *msg);
void *xmlRealloc(void *ptr, size_t size);