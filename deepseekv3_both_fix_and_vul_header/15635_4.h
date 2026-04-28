#include <stdlib.h>

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlNs xmlNs;
typedef xmlNs *xmlNsPtr;

typedef struct _xmlDoc {
    xmlNodePtr children;
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xmlEntity xmlEntity;
typedef xmlEntity *xmlEntityPtr;

typedef struct _xmlParserCtxt {
    xmlNodePtr node;
    xmlDocPtr myDoc;
    int nodeNr;
    xmlNodePtr *nodeTab;
    int instate;
    int parseMode;
    int replaceEntities;
} xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;

typedef struct _xmlTextReader {
    xmlParserCtxtPtr ctxt;
    xmlDocPtr doc;
    xmlNodePtr node;
    xmlNodePtr curnode;
    xmlEntityPtr ent;
    int mode;
    int state;
    int depth;
    int preserves;
    int entNr;
    int validate;
    int xinclude;
    int in_xinclude;
    void *xincctxt;
    unsigned long parserFlags;
} xmlTextReader;
typedef xmlTextReader *xmlTextReaderPtr;

typedef enum {
    XML_ELEMENT_NODE,
    XML_ATTRIBUTE_NODE,
    XML_TEXT_NODE,
    XML_CDATA_SECTION_NODE,
    XML_ENTITY_REF_NODE,
    XML_ENTITY_NODE,
    XML_PI_NODE,
    XML_COMMENT_NODE,
    XML_DOCUMENT_NODE,
    XML_DOCUMENT_TYPE_NODE,
    XML_DOCUMENT_FRAG_NODE,
    XML_NOTATION_NODE,
    XML_HTML_DOCUMENT_NODE,
    XML_DTD_NODE,
    XML_ELEMENT_DECL,
    XML_ATTRIBUTE_DECL,
    XML_ENTITY_DECL,
    XML_NAMESPACE_DECL,
    XML_XINCLUDE_START,
    XML_XINCLUDE_END
} xmlElementType;

typedef enum {
    XML_TEXTREADER_START,
    XML_TEXTREADER_ELEMENT,
    XML_TEXTREADER_END,
    XML_TEXTREADER_BACKTRACK,
    XML_TEXTREADER_DONE,
    XML_TEXTREADER_ERROR
} xmlTextReaderState;

typedef enum {
    XML_TEXTREADER_MODE_INITIAL,
    XML_TEXTREADER_MODE_INTERACTIVE,
    XML_TEXTREADER_MODE_EOF,
    XML_TEXTREADER_MODE_ERROR
} xmlTextReaderMode;

typedef enum {
    XML_TEXTREADER_NOT_VALIDATE,
    XML_TEXTREADER_VALIDATE_DTD,
    XML_TEXTREADER_VALIDATE_XSD
} xmlTextReaderValidate;

struct _xmlNode {
    xmlElementType type;
    struct _xmlNode *children;
    struct _xmlNode *last;
    struct _xmlNode *parent;
    struct _xmlNode *next;
    struct _xmlNode *prev;
    struct _xmlDoc *doc;
    int extra;
    char *content;
    xmlNsPtr ns;
};

struct _xmlEntity {
    struct _xmlNode *children;
};

struct _xmlNs {
    char *href;
};

#define NODE_IS_EMPTY      (1 << 0)
#define NODE_IS_PRESERVED  (1 << 1)
#define NODE_IS_SPRESERVED (1 << 2)

#define XML_PARSE_READER (1 << 5)
#define XML_PARSER_EOF 1
#define PARSER_STOPPED(ctxt) (0)

#define XINCLUDE_NS "http://www.w3.org/2001/XInclude"
#define XINCLUDE_OLD_NS "http://www.w3.org/1999/XInclude"

/* Function prototypes */
int xmlTextReaderReadTree(xmlTextReaderPtr reader);
int xmlTextReaderPushData(xmlTextReaderPtr reader);
void xmlUnlinkNode(xmlNodePtr node);
void xmlTextReaderFreeNode(xmlTextReaderPtr reader, xmlNodePtr node);
int xmlParseChunk(xmlParserCtxtPtr ctxt, const char *chunk, int size, int terminate);
xmlNodePtr xmlTextReaderExpand(xmlTextReaderPtr reader);
int xmlTextReaderEntPush(xmlTextReaderPtr reader, xmlNodePtr node);
xmlNodePtr xmlTextReaderEntPop(xmlTextReaderPtr reader);