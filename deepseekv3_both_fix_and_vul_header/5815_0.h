#include <stdlib.h>
#include <string.h>

#define XMLCALL
#define XML_Parser void*
#define XML_SUSPENDED 0
#define XML_FINISHED 1
#define XML_CONTEXT_BYTES 1024
#define INIT_BUFFER_SIZE 1024
#define XML_ERROR_SUSPENDED 0
#define XML_ERROR_FINISHED 1
#define XML_ERROR_NO_MEMORY 2

extern int ps_parsing;
extern int errorCode;
extern char *buffer;
extern char *bufferPtr;
extern char *bufferEnd;
extern char *bufferLim;
extern void *eventPtr;
extern void *eventEndPtr;
extern void *positionPtr;

#define MALLOC malloc
#define FREE free