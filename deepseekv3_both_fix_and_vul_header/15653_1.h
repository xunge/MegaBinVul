#include <stddef.h>

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_ABORTED,
    XML_ERROR_INVALID_TOKEN,
    XML_ERROR_PARTIAL_CHAR,
    XML_ERROR_SYNTAX,
    XML_ERROR_UNEXPECTED_STATE,
    XML_ERROR_AMPLIFICATION_LIMIT_BREACH
};

#define XML_TOK_IGNORE_SECT 1
#define XML_TOK_INVALID 2
#define XML_TOK_PARTIAL_CHAR 3
#define XML_TOK_PARTIAL 4
#define XML_TOK_NONE 5
#define XML_FINISHED 1
#define XML_ACCOUNT_DIRECT 1

typedef int XML_Bool;
typedef struct XML_ParserStruct *XML_Parser;
typedef struct ENCODING ENCODING;

struct XML_ParserStruct {
    const ENCODING *m_encoding;
    const char *m_eventPtr;
    const char *m_eventEndPtr;
    struct {
        int parsing;
    } m_parsingStatus;
    void (*m_defaultHandler)(void);
    struct {
        const char *internalEventPtr;
        const char *internalEventEndPtr;
    } *m_openInternalEntities;
};

int XmlIgnoreSectionTok(const ENCODING *enc, const char *s, const char *end, const char **next);
void reportDefault(XML_Parser parser, const ENCODING *enc, const char *s, const char *next);
XML_Bool accountingDiffTolerated(XML_Parser parser, int tok, const char *s, const char *next, int line, int type);
void accountingOnAbort(XML_Parser parser);