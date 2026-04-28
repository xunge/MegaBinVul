#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;
typedef enum {
    XML_ERR_OK,
    XML_ERR_INTERNAL_ERROR,
    XML_WAR_UNDECLARED_ENTITY,
    XML_ERR_ENTITY_LOOP,
    XML_ERR_NOT_WELL_BALANCED,
    XML_ERR_EXTRA_CONTENT
} xmlParserErrors;

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlSAXHandler xmlSAXHandler;
typedef xmlSAXHandler *xmlSAXHandlerPtr;

typedef enum {
    XML_CHAR_ENCODING_NONE,
    XML_DOC_INTERNAL
} xmlCharEncoding;

typedef enum {
    XML_PARSER_CONTENT
} xmlParserState;

typedef struct {
    int code;
} xmlError;

#define XML_PARSE_HUGE (1 << 19)
#define BAD_CAST (xmlChar *)
#define RAW (ctxt->input->cur[0])
#define NXT(n) (ctxt->input->cur[(n)])
#define CUR_PTR (ctxt->input->cur)
#define CMP5(p,c1,c2,c3,c4,c5) \
    ((p[0] == c1) && (p[1] == c2) && (p[2] == c3) && (p[3] == c4) && (p[4] == c5))
#define IS_BLANK_CH(c) ((c == 0x20) || (c == 0x9) || (c == 0xD) || (c == 0xA))
#define GROW do {} while(0)

struct _xmlParserCtxt {
    int options;
    void *userData;
    void *_private;
    int loadsubset;
    int validate;
    int external;
    int record_info;
    struct {
        int maximum;
        int length;
        void *buffer;
    } node_seq;
    xmlSAXHandlerPtr sax;
    xmlDocPtr myDoc;
    xmlNodePtr node;
    int wellFormed;
    int errNo;
    int nbentities;
    long sizeentities;
    struct {
        xmlChar *base;
        xmlChar *cur;
        xmlChar *end;
        long consumed;
    } *input;
    xmlError lastError;
    xmlParserState instate;
    int depth;
};

struct _xmlDoc {
    xmlChar *URL;
    void *intSubset;
    void *extSubset;
    void *dict;
    int properties;
    xmlNodePtr children;
};

struct _xmlNode {
    xmlNodePtr parent;
    xmlNodePtr next;
    xmlNodePtr children;
    xmlDocPtr doc;
};

xmlParserCtxtPtr xmlCreateEntityParserCtxtInternal(const xmlChar *URL, const xmlChar *ID, void *a, xmlParserCtxtPtr oldctxt);
void xmlDetectSAX2(xmlParserCtxtPtr ctxt);
xmlDocPtr xmlNewDoc(const xmlChar *version);
void xmlFreeParserCtxt(xmlParserCtxtPtr ctxt);
void xmlFreeDoc(xmlDocPtr doc);
xmlNodePtr xmlNewDocNode(xmlDocPtr doc, void *a, const xmlChar *name, const xmlChar *content);
void xmlAddChild(xmlNodePtr parent, xmlNodePtr cur);
void nodePush(xmlParserCtxtPtr ctxt, xmlNodePtr node);
xmlCharEncoding xmlDetectCharEncoding(const xmlChar *start, int len);
void xmlSwitchEncoding(xmlParserCtxtPtr ctxt, xmlCharEncoding enc);
void xmlParseTextDecl(xmlParserCtxtPtr ctxt);
void xmlParseContent(xmlParserCtxtPtr ctxt);
void xmlFatalErr(xmlParserCtxtPtr ctxt, xmlParserErrors error, const char *msg);
void xmlCopyError(const xmlError *from, xmlError *to);
xmlChar *xmlStrdup(const xmlChar *cur);
void xmlDictReference(void *dict);