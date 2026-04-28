#include <stdlib.h>
#include <string.h>

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlNs {
    struct _xmlNode *next;
    char *prefix;
} xmlNs;
typedef xmlNs *xmlNsPtr;

typedef struct _xmlNodeSet {
    int nodeNr;
    int nodeMax;
    xmlNodePtr *nodeTab;
} xmlNodeSet;
typedef xmlNodeSet *xmlNodeSetPtr;

struct _xmlNode {
    int type;
};

#define XML_NAMESPACE_DECL 1
#define XML_NODESET_DEFAULT 10

static xmlNodeSetPtr xmlXPathNodeSetCreateSize(int size);
static xmlNodeSetPtr xmlXPathNodeSetCreate(xmlNodePtr node);
static void xmlXPathNodeSetFreeNs(xmlNsPtr ns);
static int xmlStrEqual(const char *str1, const char *str2);
static void xmlXPathErrMemory(void *ctxt, const char *msg);
static void *xmlMalloc(size_t size);
static void *xmlRealloc(void *ptr, size_t size);
static xmlNodePtr xmlXPathNodeSetDupNs(xmlNodePtr node, xmlNsPtr ns);