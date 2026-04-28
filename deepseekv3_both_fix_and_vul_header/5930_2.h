#include <stdlib.h>
#include <string.h>

typedef struct _xmlNode {
    int type;
    struct _xmlNode *next;
} xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlNs {
    struct _xmlNs *next;
    const unsigned char *prefix;
} xmlNs;
typedef xmlNs *xmlNsPtr;

typedef struct _xmlNodeSet {
    int nodeNr;
    int nodeMax;
    xmlNodePtr *nodeTab;
} xmlNodeSet;
typedef xmlNodeSet *xmlNodeSetPtr;

#define XML_NAMESPACE_DECL 1
#define XML_NODESET_DEFAULT 10

extern xmlNodeSetPtr xmlXPathNodeSetCreate(xmlNodePtr val);
extern xmlNodePtr xmlXPathNodeSetDupNs(xmlNodePtr node, xmlNsPtr ns);
extern void xmlXPathErrMemory(void *ctxt, const char *msg);
extern void *xmlMalloc(size_t size);
extern void *xmlRealloc(void *ptr, size_t size);
extern int xmlStrEqual(const unsigned char *str1, const unsigned char *str2);