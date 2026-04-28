#include <stdlib.h>
#include <string.h>

struct _xmlNode {
    int type;
    void *name;
    struct _xmlNode *next;
};

struct _xmlNs {
    struct _xmlNode *next;
};

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xmlNs xmlNs;
typedef xmlNs *xmlNsPtr;

typedef struct _xmlNodeSet {
    int nodeNr;
    int nodeMax;
    xmlNodePtr *nodeTab;
} xmlNodeSet, *xmlNodeSetPtr;

#define XML_NODESET_DEFAULT 10
#define XML_ELEMENT_NODE 1
#define XML_NAMESPACE_DECL 18

extern void *xmlMalloc(size_t size);
extern void *xmlRealloc(void *ptr, size_t size);
extern void xmlXPathErrMemory(void *ctxt, const char *msg);
extern xmlNodePtr xmlXPathNodeSetDupNs(xmlNodePtr node, xmlNsPtr ns);