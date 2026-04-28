#include <stddef.h>

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_UNEXPECTED_STATE,
    XML_ERROR_NO_MEMORY
};

typedef enum XML_Error XML_Error;

typedef unsigned char XML_Bool;
#define XML_FALSE 0
#define XML_TRUE 1

enum XML_Parsing {
    XML_SUSPENDED
};

typedef struct XML_ParserStruct *XML_Parser;

typedef struct {
    int parsing;
    XML_Bool finalBuffer;
} ParsingStatus;

typedef struct {
    const char *textPtr;
    int textLen;
    int processed;
    XML_Bool is_param;
    XML_Bool open;
} ENTITY;

typedef struct OPEN_INTERNAL_ENTITY {
    ENTITY *entity;
    int startTagLevel;
    struct OPEN_INTERNAL_ENTITY *next;
} OPEN_INTERNAL_ENTITY;

typedef struct XML_ParserStruct {
    OPEN_INTERNAL_ENTITY *m_openInternalEntities;
    OPEN_INTERNAL_ENTITY *m_freeInternalEntities;
    const char *m_internalEncoding;
    const char *m_encoding;
    ParsingStatus m_parsingStatus;
    XML_Parser m_parentParser;
    void *m_processor;
} XML_ParserStruct;

#define PTRCALL
#define XML_ACCOUNT_ENTITY_EXPANSION 0
#define XML_ACCOUNT_DIRECT 1

extern enum XML_Error doContent(XML_Parser parser, int startTagLevel, const char *encoding, const char *s, const char *end, const char **nextPtr, XML_Bool haveMore, int account);
extern XML_Bool storeRawNames(XML_Parser parser);
extern void *contentProcessor;