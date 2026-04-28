#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;
typedef struct _xmlBuf xmlBuf;
typedef xmlBuf *xmlBufPtr;

#define XML_BUFFER_ALLOC_IMMUTABLE 1
#define XML_BUFFER_ALLOC_BOUNDED 2
#define XML_MAX_TEXT_LENGTH (1024 * 1024)
#define XML_ERR_NO_MEMORY -1

struct _xmlBuf {
    xmlChar *content;
    unsigned int use;
    unsigned int size;
    unsigned int alloc;
    int error;
};

#define CHECK_COMPAT(buf)
#define UPDATE_COMPAT(buf)

int xmlStrlen(const xmlChar *str);
int xmlBufResize(xmlBufPtr buf, unsigned int size);
void xmlBufMemoryError(xmlBufPtr buf, const char *msg);
void xmlGenericError(void *ctx, const char *msg);
extern void *xmlGenericErrorContext;