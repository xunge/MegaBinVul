#include <string.h>

struct _xmlAttr {
    char *name;
    // other members omitted
};

struct _xmlNs {
    char *href;
    // other members omitted
};

typedef struct _xmlAttr xmlAttr;
typedef xmlAttr *xmlAttrPtr;
typedef struct _xmlNs xmlNs;
typedef xmlNs *xmlNsPtr;

#define FALSE 0
#define TRUE 1

xmlNsPtr attr_find_ns(xmlAttrPtr node);