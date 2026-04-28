#include <stdlib.h>
#include <string.h>

typedef unsigned short XML_Char;
typedef unsigned char XML_Bool;
typedef int ICHAR;

typedef struct XML_ParserStruct *XML_Parser;

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_NO_MEMORY,
    XML_ERROR_INVALID_TOKEN,
    XML_ERROR_UNCLOSED_TOKEN,
    XML_ERROR_PARTIAL_CHAR,
    XML_ERROR_TAG_MISMATCH,
    XML_ERROR_ASYNC_ENTITY,
    XML_ERROR_BAD_CHAR_REF,
    XML_ERROR_BINARY_ENTITY_REF,
    XML_ERROR_UNDEFINED_ENTITY,
    XML_ERROR_ENTITY_DECLARED_IN_PE,
    XML_ERROR_RECURSIVE_ENTITY_REF,
    XML_ERROR_EXTERNAL_ENTITY_HANDLING,
    XML_ERROR_MISPLACED_XML_PI,
    XML_ERROR_NO_ELEMENTS,
    XML_ERROR_AMPLIFICATION_LIMIT_BREACH,
    XML_ERROR_ABORTED,
    XML_ERROR_FINISHED,
    XML_ERROR_SUSPENDED
};

enum XML_Account {
    XML_ACCOUNT_NONE,
    XML_ACCOUNT_ENTITY_EXPANSION
};

enum XML_Convert_Result {
    XML_CONVERT_COMPLETED,
    XML_CONVERT_INPUT_INCOMPLETE,
    XML_CONVERT_OUTPUT_EXHAUSTED
};

enum XML_Parsing {
    XML_FINISHED,
    XML_SUSPENDED
};

#define XML_T(c) c
#define XML_ENCODE_MAX 4
#define INIT_TAG_BUF_SIZE 1024
#define MUST_CONVERT(enc, s) (0)
#define MALLOC(parser, size) malloc(size)
#define FREE(parser, ptr) free(ptr)
#define REALLOC(parser, ptr, size) realloc(ptr, size)

typedef struct ENCODING {
    int minBytesPerChar;
} ENCODING;

typedef struct DTD {
    struct {
        void *pool;
    } pool;
    void *generalEntities;
    XML_Bool hasParamEntityRefs;
    XML_Bool standalone;
} DTD;

typedef struct ENTITY {
    XML_Bool is_internal;
    XML_Bool open;
    void *notation;
    void *textPtr;
    const XML_Char *name;
    const XML_Char *base;
    const XML_Char *systemId;
    const XML_Char *publicId;
} ENTITY;

typedef struct TAG_NAME {
    XML_Char *str;
    int strLen;
    XML_Char *localPart;
    XML_Char *prefix;
    int uriLen;
} TAG_NAME;

typedef struct TAG {
    char *buf;
    char *bufEnd;
    struct TAG *parent;
    struct BINDING *bindings;
    TAG_NAME name;
    const char *rawName;
    int rawNameLength;
} TAG;

typedef struct BINDING {
    struct BINDING *nextTagBinding;
    struct PREFIX *prefix;
    void *prevPrefixBinding;
} BINDING;

typedef struct PREFIX {
    XML_Char *name;
    BINDING *binding;
} PREFIX;

typedef struct OPEN_INTERNAL_ENTITY {
    const char *internalEventPtr;
    const char *internalEventEndPtr;
} OPEN_INTERNAL_ENTITY;

typedef void (*XML_CharacterDataHandler)(void *userData, const XML_Char *s, int len);

typedef struct XML_ParserStruct {
    const ENCODING *m_encoding;
    DTD *m_dtd;
    const char *m_eventPtr;
    const char *m_eventEndPtr;
    OPEN_INTERNAL_ENTITY *m_openInternalEntities;
    XML_CharacterDataHandler m_characterDataHandler;
    void *m_handlerArg;
    void (*m_defaultHandler)(void *, const char *, int);
    int m_tagLevel;
    TAG *m_tagStack;
    TAG *m_freeTagList;
    BINDING *m_freeBindingList;
    struct {
        int parsing;
    } m_parsingStatus;
    XML_Bool m_defaultExpandInternalEntities;
    void *m_externalEntityRefHandlerArg;
    int (*m_externalEntityRefHandler)(void *, const XML_Char *, const XML_Char *, 
                                     const XML_Char *, const XML_Char *);
    void (*m_startElementHandler)(void *, const XML_Char *, const XML_Char **);
    void (*m_endElementHandler)(void *, const XML_Char *);
    void (*m_startCdataSectionHandler)(void *);
    void (*m_skippedEntityHandler)(void *, const XML_Char *, int);
    void (*m_endNamespaceDeclHandler)(void *, const XML_Char *);
    struct {
        char *buf;
        char *bufEnd;
    } m_tempPool;
    XML_Char *m_dataBuf;
    XML_Char *m_dataBufEnd;
    XML_Bool m_ns;
    XML_Bool m_ns_triplets;
    XML_Char m_namespaceSeparator;
    const XML_Char **m_atts;
    void *m_processor;
} XML_ParserStruct;

