#include <stddef.h>

typedef unsigned char xmlChar;

typedef struct _xmlDoc {
    void *intSubset;
    void *extSubset;
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xmlNs {
    xmlChar *prefix;
} xmlNs;

typedef struct _xmlNode {
    xmlChar *name;
    xmlNs *ns;
} xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlAttribute {
    int atype;
} xmlAttribute;
typedef xmlAttribute *xmlAttributePtr;

enum {
    XML_ATTRIBUTE_CDATA
};

xmlChar *xmlBuildQName(const xmlChar *name, const xmlChar *prefix, xmlChar *buffer, int length);
xmlAttributePtr xmlGetDtdAttrDesc(void *dtd, const xmlChar *elem, const xmlChar *name);
xmlChar *xmlStrdup(const xmlChar *cur);
void xmlFree(void *ptr);