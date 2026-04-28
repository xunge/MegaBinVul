#include <stddef.h>

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_INVALID_TOKEN,
    XML_ERROR_UNCLOSED_TOKEN,
    XML_ERROR_PARTIAL_CHAR,
    XML_ERROR_ABORTED,
    XML_ERROR_SYNTAX,
    XML_ERROR_AMPLIFICATION_LIMIT_BREACH
};

enum XML_Status {
    XML_FINISHED,
    XML_SUSPENDED
};

enum XML_Token {
    XML_TOK_INVALID = -1,
    XML_TOK_PARTIAL = -2,
    XML_TOK_PARTIAL_CHAR = -3,
    XML_TOK_NONE = 0,
    XML_TOK_XML_DECL = 1,
    XML_TOK_BOM = 2,
    XML_TOK_INSTANCE_START = 3
};

struct XML_ParsingStatus {
    enum XML_Status parsing;
    int finalBuffer;
};

struct XML_Encoding {
    /* encoding structure members */
};

struct XML_ParserStruct {
    const char *m_eventPtr;
    const char *m_eventEndPtr;
    const struct XML_Encoding *m_encoding;
    struct XML_ParsingStatus m_parsingStatus;
    enum XML_Error (*m_processor)(struct XML_ParserStruct *, const char *, const char *, const char **);
    /* other members */
};

typedef struct XML_ParserStruct *XML_Parser;

/* Dummy implementations to satisfy linker */
static int XmlPrologTok(const struct XML_Encoding *encoding, const char *s, const char *end, const char **nextPtr) { return 0; }
static enum XML_Error storeEntityValue(XML_Parser parser, const struct XML_Encoding *encoding, const char *s, const char *end, int direct) { return XML_ERROR_NONE; }
static enum XML_Error processXmlDecl(XML_Parser parser, int isGeneralTextEntity, const char *s, const char *next) { return XML_ERROR_NONE; }
static enum XML_Error entityValueProcessor(XML_Parser parser, const char *s, const char *end, const char **nextPtr) { return XML_ERROR_NONE; }
static int accountingDiffTolerated(XML_Parser parser, int tok, const char *s, const char *next, int line, int direct) { return 1; }
static void accountingOnAbort(XML_Parser parser) {}

#define PTRCALL
#define XML_ACCOUNT_DIRECT 0
#ifdef XML_DTD
#define XML_DTD 1
#endif