#include <stddef.h>

typedef unsigned char xmlChar;

#define XML_NAMESPACE_DECL 1
#define XML_ATTRIBUTE_NODE 2
#define XML_TEXT_NODE 3
#define XML_CDATA_SECTION_NODE 4 
#define XML_PI_NODE 5
#define XML_COMMENT_NODE 6
#define XML_BUFFER_ALLOC_BOUNDED 0
#define BAD_CAST (const xmlChar *)

struct _xmlNode {
    int type;
    void *content;
    struct _xmlNode *children;
    struct _xmlNode *next;
};

struct _xmlNs {
    xmlChar *href;
};

struct _xmlAttr {
    struct _xmlNode *children;
};

struct _xmlBuffer;

typedef struct _xmlNode *xmlNodePtr;
typedef struct _xmlNs *xmlNsPtr;
typedef struct _xmlAttr *xmlAttrPtr;
typedef struct _xmlBuffer *xmlBufferPtr;

struct _xmlTextReader {
    xmlNodePtr node;
    xmlNodePtr curnode;
    xmlBufferPtr buffer;
};

typedef struct _xmlTextReader *xmlTextReaderPtr;

extern void *xmlGenericErrorContext;

void xmlGenericError(void *ctx, const char *msg);
xmlBufferPtr xmlBufCreateSize(int size);
void xmlBufSetAllocationScheme(xmlBufferPtr buf, int scheme);
void xmlBufEmpty(xmlBufferPtr buf);
void xmlBufGetNodeContent(xmlBufferPtr buf, xmlNodePtr node);
const xmlChar *xmlBufContent(xmlBufferPtr buf);
void xmlBufFree(xmlBufferPtr buf);