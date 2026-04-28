#include <stddef.h>

typedef unsigned short XML_Char;
typedef char ICHAR;

struct ENCODING {
    int minBytesPerChar;
};

struct STRING_POOL {
    void *blocks;
    char *ptr;
    char *end;
    char *start;
};

struct ENTITY {
    int open;
    const char *systemId;
    const char *publicId;
    const char *base;
    const XML_Char *textPtr;
    size_t textLen;
};

struct DTD {
    struct STRING_POOL entityValuePool;
    int keepProcessing;
    int standalone;
    struct {
        void *data;
    } paramEntities;
    int paramEntityRead;
};

struct XML_ParserStruct {
    struct DTD *m_dtd;
    struct {
        int inEntityValue;
    } m_prologState;
    int m_isParamEntity;
    const struct ENCODING *m_encoding;
    const struct ENCODING *m_internalEncoding;
    const char *m_eventPtr;
    void *m_externalEntityRefHandlerArg;
    int (*m_externalEntityRefHandler)(void *, int, const char *, const char *, const char *);
    struct {
        struct STRING_POOL *blocks;
        char *ptr;
        char *end;
    } m_tempPool;
};

typedef struct XML_ParserStruct *XML_Parser;
typedef struct ENCODING ENCODING;
typedef struct DTD DTD;
typedef struct STRING_POOL STRING_POOL;
typedef struct ENTITY ENTITY;

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_NO_MEMORY,
    XML_ERROR_AMPLIFICATION_LIMIT_BREACH,
    XML_ERROR_RECURSIVE_ENTITY_REF,
    XML_ERROR_EXTERNAL_ENTITY_HANDLING,
    XML_ERROR_PARAM_ENTITY_REF,
    XML_ERROR_BAD_CHAR_REF,
    XML_ERROR_INVALID_TOKEN,
    XML_ERROR_UNEXPECTED_STATE
};

enum XML_Account {
    XML_ACCOUNT_ENTITY_EXPANSION
};

enum XML_Bool {
    XML_FALSE,
    XML_TRUE
};

enum {
    XML_TOK_PARAM_ENTITY_REF,
    XML_TOK_NONE,
    XML_TOK_ENTITY_REF,
    XML_TOK_DATA_CHARS,
    XML_TOK_TRAILING_CR,
    XML_TOK_DATA_NEWLINE,
    XML_TOK_CHAR_REF,
    XML_TOK_PARTIAL,
    XML_TOK_INVALID
};

#define XML_ENCODE_MAX 16
#define UNUSED_P(x) (void)(x)

int poolGrow(STRING_POOL *pool);
int XmlEntityValueTok(const ENCODING *enc, const char *ptr, const char *end, const char **next);
int poolAppend(STRING_POOL *pool, const ENCODING *enc, const char *ptr, const char *end);
int XmlCharRefNumber(const ENCODING *enc, const char *ptr);
int XmlEncode(int n, ICHAR *buf);