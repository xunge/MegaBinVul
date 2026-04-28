#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;
typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;
typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlDict xmlDict;
typedef struct _xmlSAXHandler xmlSAXHandler;
typedef xmlSAXHandler *xmlSAXHandlerPtr;
typedef struct _xmlParserInput xmlParserInput;

#define XML_ERR_ENTITY_LOOP 1
#define XML_DOC_INTERNAL 1
#define XML_PARSE_NODICT 1
#define XML_PARSER_CONTENT 1
#define XML_ERR_NOT_WELL_BALANCED 2
#define XML_ERR_EXTRA_CONTENT 3
#define XML_XML_NAMESPACE (const xmlChar *) "http://www.w3.org/XML/1998/namespace"
#define BAD_CAST (xmlChar *)

struct _xmlNode {
    struct _xmlNode *children;
    struct _xmlNode *parent;
    struct _xmlNode *next;
    xmlDocPtr doc;
};

struct _xmlDoc {
    struct _xmlNode *children;
    xmlDict *dict;
    void *intSubset;
    void *extSubset;
    void *oldNs;
    int properties;
};

struct _xmlParserInput {
    const xmlChar *cur;
};

struct _xmlParserCtxt {
    void *userData;
    xmlSAXHandler *sax;
    xmlDict *dict;
    xmlChar *str_xml;
    xmlChar *str_xmlns;
    xmlChar *str_xml_ns;
    int dictNames;
    xmlDocPtr myDoc;
    int instate;
    int input_id;
    int depth;
    int validate;
    int loadsubset;
    int wellFormed;
    int errNo;
    xmlNodePtr node;
    xmlParserInput *input;
};

struct _xmlSAXHandler {
    // Minimal definition
};

struct _xmlDict {
    // Minimal definition
};

size_t xmlStrlen(const xmlChar *str);
xmlParserCtxtPtr xmlCreateMemoryParserCtxt(char *buffer, int size);
void xmlFreeParserCtxt(xmlParserCtxtPtr ctxt);
xmlDocPtr xmlNewDoc(const xmlChar *version);
void xmlFreeDoc(xmlDocPtr doc);
void xmlDictFree(xmlDict *dict);
void xmlDictReference(xmlDict *dict);
xmlChar *xmlDictLookup(xmlDict *dict, const xmlChar *name, int len);
void xmlCtxtUseOptionsInternal(xmlParserCtxtPtr ctxt, int options, void *unused);
xmlNodePtr xmlNewDocNode(xmlDocPtr doc, void *ns, const xmlChar *name, const xmlChar *content);
void xmlAddChild(xmlNodePtr parent, xmlNodePtr cur);
void nodePush(xmlParserCtxtPtr ctxt, xmlNodePtr node);
void xmlSetTreeDoc(xmlNodePtr node, xmlDocPtr doc);
void xmlSearchNsByHref(xmlDocPtr doc, xmlNodePtr node, const xmlChar *href);
void xmlDetectSAX2(xmlParserCtxtPtr ctxt);
void xmlParseContent(xmlParserCtxtPtr ctxt);
void xmlFatalErr(xmlParserCtxtPtr ctxt, int error, const char *info);

#define RAW (*ctxt->input->cur)
#define NXT(i) (ctxt->input->cur[i])