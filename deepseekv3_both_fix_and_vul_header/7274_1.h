#include <stdlib.h>

typedef struct _xmlValidCtxt xmlValidCtxt;
typedef xmlValidCtxt *xmlValidCtxtPtr;
typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;
typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef unsigned char xmlChar;
typedef struct _xmlNs xmlNs;
typedef struct _xmlAttribute xmlAttribute;
typedef xmlAttribute *xmlAttributePtr;

#define XML_ATTRIBUTE_CDATA 1
#define XML_DTD_NOT_STANDALONE 0x1000

struct _xmlNs {
    xmlChar *prefix;
    void *other_data;
};

struct _xmlNode {
    xmlChar *name;
    xmlNs *ns;
    void *other_data;
};

struct _xmlDoc {
    void *intSubset;
    void *extSubset;
    int standalone;
    void *other_data;
};

struct _xmlAttribute {
    int atype;
    void *other_data;
};

struct _xmlValidCtxt {
    int valid;
    void *other_data;
};

xmlChar *xmlBuildQName(const xmlChar *name, const xmlChar *prefix, xmlChar *buffer, int buffer_len);
xmlAttributePtr xmlGetDtdAttrDesc(void *dtd, const xmlChar *elem, const xmlChar *name);
void xmlFree(void *ptr);
xmlChar *xmlStrdup(const xmlChar *cur);
int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);
void xmlErrValidNode(xmlValidCtxtPtr ctxt, xmlNodePtr node, int error, const char *msg, ...);