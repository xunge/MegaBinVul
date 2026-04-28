#include <stdlib.h>

typedef struct _xmlDoc xmlDoc;
typedef xmlDoc *xmlDocPtr;
typedef struct _xmlAttr xmlAttr;
typedef xmlAttr *xmlAttrPtr;
typedef struct _xmlIDTable xmlIDTable;
typedef xmlIDTable *xmlIDTablePtr;
typedef struct _xmlID xmlID;
typedef xmlID *xmlIDPtr;
typedef unsigned char xmlChar;

struct _xmlAttr {
    int atype;
    void *children;
};

struct _xmlID {
    xmlAttrPtr attr;
};

struct _xmlDoc {
    void *ids;
};

extern xmlChar *xmlNodeListGetString(xmlDocPtr doc, void *node, int line);
extern void *xmlHashLookup(void *table, const xmlChar *name);
extern int xmlHashRemoveEntry(void *table, const xmlChar *name, void (*f)(void *));
extern void xmlFree(void *ptr);
extern void xmlFreeIDTableEntry(void *entry);