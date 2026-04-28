#include <stddef.h>

enum XML_Error {
    XML_ERROR_NONE,
    XML_ERROR_NO_MEMORY,
    XML_ERROR_SYNTAX,
    XML_ERROR_NO_ELEMENTS,
    XML_ERROR_INVALID_TOKEN,
    XML_ERROR_UNCLOSED_TOKEN,
    XML_ERROR_PARTIAL_CHAR,
    XML_ERROR_TAG_MISMATCH,
    XML_ERROR_DUPLICATE_ATTRIBUTE,
    XML_ERROR_JUNK_AFTER_DOC_ELEMENT,
    XML_ERROR_PARAM_ENTITY_REF,
    XML_ERROR_UNDEFINED_ENTITY,
    XML_ERROR_RECURSIVE_ENTITY_REF,
    XML_ERROR_ASYNC_ENTITY,
    XML_ERROR_BAD_CHAR_REF,
    XML_ERROR_BINARY_ENTITY_REF,
    XML_ERROR_ATTRIBUTE_EXTERNAL_ENTITY_REF,
    XML_ERROR_MISPLACED_XML_PI,
    XML_ERROR_UNKNOWN_ENCODING,
    XML_ERROR_INCORRECT_ENCODING,
    XML_ERROR_UNCLOSED_CDATA_SECTION,
    XML_ERROR_EXTERNAL_ENTITY_HANDLING
};

typedef int XML_Bool;
#define XML_TRUE 1
#define PTRCALL

typedef struct XML_ParserStruct *XML_Parser;

struct XML_ParserStruct {
    const struct {
        int finalBuffer;
    } m_parsingStatus;
    const void *m_encoding;
};

int XmlPrologTok(const void *encoding, const char *s, const char *end, const char **next);
enum XML_Error doProlog(XML_Parser parser, const void *encoding, const char *s, const char *end, int tok, const char *next, const char **nextPtr, XML_Bool more, ...);