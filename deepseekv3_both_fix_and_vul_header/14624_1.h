#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define XMLCALL
#define EXPAT_SAFE_PTR_DIFF(a, b) ((a) - (b))
#define XML_CONTEXT_BYTES 1024
#define INIT_BUFFER_SIZE 1024
#define MALLOC(p, s) malloc(s)
#define FREE(p, m) free(m)

enum XML_Error {
    XML_ERROR_NO_MEMORY,
    XML_ERROR_SUSPENDED,
    XML_ERROR_FINISHED
};

enum XML_Parsing {
    XML_SUSPENDED,
    XML_FINISHED
};

typedef struct XML_ParserStruct {
    int m_errorCode;
    struct {
        enum XML_Parsing parsing;
    } m_parsingStatus;
    char *m_buffer;
    char *m_bufferPtr;
    char *m_bufferEnd;
    char *m_bufferLim;
    char *m_eventPtr;
    char *m_eventEndPtr;
    char *m_positionPtr;
} *XML_Parser;