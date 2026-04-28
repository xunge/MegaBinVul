#include <stddef.h>

typedef struct XML_ParserStruct *XML_Parser;
typedef unsigned short XML_Char;

#define XMLCALL
XML_Parser XML_ParserCreate_MM(const XML_Char *encodingName, void *memptsuite, const XML_Char *nameSpaceSeparator);