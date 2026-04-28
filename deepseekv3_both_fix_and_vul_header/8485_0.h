#include <stdlib.h>
#include <string.h>

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xmlXPathObject xmlXPathObject;
typedef xmlXPathObject *xmlXPathObjectPtr;
typedef struct _xmlNodeSet xmlNodeSet;

#define XPATH_POINT 1
#define XPATH_RANGE 2
#define XPATH_NODESET 3

struct _xmlXPathObject {
    int type;
    void *user;
    int index;
    void *user2;
    int index2;
    xmlNodeSet *nodesetval;
};

struct _xmlNodeSet {
    int nodeNr;
    xmlNodePtr *nodeTab;
};

void xmlXPtrErrMemory(const char *msg);
void xmlXPtrRangeCheckOrder(xmlXPathObjectPtr obj);
void *xmlMalloc(size_t size);
#define STRANGE