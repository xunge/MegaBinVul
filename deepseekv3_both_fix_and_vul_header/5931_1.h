#include <stdlib.h>
#include <string.h>

typedef struct _xmlNode xmlNode;
typedef struct _xmlNs xmlNs;
typedef struct _xmlNodeSet xmlNodeSet;
typedef xmlNode *xmlNodePtr;
typedef xmlNs *xmlNsPtr;
typedef xmlNodeSet *xmlNodeSetPtr;

#define XML_NAMESPACE_DECL 1
#define XML_ELEMENT_NODE 2
#define XML_NODESET_DEFAULT 10

typedef char xmlChar;

struct _xmlNode {
    int type;
};

struct _xmlNs {
    int type;
    xmlChar *prefix;
    xmlNs *next;
};

struct _xmlNodeSet {
    int nodeNr;
    int nodeMax;
    xmlNodePtr *nodeTab;
};

void xmlXPathErrMemory(void *ctxt, const char *error);
void *xmlMalloc(size_t size);
void *xmlRealloc(void *ptr, size_t size);
xmlNodePtr xmlXPathNodeSetDupNs(xmlNodePtr node, xmlNsPtr ns);
int xmlStrEqual(const xmlChar *str1, const xmlChar *str2);