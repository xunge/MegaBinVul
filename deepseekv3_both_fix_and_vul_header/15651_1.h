#include <stddef.h>

typedef unsigned char XML_Bool;
typedef unsigned short XML_Char;

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_ABORTED,
    XML_ERROR_INVALID_TOKEN,
    XML_ERROR_PARTIAL_CHAR,
    XML_ERROR_UNCLOSED_CDATA_SECTION,
    XML_ERROR_UNEXPECTED_STATE,
    XML_ERROR_AMPLIFICATION_LIMIT_BREACH
};

enum XML_Account {
    XML_ACCOUNT_DIRECT,
    XML_ACCOUNT_INDIRECT
};

enum XML_Convert_Result {
    XML_CONVERT_COMPLETED,
    XML_CONVERT_INPUT_INCOMPLETE
};

enum XML_Parsing {
    XML_INITIALIZED,
    XML_PARSING,
    XML_SUSPENDED,
    XML_FINISHED
};

enum XML_Token {
    XML_TOK_CDATA_SECT_CLOSE,
    XML_TOK_DATA_NEWLINE,
    XML_TOK_DATA_CHARS,
    XML_TOK_INVALID,
    XML_TOK_PARTIAL_CHAR,
    XML_TOK_PARTIAL,
    XML_TOK_NONE
};

typedef void (*XML_CharacterDataHandler)(void *userData, const XML_Char *s, int len);

struct encoding {
    /* encoding structure */
};

typedef struct encoding ENCODING;

struct internal_entity {
    const char *internalEventPtr;
    const char *internalEventEndPtr;
};

typedef struct parser *XML_Parser;

struct parser {
    const ENCODING *m_encoding;
    const char *m_eventPtr;
    const char *m_eventEndPtr;
    struct internal_entity *m_openInternalEntities;
    XML_CharacterDataHandler m_characterDataHandler;
    void (*m_endCdataSectionHandler)(void *);
    void (*m_defaultHandler)(void *, const ENCODING *, const char *, const char *);
    void *m_handlerArg;
    char *m_dataBuf;
    char *m_dataBufEnd;
    struct {
        enum XML_Parsing parsing;
    } m_parsingStatus;
};

#define UNUSED_P(x) (void)(x)
#define MUST_CONVERT(enc, s) (0)
#define ICHAR char

int XmlCdataSectionTok(const ENCODING *enc, const char *ptr, const char *end, const char **nextPtr);
void reportDefault(XML_Parser parser, const ENCODING *enc, const char *s, const char *next);
int accountingDiffTolerated(XML_Parser parser, int tok, const char *s, const char *next, int line, enum XML_Account account);
void accountingOnAbort(XML_Parser parser);
enum XML_Convert_Result XmlConvert(const ENCODING *enc, const char **fromP, const char *fromLim, ICHAR **toP, const ICHAR *toLim);