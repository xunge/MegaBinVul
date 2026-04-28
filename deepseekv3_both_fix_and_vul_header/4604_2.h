#include <stdio.h>
#include <stdlib.h>

extern int nb_tests;
extern char *testErrors;
extern int testErrorsSize;

typedef struct _xmlParserCtxt {
    struct _xmlDoc *myDoc;
    int wellFormed;
    /* Other members omitted for simplicity */
} xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;

typedef struct _xmlDoc {
    /* Members omitted for simplicity */
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef char xmlChar;

#define ATTRIBUTE_UNUSED
#define LIBXML_HTML_ENABLED
#define XML_PARSE_HTML (1<<0)
#define XML_CHAR_ENCODING_NONE 0

int loadMem(const char *filename, const char **base, int *size);
int compareFileMem(const char *filename, const char *mem, int size);

xmlParserCtxtPtr htmlCreatePushParserCtxt(void *sax, void *user_data, 
                                        const char *chunk, int size,
                                        const char *filename, int encoding);
xmlParserCtxtPtr xmlCreatePushParserCtxt(void *sax, void *user_data,
                                        const char *chunk, int size,
                                        const char *filename);
void xmlCtxtUseOptions(xmlParserCtxtPtr ctxt, int options);
void htmlParseChunk(xmlParserCtxtPtr ctxt, const char *chunk, int size, int terminate);
void xmlParseChunk(xmlParserCtxtPtr ctxt, const char *chunk, int size, int terminate);
void xmlFreeParserCtxt(xmlParserCtxtPtr ctxt);
void xmlFreeDoc(xmlDocPtr doc);
void htmlDocDumpMemory(xmlDocPtr doc, xmlChar **mem, int *size);
void xmlDocDumpMemory(xmlDocPtr doc, xmlChar **mem, int *size);
void xmlFree(void *mem);