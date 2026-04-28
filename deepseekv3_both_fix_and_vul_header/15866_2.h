#include <stddef.h>

typedef struct _xmlSchemaValidCtxt xmlSchemaValidCtxt;
typedef xmlSchemaValidCtxt *xmlSchemaValidCtxtPtr;
typedef struct _xmlSchemaParserCtxt xmlSchemaParserCtxt;
typedef xmlSchemaParserCtxt *xmlSchemaParserCtxtPtr;
typedef struct _xmlSchema xmlSchema;
typedef struct _xmlHashTable xmlHashTable;

struct _xmlSchemaConstructionCtxt {
    xmlSchema *mainSchema;
};

struct _xmlSchemaValidCtxt {
    int err;
    int nberrors;
    int depth;
    int skipDepth;
    int xsiAssemble;
    int hasKeyrefs;
    int createIDCNodeTables;
    xmlSchema *schema;
    xmlSchemaParserCtxtPtr pctxt;
};

struct _xmlSchemaParserCtxt {
    int xsiAssemble;
    void *dict;
    struct _xmlSchemaConstructionCtxt *constructor;
    int ownsConstructor;
};

struct _xmlSchema {
    xmlHashTable *schemasImports;
};

int xmlSchemaCreatePCtxtOnVCtxt(xmlSchemaValidCtxtPtr vctxt);
xmlSchema *xmlSchemaNewSchema(xmlSchemaParserCtxtPtr pctxt);
struct _xmlSchemaConstructionCtxt *xmlSchemaConstructionCtxtCreate(void *dict);
void xmlHashScan(xmlHashTable *table, void (*scanner)(void *, void *, void *), void *data);
void xmlSchemaAugmentImportedIDC(void *payload, void *data, void *vctxt);