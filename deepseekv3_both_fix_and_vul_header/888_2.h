#include <stddef.h>
#include <string.h>

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xsltTransformContext xsltTransformContext;
typedef xsltTransformContext *xsltTransformContextPtr;
typedef struct _xmlHashTable xmlHashTable;
typedef xmlHashTable *xmlHashTablePtr;
typedef unsigned int xmlDictPtr;
typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;
typedef struct _xmlNs xmlNs;

#define XML_TEXT_NODE 1
#define XML_CDATA_SECTION_NODE 2
#define XML_ELEMENT_NODE 3
#define XSLT_OUTPUT_XML 4
#define XSLT_TRACE_COPY_TEXT 5
#define XSLT_STATE_STOPPED 6

extern void *xsltGenericDebugContext;
extern const char *xmlStringTextNoenc;

struct _xmlNode {
    int type;
    const char *name;
    char *content;
    struct _xmlNode *children;
    struct _xmlNode *last;
    struct _xmlDoc *doc;
    struct _xmlNs *ns;
};

struct _xmlDoc {
    xmlDictPtr dict;
};

struct _xmlNs {
    const char *href;
};

struct _xsltStyle {
    xmlHashTablePtr cdataSection;
};

struct _xsltTransformContext {
    struct _xsltStyle *style;
    int type;
    char *lasttext;
    unsigned int lasttsize;
    unsigned int lasttuse;
    xmlDictPtr dict;
    xmlDocPtr output;
    int state;
};

#define WITH_XSLT_DEBUG_PROCESS
#define XSLT_TRACE(ctx, lvl, msg)

xmlNodePtr xsltAddTextString(xsltTransformContextPtr ctxt, xmlNodePtr target, const char *content, int len);
xmlNodePtr xmlNewCDataBlock(xmlDocPtr doc, const char *content, unsigned int len);
xmlNodePtr xmlNewTextLen(const char *content, int len);
char *xmlStrdup(const char *cur);
size_t xmlStrlen(const char *str);
int xmlDictOwns(xmlDictPtr dict, const char *str);
xmlNodePtr xsltAddChild(xmlNodePtr parent, xmlNodePtr cur);
void xsltTransformError(xsltTransformContextPtr ctxt, xmlNodePtr node, xmlNodePtr inst, const char *message, ...);
void *xmlHashLookup2(xmlHashTablePtr table, const char *name, const char *name2);