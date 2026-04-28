#include <stdlib.h>

struct _xmlParserCtxt {
    void *dict;
    struct _xmlSAXHandler *sax;
    int maxatts;
    void *atts;
    struct _xmlParserInput **inputTab;
    int inputMax;
    int inputNr;
    struct _xmlParserInput *input;
    const char *version;
    const char *encoding;
    int standalone;
    int hasExternalSubset;
    int hasPErefs;
    int html;
    int external;
    int instate;
    int token;
    char *directory;
    struct _xmlNode **nodeTab;
    int nodeMax;
    int nodeNr;
    struct _xmlNode *node;
    const unsigned char **nameTab;
    int nameMax;
    int nameNr;
    const unsigned char *name;
    int *spaceTab;
    int spaceMax;
    int spaceNr;
    int *space;
    void *userData;
    void *myDoc;
    int wellFormed;
    int nsWellFormed;
    int valid;
    int loadsubset;
    int validate;
    int pedantic;
    int linenumbers;
    int keepBlanks;
    struct {
        int finishDtd;
        void *userData;
        void (*error)(void *, const char *, ...);
        void (*warning)(void *, const char *, ...);
        int nodeMax;
    } vctxt;
    int replaceEntities;
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
    int input_id;
    void *node_seq;
};

struct _xmlSAXHandler {
    void (*ignorableWhitespace)(void*, const unsigned char*, int);
};

typedef struct _xmlParserCtxt *xmlParserCtxtPtr;
typedef struct _xmlParserInput *xmlParserInputPtr;
typedef struct _xmlSAXHandler xmlSAXHandler;
typedef struct _xmlNode *xmlNodePtr;
typedef unsigned char xmlChar;

#define XML_MAX_DICTIONARY_LIMIT 0
#define XML_PARSER_START 0
#define XML_CTXT_FINISH_DTD_0 0
#define XML_ERR_OK 0
#define XML_CHAR_ENCODING_UTF8 0

extern void xmlDefaultSAXHandlerInit(void);
extern void xmlErrInternal(void*, const char*, void*);
extern void xmlErrMemory(void*, const char*);
extern void* xmlDictCreate(void);
extern void xmlDictSetLimit(void*, int);
extern void* xmlMalloc(size_t);
extern void xmlSAXVersion(xmlSAXHandler*, int);
extern xmlParserInputPtr inputPop(xmlParserCtxtPtr);
extern void xmlFreeInputStream(xmlParserInputPtr);
extern int xmlLoadExtDtdDefaultValue;
extern int xmlDoValidityCheckingDefaultValue;
extern int xmlPedanticParserDefaultValue;
extern int xmlLineNumbersDefaultValue;
extern int xmlKeepBlanksDefaultValue;
extern void xmlSAX2IgnorableWhitespace(void*, const xmlChar*, int);
extern void xmlParserValidityError(void*, const char*, ...);
extern void xmlParserValidityWarning(void*, const char*, ...);
extern int xmlGetWarningsDefaultValue;
extern int xmlSubstituteEntitiesDefaultValue;
extern void xmlInitNodeInfoSeq(void*);