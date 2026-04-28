#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;

extern int xmlStrlen(const xmlChar *str);
extern xmlChar *xmlStrdup(const xmlChar *str);
extern xmlChar *xmlStrndup(const xmlChar *str, int len);
extern void *xmlMalloc(size_t size);
extern void xmlErrMemory(void *ctx, const char *msg);