#include <stdlib.h>
#include <string.h>

typedef struct _xmlNode {
    int type;
} xmlNode;
typedef xmlNode *xmlNodePtr;

typedef struct _xmlXPathObject {
    int type;
    void *user;
    int index;
    void *user2;
    int index2;
} xmlXPathObject;
typedef xmlXPathObject *xmlXPathObjectPtr;

#define XPATH_POINT 1
#define XPATH_RANGE 2

void xmlXPtrErrMemory(const char *msg);
void xmlXPtrRangeCheckOrder(xmlXPathObjectPtr obj);
void *xmlMalloc(size_t size);