enum {
    XML_TOK_TRAILING_CR,
    XML_TOK_NONE,
    XML_TOK_INVALID,
    XML_TOK_PARTIAL,
    XML_TOK_PARTIAL_CHAR,
    XML_TOK_ENTITY_REF,
    XML_TOK_START_TAG_NO_ATTS,
    XML_TOK_START_TAG_WITH_ATTS,
    XML_TOK_EMPTY_ELEMENT_NO_ATTS,
    XML_TOK_EMPTY_ELEMENT_WITH_ATTS,
    XML_TOK_END_TAG,
    XML_TOK_CHAR_REF,
    XML_TOK_XML_DECL,
    XML_TOK_DATA_NEWLINE,
    XML_TOK_CDATA_SECT_OPEN,
    XML_TOK_TRAILING_RSQB,
    XML_TOK_DATA_CHARS,
    XML_TOK_PI,
    XML_TOK_COMMENT
};

#define XML_FALSE 0
#define XML_TRUE 1

/* Dummy function implementations to satisfy linker */
static int XmlContentTok(const ENCODING *enc, const char *s, const char *end, const char **next) { return 0; }
static int XmlNameLength(const ENCODING *enc, const char *s) { return 0; }
static int XmlCharRefNumber(const ENCODING *enc, const char *s) { return 0; }
static int XmlEncode(int n, ICHAR *buf) { return 0; }
static enum XML_Convert_Result XmlConvert(const ENCODING *enc, const char **fromPtr, const char *fromEnd, ICHAR **toPtr, const ICHAR *toEnd) { return XML_CONVERT_COMPLETED; }
static XML_Char XmlPredefinedEntityName(const ENCODING *enc, const char *s, const char *end) { return 0; }
static enum XML_Error processInternalEntity(XML_Parser parser, ENTITY *entity, XML_Bool betweenDecl) { return XML_ERROR_NONE; }
static enum XML_Error epilogProcessor(XML_Parser parser, const char *s, const char *end, const char **nextPtr) { return XML_ERROR_NONE; }
static enum XML_Error cdataSectionProcessor(XML_Parser parser, const char *s, const char *end, const char **nextPtr) { return XML_ERROR_NONE; }
static enum XML_Error doCdataSection(XML_Parser parser, const ENCODING *enc, const char **nextPtr, const char *end, const char **nextEndPtr, XML_Bool haveMore, enum XML_Account account) { return XML_ERROR_NONE; }
static XML_Bool reportProcessingInstruction(XML_Parser parser, const ENCODING *enc, const char *start, const char *end) { return XML_TRUE; }
static XML_Bool reportComment(XML_Parser parser, const ENCODING *enc, const char *start, const char *end) { return XML_TRUE; }
static void reportDefault(XML_Parser parser, const ENCODING *enc, const char *start, const char *end) {}
static enum XML_Error storeAtts(XML_Parser parser, const ENCODING *enc, const char *s, TAG_NAME *tagName, BINDING **bindings, enum XML_Account account) { return XML_ERROR_NONE; }
static void freeBindings(XML_Parser parser, BINDING *bindings) {}
static const XML_Char *getContext(XML_Parser parser) { return NULL; }
static void *lookup(XML_Parser parser, void *table, const XML_Char *name, int len) { return NULL; }
static void accountingOnAbort(XML_Parser parser) {}
static XML_Bool accountingDiffTolerated(XML_Parser parser, int tok, const char *s, const char *accountAfter, int line, enum XML_Account account) { return XML_TRUE; }
static const XML_Char *poolStoreString(void *pool, const ENCODING *enc, const char *ptr, const char *end) { return NULL; }
static void poolDiscard(void *pool) {}
static void poolFinish(void *pool) {}
static void poolClear(void *pool) {}