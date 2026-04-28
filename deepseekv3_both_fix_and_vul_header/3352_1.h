#include <stdio.h>
#include <stdlib.h>

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlEntity xmlEntity;
typedef xmlEntity *xmlEntityPtr;
typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef unsigned char xmlChar;

typedef struct _xmlSAXHandler {
    void (*characters)(void *ctx, const xmlChar *ch, int len);
    void (*reference)(void *ctx, const xmlChar *name);
} xmlSAXHandler;

typedef enum {
    XML_ERR_OK,
    XML_ERR_ENTITY_LOOP,
    XML_ERR_INTERNAL_ERROR,
    XML_ERR_UNDECLARED_ENTITY,
    XML_WAR_UNDECLARED_ENTITY,
    XML_ERR_ENTITY_PE_INTERNAL
} xmlParserErrors;

#define RAW 0
#define NXT(i) 0
#define COPY_BUF(a,b,c,d) 
#define BAD_CAST (const xmlChar *)
#define XML_CHAR_ENCODING_UTF8 0
#define XML_INTERNAL_PREDEFINED_ENTITY 0
#define XML_INTERNAL_GENERAL_ENTITY 0
#define XML_EXTERNAL_GENERAL_PARSED_ENTITY 0
#define XML_PARSE_NOENT 0
#define XML_PARSE_DTDVALID 0
#define XML_PARSE_READER 0
#define XML_TEXT_NODE 0
#define XML_ELEMENT_NODE 0

struct _xmlParserCtxt {
    int charset;
    xmlSAXHandler *sax;
    void *userData;
    int disableSAX;
    int wellFormed;
    int options;
    unsigned long nbentities;
    int depth;
    int replaceEntities;
    void *myDoc;
    xmlNodePtr node;
    int parseMode;
    void *dict;
    int nodemem;
    int nodelen;
};

struct _xmlEntity {
    xmlChar *name;
    int etype;
    xmlChar *content;
    int checked;
    xmlNodePtr children;
    xmlNodePtr last;
    int owner;
    xmlChar *URI;
    xmlChar *ExternalID;
    void *doc;
};

struct _xmlNode {
    int type;
    xmlChar *name;
    xmlNodePtr next;
    xmlNodePtr parent;
    void *doc;
    int extra;
    void *_private;
    xmlNodePtr children;
};

int xmlParseCharRef(xmlParserCtxtPtr ctxt);
xmlEntityPtr xmlParseEntityRef(xmlParserCtxtPtr ctxt);
int xmlParserEntityCheck(xmlParserCtxtPtr ctxt, int a, xmlEntityPtr ent);
void xmlFatalErr(xmlParserCtxtPtr ctxt, int err, const char *msg);
void xmlFatalErrMsgStr(xmlParserCtxtPtr ctxt, int err, const char *msg, const char *str);
void xmlErrMsgStr(xmlParserCtxtPtr ctxt, int err, const char *msg, const char *str);
void xmlFreeNodeList(xmlNodePtr list);
xmlNodePtr xmlDocCopyNode(xmlNodePtr node, void *doc, int extended);
xmlNodePtr xmlAddChild(xmlNodePtr parent, xmlNodePtr cur);
void xmlSetTreeDoc(xmlNodePtr node, void *doc);
void xmlAddChildList(xmlNodePtr parent, xmlNodePtr cur);
size_t xmlStrlen(const xmlChar *str);
int xmlParseBalancedChunkMemoryInternal(xmlParserCtxtPtr ctxt, xmlChar *content, void *user_data, xmlNodePtr *list);
int xmlParseExternalEntityPrivate(void *doc, xmlParserCtxtPtr ctxt, xmlSAXHandler *sax, void *user_data, int depth, xmlChar *URI, xmlChar *ExternalID, xmlNodePtr *list);