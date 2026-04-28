#include <stdlib.h>
#include <string.h>

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlNodeSet xmlNodeSet;
typedef xmlNodeSet *xmlNodeSetPtr;

struct _xmlNodeSet {
    int nodeNr;
    int nodeMax;
    xmlNodePtr *nodeTab;
};

#define XML_NODESET_DEFAULT 10

xmlNodeSetPtr xmlXPathNodeSetCreateSize(int size);
xmlNodeSetPtr xmlXPathNodeSetCreate(xmlNodePtr node);
void *xmlMalloc(size_t size);
void *xmlRealloc(void *ptr, size_t size);
void xmlXPathErrMemory(void *ctxt, const char *msg);