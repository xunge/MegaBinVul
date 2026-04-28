#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;

xmlChar *xmlStrndup(const xmlChar *add, int len);
int xmlStrlen(const xmlChar *str);
void *xmlRealloc(void *ptr, size_t size);
void xmlErrMemory(void *ctx, const char *extra);