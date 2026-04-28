#include <stdlib.h>

typedef struct _xmlParserCtxt xmlParserCtxt;
typedef xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlParserInput xmlParserInput;
typedef xmlParserInput *xmlParserInputPtr;
typedef struct _xmlDict xmlDict;
typedef xmlDict *xmlDictPtr;

#define XML_PARSER_START 0
#define XML_ERR_OK 0
#define XML_CHAR_ENCODING_UTF8 0

#define DICT_FREE(x) if (x) xmlFree((char *)(x))

struct _xmlError {
    int code;
};

typedef void (*xmlHashDeallocator)(void *payload);

struct _xmlParserCtxt {
    xmlDictPtr dict;
    xmlParserInputPtr input;
    int inputNr;
    int *spaceTab;
    int *space;
    int spaceNr;
    int nodeNr;
    void *node;
    int nameNr;
    char *name;
    char *version;
    char *encoding;
    char *directory;
    char *extSubURI;
    char *extSubSystem;
    void *myDoc;
    int standalone;
    int hasExternalSubset;
    int hasPErefs;
    int html;
    int external;
    int instate;
    int token;
    int wellFormed;
    int nsWellFormed;
    int disableSAX;
    int valid;
    int record_info;
    long nbChars;
    long checkIndex;
    int inSubset;
    int errNo;
    int depth;
    int charset;
    void *catalogs;
    int nbentities;
    int sizeentities;
    int sizeentcopy;
    void *node_seq;
    void *attsDefault;
    void *attsSpecial;
    struct _xmlError lastError;
};

void xmlFreeInputStream(xmlParserInputPtr input);
xmlParserInputPtr inputPop(xmlParserCtxtPtr ctxt);
void xmlFreeDoc(void *doc);
void xmlInitNodeInfoSeq(void *seq);
void xmlHashFree(void *table, xmlHashDeallocator f);
void xmlFree(void *ptr);
void xmlResetError(struct _xmlError *err);
void xmlCatalogFreeLocal(void *catalogs);