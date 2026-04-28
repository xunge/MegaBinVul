#include <stddef.h>

#define XAR_CKSUM_NONE 0
#define XAR_CKSUM_SHA1 1
#define XAR_CKSUM_MD5 2
#define XAR_CKSUM_OTHER 3

#define CLI_HASHLEN_SHA1 20
#define CLI_HASHLEN_MD5 16

#define XML_READER_TYPE_TEXT 3

typedef struct _xmlTextReader xmlTextReader;
typedef xmlTextReader *xmlTextReaderPtr;
typedef unsigned char xmlChar;

extern int xmlTextReaderGetAttribute(xmlTextReaderPtr, const xmlChar*);
extern void cli_dbgmsg(const char*, ...);
extern int xmlStrcasecmp(const xmlChar*, const xmlChar*);
extern void xmlFree(void*);
extern int xmlTextReaderRead(xmlTextReaderPtr);
extern int xmlTextReaderNodeType(xmlTextReaderPtr);
extern const xmlChar* xmlTextReaderConstValue(xmlTextReaderPtr);
extern int xmlStrlen(const xmlChar*);
extern xmlChar* xmlStrdup(const xmlChar*);