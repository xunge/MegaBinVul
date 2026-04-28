#include <stddef.h>

typedef unsigned short XML_Char;

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_AMPLIFICATION_LIMIT_BREACH,
    XML_ERROR_TEXT_DECL,
    XML_ERROR_XML_DECL,
    XML_ERROR_NO_MEMORY,
    XML_ERROR_INCORRECT_ENCODING,
    XML_ERROR_UNKNOWN_ENCODING
};

typedef struct ENCODING {
    int minBytesPerChar;
} ENCODING;

typedef struct DTD {
    int standalone;
} DTD;

typedef struct Pool {
    XML_Char* (*poolStoreString)(struct Pool*, const ENCODING*, const char*, const char*);
    void (*poolFinish)(struct Pool*);
    void (*poolClear)(struct Pool*);
} Pool;

typedef struct XML_ParserStruct {
    int m_ns;
    const ENCODING *m_encoding;
    const char *m_eventPtr;
    DTD *m_dtd;
    void (*m_xmlDeclHandler)(void *, const XML_Char *, const XML_Char *, int);
    void *m_handlerArg;
    void (*m_defaultHandler)(void *, const char *, const char *);
    const char *m_protocolEncodingName;
    Pool m_temp2Pool;
    int m_paramEntityParsing;
} *XML_Parser;

#define XML_TRUE 1
#define XML_FALSE 0

enum {
    XML_TOK_XML_DECL,
    XML_PARAM_ENTITY_PARSING_UNLESS_STANDALONE,
    XML_PARAM_ENTITY_PARSING_NEVER,
    XML_ACCOUNT_DIRECT
};

XML_Char* poolStoreString(Pool*, const ENCODING*, const char*, const char*);
void poolFinish(Pool*);
void poolClear(Pool*);
int XmlParseXmlDeclNS(int, const ENCODING*, const char*, const char*, const char**, const char**, const char**, const char**, const ENCODING**, int*);
int XmlParseXmlDecl(int, const ENCODING*, const char*, const char*, const char**, const char**, const char**, const char**, const ENCODING**, int*);
int XmlNameLength(const ENCODING*, const char*);
void reportDefault(XML_Parser, const ENCODING*, const char*, const char*);
enum XML_Error handleUnknownEncoding(XML_Parser, const XML_Char*);
int accountingDiffTolerated(XML_Parser, int, const char*, const char*, int, int);
void accountingOnAbort(XML_Parser*);