#include <string.h>

typedef struct _xmlNs {
    char *href;
} xmlNs;

typedef struct _xmlNode {
    int type;
    char *name;
    struct _xmlNode *parent;
    struct _xmlNode *prev;
    struct _xmlNode *last;
    xmlNs *ns;
} xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlAttr {
    xmlNode *parent;
} xmlAttr;
typedef xmlAttr *xmlAttrPtr;

typedef struct _xsltTransformContext xsltTransformContext;
typedef xsltTransformContext *xsltTransformContextPtr;
typedef struct _xsltCompMatch xsltCompMatch;
typedef xsltCompMatch *xsltCompMatchPtr;

#define XML_ELEMENT_NODE 1
#define XML_ATTRIBUTE_NODE 2
#define XML_TEXT_NODE 3
#define XML_PI_NODE 7
#define XML_COMMENT_NODE 8
#define XML_DOCUMENT_NODE 9
#define XML_HTML_DOCUMENT_NODE 13
#define XML_DTD_NODE 10
#define XML_XINCLUDE_START 15
#define XML_XINCLUDE_END 16

static int xmlStrEqual(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0;
}

static int xsltTestCompMatchList(xsltTransformContextPtr context, 
                                xmlNodePtr node, 
                                xsltCompMatchPtr pattern) {
    return 0;
}