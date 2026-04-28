#include <string.h>

#define BUFFER_SIZE 1024
unsigned char buffer[BUFFER_SIZE];
typedef char xmlChar;
#define BAD_CAST (xmlChar *)
void *xmlEncodeEntitiesReentrant(void *a, const xmlChar *b);
void xmlGenericError(void *ctx, const char *msg, ...);
void xmlFree(void *ptr);
extern void *xmlGenericErrorContext;