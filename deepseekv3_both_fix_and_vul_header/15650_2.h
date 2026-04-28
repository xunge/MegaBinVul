#include <stdlib.h>

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_NO_MEMORY,
    /* add other error codes as needed */
};

typedef unsigned char XML_Bool;
typedef int XML_Status;

#define XML_TRUE 1
#define XML_FALSE 0
#define XML_SUSPENDED 1
#define XML_ACCOUNT_ENTITY_EXPANSION 0

typedef struct XML_ParserStruct *XML_Parser;
typedef struct ENTITY ENTITY;
typedef struct OPEN_INTERNAL_ENTITY OPEN_INTERNAL_ENTITY;

struct ENTITY {
    int is_param;
    void *textPtr;
    size_t textLen;
    int processed;
    XML_Bool open;
};

struct OPEN_INTERNAL_ENTITY {
    OPEN_INTERNAL_ENTITY *next;
    ENTITY *entity;
    int startTagLevel;
    XML_Bool betweenDecl;
    void *internalEventPtr;
    void *internalEventEndPtr;
};

struct XML_ParserStruct {
    OPEN_INTERNAL_ENTITY *m_freeInternalEntities;
    OPEN_INTERNAL_ENTITY *m_openInternalEntities;
    int m_tagLevel;
    void *m_internalEncoding;
    struct {
        XML_Status parsing;
    } m_parsingStatus;
    void *m_processor;
};

#define MALLOC(parser, size) malloc(size)

#ifdef XML_DTD
void entityTrackingOnOpen(XML_Parser parser, ENTITY *entity, int line);
void entityTrackingOnClose(XML_Parser parser, ENTITY *entity, int line);
int XmlPrologTok(void *encoding, const char *s, const char *end, const char **nextPtr);
#endif

enum XML_Error doProlog(XML_Parser parser, void *encoding, const char *s, const char *end, 
                  int tok, const char *next, const char **nextPtr, XML_Bool haveMore, 
                  XML_Bool allowClosingDoctype, int accountEntityExpansion);

enum XML_Error doContent(XML_Parser parser, int startTagLevel, void *encoding, 
                   const char *s, const char *end, const char **nextPtr, 
                   XML_Bool haveMore, int accountEntityExpansion);

void internalEntityProcessor(XML_Parser parser, const char *s, const char *end, 
                           const char **nextPtr);