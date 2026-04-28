#include <stdlib.h>

typedef struct _xmlID xmlID;
typedef xmlID *xmlIDPtr;
typedef struct _xmlIDTable *xmlIDTablePtr;
typedef struct _xmlValidCtxt {
    int vstateNr;
} xmlValidCtxt;
typedef xmlValidCtxt *xmlValidCtxtPtr;
typedef struct _xmlDoc {
    void *ids;
    void *dict;
} xmlDoc;
typedef xmlDoc *xmlDocPtr;
typedef unsigned char xmlChar;
typedef struct _xmlAttr {
    const xmlChar *name;
    void *parent;
    int atype;
} xmlAttr;
typedef xmlAttr *xmlAttrPtr;

struct _xmlID {
    xmlChar *value;
    xmlChar *name;
    xmlDocPtr doc;
    xmlAttrPtr attr;
    int lineno;
};

extern void *xmlMalloc(size_t size);
extern void xmlVErrMemory(xmlValidCtxtPtr ctxt, const char *msg);
extern xmlChar *xmlStrdup(const xmlChar *cur);
extern xmlChar *xmlDictLookup(void *dict, const xmlChar *name, int len);
extern int xmlGetLineNo(void *node);
extern int xmlHashAddEntry(xmlIDTablePtr table, const xmlChar *name, void *userdata);
extern void xmlFreeID(xmlIDPtr id);
extern void xmlErrValidNode(xmlValidCtxtPtr ctxt, void *node, int error, const char *msg, const xmlChar *str1, const xmlChar *str2, const xmlChar *str3);
extern xmlIDTablePtr xmlHashCreateDict(int size, void *dict);

#define XML_ATTRIBUTE_ID 1
#define XML_DTD_ID_REDEFINED 1000
#ifdef LIBXML_VALID_ENABLED
#define LIBXML_VALID_ENABLED
#endif