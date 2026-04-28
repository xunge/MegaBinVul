#include <stddef.h>

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_UNCLOSED_TOKEN,
    XML_ERROR_PARTIAL_CHAR,
    XML_ERROR_AMPLIFICATION_LIMIT_BREACH
};

enum XML_AccountDirect {
    XML_ACCOUNT_DIRECT
};

#define PTRCALL
#define XML_DTD
#define XML_GE 1

struct XML_ParsingStatus {
    int finalBuffer;
};

typedef struct XML_ParserStruct *XML_Parser;
struct XML_ParserStruct {
    const char *m_encoding;
    struct XML_ParsingStatus m_parsingStatus;
    const char *m_eventPtr;
    enum XML_Error (*m_processor)(XML_Parser, const char *, const char *, const char **);
};

int XmlContentTok(const char *encoding, const char *start, const char *end, const char **next);
int accountingDiffTolerated(XML_Parser parser, int tok, const char *start, const char *next, int line, enum XML_AccountDirect direct);
void accountingOnAbort(XML_Parser parser);
enum XML_Error externalEntityInitProcessor3(XML_Parser parser, const char *start, const char *end, const char **endPtr);

#define XML_TOK_BOM 1
#define XML_TOK_PARTIAL 2
#define XML_TOK_PARTIAL_CHAR 3