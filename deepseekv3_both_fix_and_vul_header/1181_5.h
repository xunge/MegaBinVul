#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

typedef struct XML_Content XML_Content;
typedef struct DTD DTD;
typedef struct XML_Parser *XML_Parser;
typedef unsigned short XML_Char;

struct XML_Parser {
    DTD *m_dtd;
};

struct XML_Content {
    int type;
    int quant;
    XML_Char *name;
    unsigned int numchildren;
    XML_Content *children;
};

struct DTD {
    size_t scaffCount;
    size_t contentStringLen;
    struct {
        int type;
        int quant;
        XML_Char *name;
        unsigned int childcnt;
        int firstchild;
        int nextsib;
    } *scaffold;
};

#define MALLOC(parser, size) malloc(size)

enum {
    XML_CTYPE_NAME
};

static void build_node(XML_Parser parser, int node, XML_Content *dest, XML_Content **cpos, XML_Char **str);