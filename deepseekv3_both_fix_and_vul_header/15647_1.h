#include <stddef.h>

#define PTRCALL

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_UNEXPECTED_STATE,
    XML_ERROR_NO_MEMORY,
    XML_SUSPENDED
};

typedef enum XML_Bool {
    XML_FALSE,
    XML_TRUE
} XML_Bool;

typedef enum {
    XML_ACCOUNT_ENTITY_EXPANSION,
    XML_ACCOUNT_DIRECT
} XML_AccountType;

typedef struct XML_ParserStruct *XML_Parser;

typedef struct ENTITY {
    void *textPtr;
    int textLen;
    int processed;
    XML_Bool open;
    XML_Bool is_param;
} ENTITY;

typedef struct OPEN_INTERNAL_ENTITY {
    ENTITY *entity;
    int startTagLevel;
    struct OPEN_INTERNAL_ENTITY *next;
} OPEN_INTERNAL_ENTITY;

typedef struct {
    int parsing;
    XML_Bool finalBuffer;
} ParsingStatus;

struct XML_ParserStruct {
    OPEN_INTERNAL_ENTITY *m_openInternalEntities;
    OPEN_INTERNAL_ENTITY *m_freeInternalEntities;
    const char *m_internalEncoding;
    const char *m_encoding;
    ParsingStatus m_parsingStatus;
    XML_Parser m_parentParser;
    void *m_processor;
};

static enum XML_Error doContent(XML_Parser parser, int startTagLevel,
                              const char *encoding, const char *s,
                              const char *end, const char **nextPtr,
                              XML_Bool haveMore, XML_AccountType accountType);

static enum XML_Error doProlog(XML_Parser parser, const char *encoding,
                             const char *s, const char *end, int tok,
                             const char *next, const char **nextPtr,
                             XML_Bool haveMore, XML_Bool allowForeignDTD,
                             XML_AccountType accountType);

static int XmlPrologTok(const char *encoding, const char *s,
                       const char *end, const char **nextPtr);

static void entityTrackingOnClose(XML_Parser parser, ENTITY *entity, int line);

static XML_Bool storeRawNames(XML_Parser parser);

extern void *prologProcessor;
extern void *contentProcessor;