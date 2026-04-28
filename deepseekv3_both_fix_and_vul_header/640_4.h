#include <stdlib.h>

typedef enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_NO_MEMORY,
    XML_ERROR_SUSPENDED
} XML_Error;

typedef enum XML_Bool {
    XML_FALSE,
    XML_TRUE
} XML_Bool;

typedef enum XML_ParsingStatus {
    XML_SUSPENDED
} XML_ParsingStatus;

typedef struct XML_ParserStruct XML_ParserStruct;
typedef XML_ParserStruct* XML_Parser;

typedef struct ENTITY {
    void *textPtr;
    size_t textLen;
    XML_Bool open;
    int processed;
    XML_Bool is_param;
} ENTITY;

typedef struct OPEN_INTERNAL_ENTITY {
    struct OPEN_INTERNAL_ENTITY *next;
    ENTITY *entity;
    int startTagLevel;
    XML_Bool betweenDecl;
    void *internalEventPtr;
    void *internalEventEndPtr;
} OPEN_INTERNAL_ENTITY;

struct XML_ParserStruct {
    OPEN_INTERNAL_ENTITY *m_freeInternalEntities;
    OPEN_INTERNAL_ENTITY *m_openInternalEntities;
    int m_tagLevel;
    struct {
        XML_ParsingStatus parsing;
    } m_parsingStatus;
    void *m_processor;
    void *m_internalEncoding;
};

#define MALLOC(parser, size) malloc(size)

#ifdef XML_DTD
int XmlPrologTok(void *encoding, const char *start, const char *end, const char **next);
#endif

XML_Error doProlog(XML_Parser parser, void *encoding, const char *start, const char *end, int tok, const char *next, const char **nextPtr, XML_Bool haveMore);
XML_Error doContent(XML_Parser parser, int tagLevel, void *encoding, const char *start, const char *end, const char **nextPtr, XML_Bool haveMore);
XML_Error internalEntityProcessor(XML_Parser parser, const char *start, const char *end, const char **endPtr);