#include <string.h>

struct _xmlNode {
    void *name;
};

struct _xmlNs {
    void *href;
};

typedef struct _xmlNode xmlNode;
typedef xmlNode *xmlNodePtr;
typedef struct _xmlNs xmlNs;
typedef xmlNs *xmlNsPtr;

#define FALSE 0
#define TRUE 1

xmlNsPtr node_find_ns(xmlNodePtr node);