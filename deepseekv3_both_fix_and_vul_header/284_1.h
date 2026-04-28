#include <stddef.h>

typedef unsigned short XML_Char;
#define ASCII_COLON ':'
#define XML_T(c) c

typedef struct PREFIX {
    XML_Char *name;
} PREFIX;

typedef struct DTD {
    struct {
        XML_Char *start;
        int (*appendChar)(void *, XML_Char);
        XML_Char *(*startFunc)(void *);
        void (*finish)(void *);
        void (*discard)(void *);
    } pool;
    struct {
        void *(*lookup)(void *, void *, XML_Char *, size_t);
    } prefixes;
} DTD;

typedef struct ELEMENT_TYPE {
    XML_Char *name;
    PREFIX *prefix;
} ELEMENT_TYPE;

typedef struct XML_ParserStruct {
    DTD *m_dtd;
} XML_ParserStruct;

typedef XML_ParserStruct *XML_Parser;

static int poolAppendChar(void *pool, XML_Char c);
static void *lookup(void *parser, void *prefixes, XML_Char *str, size_t size);
static XML_Char *poolStart(void *pool);
static void poolFinish(void *pool);
static void poolDiscard(void *pool);