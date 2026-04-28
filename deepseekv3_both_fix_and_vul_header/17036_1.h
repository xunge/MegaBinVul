#include <stdlib.h>

#define CL_SUCCESS 0
#define CL_EFORMAT 1

typedef void* xmlTextReaderPtr;
typedef unsigned char xmlChar;
#define XML_READER_TYPE_TEXT 3

extern int xmlTextReaderRead(xmlTextReaderPtr reader);
extern int xmlTextReaderNodeType(xmlTextReaderPtr reader);
extern const xmlChar* xmlTextReaderConstValue(xmlTextReaderPtr reader);
extern void cli_dbgmsg(const char *format, ...);