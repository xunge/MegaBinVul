#include <stdlib.h>
#include <string.h>

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xmlXPathObject xmlXPathObject;
typedef xmlXPathObject *xmlXPathObjectPtr;

struct _xmlXPathObject {
    int type;
    void *user;
    int index;
    void *user2;
    int index2;
};

#define XPATH_POINT 1
#define XPATH_RANGE 2

void xmlXPtrErrMemory(const char *msg);
void xmlXPtrRangeCheckOrder(xmlXPathObjectPtr obj);
void *xmlMalloc(size_t size);