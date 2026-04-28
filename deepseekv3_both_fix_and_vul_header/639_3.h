#include <stddef.h>

#define PTRCALL

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_UNEXPECTED_STATE
};

enum ParsingStatus {
    XML_SUSPENDED
};

typedef int XML_Bool;
#define XML_FALSE 0
#define XML_TRUE 1

typedef struct ENTITY {
    const char *textPtr;
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

typedef struct XML_ParserStruct {
    OPEN_INTERNAL_ENTITY *m_openInternalEntities;
    OPEN_INTERNAL_ENTITY *m_freeInternalEntities;
    const char *m_internalEncoding;
    const char *m_encoding;
    struct {
        XML_Bool finalBuffer;
        enum ParsingStatus parsing;
    } m_parsingStatus;
    struct XML_ParserStruct *m_parentParser;
    void (*m_processor)(void);
} XML_ParserStruct;

typedef XML_ParserStruct* XML_Parser;

extern enum XML_Error doProlog(XML_Parser parser, const char *encoding, const char *s, const char *end, int tok, const char *next, const char **nextPtr, XML_Bool haveMore, XML_Bool allowClosingDoctype);
extern enum XML_Error doContent(XML_Parser parser, int startTagLevel, const char *encoding, const char *s, const char *end, const char **nextPtr, XML_Bool haveMore);
extern int XmlPrologTok(const char *encoding, const char *s, const char *end, const char **nextPtr);

static enum XML_Error (*prologProcessor)(XML_Parser, const char *, const char *, const char **);
static enum XML_Error (*contentProcessor)(XML_Parser, int, const char *, const char *, const char **, XML_Bool);