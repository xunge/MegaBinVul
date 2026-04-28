#include <stdlib.h>
#include <string.h>

typedef unsigned int xmlChar;
typedef int xmlCharEncoding;

struct _xmlBuf {
    void *content;
    size_t size;
};

struct _xmlParserInputBuffer {
    struct _xmlBuf *buffer;
};

struct _xmlParserInput {
    char *filename;
    struct _xmlParserInputBuffer *buf;
};

typedef struct _xmlParserInput *xmlParserInputPtr;

struct _xmlSAXHandler {
    void (*startElement)(void *ctx, const xmlChar *name, const xmlChar **atts);
    void (*endElement)(void *ctx, const xmlChar *name);
    void (*startElementNs)(void *ctx, const xmlChar *localname, const xmlChar *prefix,
                          const xmlChar *URI, int nb_namespaces, const xmlChar **namespaces,
                          int nb_attributes, int nb_defaulted, const xmlChar **attributes);
    void (*endElementNs)(void *ctx, const xmlChar *localname, const xmlChar *prefix,
                        const xmlChar *URI);
    void (*characters)(void *ctx, const xmlChar *ch, int len);
    void (*ignorableWhitespace)(void *ctx, const xmlChar *ch, int len);
    void (*cdataBlock)(void *ctx, const xmlChar *value, int len);
    int initialized;
};

struct _xmlParserCtxt {
    struct _xmlDict *dict;
    xmlParserInputPtr input;
    void *_private;
    int linenumbers;
    int dictNames;
    int docdict;
    int parseMode;
};

typedef struct _xmlParserCtxt xmlParserCtxt;

struct _xmlDict {
    // Minimal definition
};

struct _xmlTextReader {
    void *doc;
    int entNr;
    int parserFlags;
    int validate;
    struct _xmlParserInputBuffer *input;
    int allocs;
    struct _xmlBuf *buffer;
    struct _xmlSAXHandler *sax;
    void *startElement;
    void *endElement;
    void *startElementNs;
    void *endElementNs;
    void *characters;
    void *cdataBlock;
    int mode;
    void *node;
    void *curnode;
    xmlParserCtxt *ctxt;
    struct _xmlDict *dict;
    int base;
    int cur;
    int xinclude;
    void *xincctxt;
    xmlChar *xinclude_name;
    int in_xinclude;
    void **patternTab;
    int patternNr;
    int patternMax;
};

typedef struct _xmlTextReader xmlTextReader;
typedef xmlTextReader *xmlTextReaderPtr;
typedef struct _xmlParserInputBuffer *xmlParserInputBufferPtr;
typedef struct _xmlSAXHandler xmlSAXHandler;
typedef struct _xmlBuf xmlBuf;
typedef struct _xmlDict xmlDict;
typedef struct _xmlCharEncodingHandler xmlCharEncodingHandler;
typedef xmlCharEncodingHandler *xmlCharEncodingHandlerPtr;

#define XML_PARSE_COMPACT 1
#define XML_TEXTREADER_NOT_VALIDATE 0
#define XML_TEXTREADER_VALIDATE_DTD 1
#define XML_TEXTREADER_INPUT 1
#define XML_TEXTREADER_MODE_INITIAL 0
#define XML_SAX2_MAGIC 1
#define XML_PARSE_XINCLUDE 2
#define XML_PARSE_DTDVALID 4
#define XML_BUFFER_ALLOC_BOUNDED 1
#define XML_CHAR_ENCODING_NONE 0
#define XML_PARSE_READER 1

void xmlFreeParserInputBuffer(xmlParserInputBufferPtr input);
void xmlGenericError(void *ctx, const char *msg);
void *xmlGenericErrorContext;
xmlBuf *xmlBufCreateSize(int size);
void xmlBufSetAllocationScheme(xmlBuf *buf, int scheme);
void *xmlMalloc(size_t size);
void xmlSAXVersion(xmlSAXHandler *sax, int version);
void xmlTextReaderStartElement(void *ctx, const xmlChar *name, const xmlChar **atts);
void xmlTextReaderEndElement(void *ctx, const xmlChar *name);
void xmlTextReaderStartElementNs(void *ctx, const xmlChar *localname, const xmlChar *prefix,
                               const xmlChar *URI, int nb_namespaces, const xmlChar **namespaces,
                               int nb_attributes, int nb_defaulted, const xmlChar **attributes);
void xmlTextReaderEndElementNs(void *ctx, const xmlChar *localname, const xmlChar *prefix,
                             const xmlChar *URI);
void xmlTextReaderCharacters(void *ctx, const xmlChar *ch, int len);
void xmlTextReaderCDataBlock(void *ctx, const xmlChar *value, int len);
int xmlBufUse(xmlBuf *buf);
int xmlParserInputBufferRead(xmlParserInputBufferPtr input, int len);
xmlParserCtxt *xmlCreatePushParserCtxt(xmlSAXHandler *sax, void *user_data,
                                     const char *chunk, int size, const char *filename);
const xmlChar *xmlBufContent(xmlBuf *buf);
void xmlCtxtReset(xmlParserCtxt *ctxt);
xmlParserInputBufferPtr xmlAllocParserInputBuffer(xmlCharEncoding enc);
xmlParserInputPtr xmlNewInputStream(xmlParserCtxt *ctxt);
char *xmlCanonicPath(const xmlChar *path);
void xmlBufResetInput(xmlBuf *buf, xmlParserInputPtr input);
void inputPush(xmlParserCtxt *ctxt, xmlParserInputPtr input);
void xmlDictFree(xmlDict *dict);
xmlDict *xmlDictCreate();
void xmlXIncludeFreeContext(void *ctx);
xmlChar *xmlDictLookup(xmlDict *dict, const xmlChar *name, int len);
void xmlFreePattern(void *pattern);
xmlCharEncodingHandlerPtr xmlFindCharEncodingHandler(const char *name);
int xmlSwitchToEncoding(xmlParserCtxt *ctxt, xmlCharEncodingHandlerPtr handler);
xmlChar *xmlStrdup(const xmlChar *cur);
void xmlCtxtUseOptions(xmlParserCtxt *ctxt, int options);

extern const xmlChar XINCLUDE_NODE[];