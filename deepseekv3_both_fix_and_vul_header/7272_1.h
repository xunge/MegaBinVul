#include <stdlib.h>
#include <string.h>

typedef unsigned char xmlChar;

typedef struct _xmlRef {
    xmlChar *value;
    xmlChar *name;
    struct _xmlAttr *attr;
    int lineno;
} xmlRef;
typedef xmlRef *xmlRefPtr;

typedef struct _xmlValidCtxt {
    int vstateNr;
} xmlValidCtxt;
typedef xmlValidCtxt *xmlValidCtxtPtr;

typedef struct _xmlDoc {
    void *refs;
    void *dict;
} xmlDoc;
typedef xmlDoc *xmlDocPtr;

typedef struct _xmlAttr {
    xmlChar *name;
    void *parent;
} xmlAttr;
typedef xmlAttr *xmlAttrPtr;

typedef struct _xmlHashTable xmlHashTable;
typedef xmlHashTable *xmlRefTablePtr;

typedef struct _xmlList xmlList;
typedef xmlList *xmlListPtr;

#define XML_ERR_INTERNAL_ERROR 1

void *xmlMalloc(size_t size);
void xmlFree(void *ptr);
void xmlVErrMemory(xmlValidCtxtPtr ctxt, const char *msg);
void xmlErrValid(xmlValidCtxtPtr ctxt, int error, const char *msg, const char *extra);
xmlChar *xmlStrdup(const xmlChar *cur);
int xmlGetLineNo(void *node);
xmlHashTable *xmlHashCreateDict(int size, void *dict);
void *xmlHashLookup(xmlHashTable *table, const xmlChar *name);
int xmlHashAddEntry(xmlHashTable *table, const xmlChar *name, void *userdata);
xmlListPtr xmlListCreate(void (*deallocator)(void *), int (*compare)(const void *, const void *));
void xmlListDelete(xmlListPtr l);
int xmlListAppend(xmlListPtr l, void *data);
void xmlFreeRef(void *ref);
int xmlDummyCompare(const void *x, const void *y);