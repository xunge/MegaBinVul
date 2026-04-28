#include <stddef.h>

#define CL_SUCCESS 0
#define CL_BREAK 1
#define CL_EFORMAT 2
#define CL_TYPE_ANY 0
#define CL_TYPE_GZ 1
#define CL_TYPE_BZ 2
#define CL_TYPE_7Z 3
#define CL_TYPE_XZ 4
#define XAR_CKSUM_NONE 0

typedef struct _xmlTextReader xmlTextReader;
typedef xmlTextReader *xmlTextReaderPtr;
typedef unsigned char xmlChar;
typedef const xmlChar *xmlCharPtr;

#define XML_READER_TYPE_ELEMENT 1
#define XML_READER_TYPE_END_ELEMENT 15

int xar_get_numeric_from_xml_element(xmlTextReaderPtr reader, long *value);
void xar_get_checksum_values(xmlTextReaderPtr reader, unsigned char **cksum, int *hash);
void cli_dbgmsg(const char *format, ...);
int xmlTextReaderRead(xmlTextReaderPtr reader);
const xmlChar *xmlTextReaderConstLocalName(xmlTextReaderPtr reader);
int xmlTextReaderNodeType(xmlTextReaderPtr reader);
int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);
xmlChar *xmlTextReaderGetAttribute(xmlTextReaderPtr reader, const xmlChar *name);
void xmlFree(void *ptr);