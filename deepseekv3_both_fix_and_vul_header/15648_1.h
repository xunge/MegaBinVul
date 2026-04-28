#include <stddef.h>

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_NO_MEMORY,
    XML_ERROR_INVALID_TOKEN,
    XML_ERROR_UNCLOSED_TOKEN,
    XML_ERROR_PARTIAL_CHAR,
    XML_ERROR_JUNK_AFTER_DOC_ELEMENT,
    XML_ERROR_ABORTED,
    XML_ERROR_AMPLIFICATION_LIMIT_BREACH
};

enum XML_Status {
    XML_SUSPENDED,
    XML_FINISHED
};

enum XML_Tok {
    XML_TOK_NONE,
    XML_TOK_PROLOG_S,
    XML_TOK_PI,
    XML_TOK_COMMENT,
    XML_TOK_INVALID,
    XML_TOK_PARTIAL,
    XML_TOK_PARTIAL_CHAR
};

#define XML_TOK_PROLOG_S (-1)
#define PTRCALL
#define XML_DTD
#define XML_ACCOUNT_DIRECT 0

struct XML_ParserStruct {
    void *m_processor;
    const char *m_eventPtr;
    const char *m_eventEndPtr;
    const char *m_encoding;
    struct {
        int parsing;
        int finalBuffer;
    } m_parsingStatus;
    void (*m_defaultHandler)(void);
};

typedef struct XML_ParserStruct *XML_Parser;

int XmlPrologTok(const char *encoding, const char *s, const char *end, const char **next);
int accountingDiffTolerated(XML_Parser parser, int tok, const char *s, const char *next, int line, int direction);
void accountingOnAbort(XML_Parser parser);
void reportDefault(XML_Parser parser, const char *encoding, const char *s, const char *next);
int reportProcessingInstruction(XML_Parser parser, const char *encoding, const char *s, const char *next);
int reportComment(XML_Parser parser, const char *encoding, const char *s, const char *next);