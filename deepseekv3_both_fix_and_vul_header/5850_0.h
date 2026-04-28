#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned char xmlChar;
typedef struct _xmlBuf xmlBuf;
typedef xmlBuf *xmlBufPtr;

#define XML_BUFFER_ALLOC_IMMUTABLE 1
#define XML_BUFFER_ALLOC_BOUNDED 2
#define XML_BUFFER_ALLOC_IO 3
#define XML_BUFFER_ALLOC_DOUBLEIT 4
#define XML_BUFFER_ALLOC_EXACT 5
#define XML_BUFFER_ALLOC_HYBRID 6
#define XML_MAX_TEXT_LENGTH (1024 * 1024)
#define BASE_BUFFER_SIZE 1024

#define CHECK_COMPAT(buf)
#define UPDATE_COMPAT(buf)

struct _xmlBuf {
    xmlChar *content;
    xmlChar *contentIO;
    unsigned int use;
    unsigned int size;
    unsigned int alloc;
    int error;
};

void xmlBufMemoryError(xmlBufPtr buf, const char *msg);
void *xmlMallocAtomic(size_t size);
void *xmlRealloc(void *ptr, size_t size);
void xmlFree(void *ptr);