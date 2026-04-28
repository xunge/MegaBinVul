#include <stdlib.h>

typedef struct _xmlRegParserCtxt {
    const char *cur;
    const char *string;
    void *atom;
    int neg;
} xmlRegParserCtxt;

typedef xmlRegParserCtxt *xmlRegParserCtxtPtr;

#define CUR (ctxt->cur[0])
#define NEXT (ctxt->cur++)
#define NXT(n) (ctxt->cur[(n)])
#define PREV (ctxt->cur[-1])
#define NEXTL(l) (ctxt->cur += (l))
#define CUR_SCHAR(p, l) (*p)
#define ERROR(msg)

typedef struct _xmlRegAtom xmlRegAtom;
typedef xmlRegAtom *xmlRegAtomPtr;

typedef enum {
    XML_REGEXP_CHARVAL
} xmlRegAtomType;

void xmlRegAtomAddRange(xmlRegParserCtxtPtr ctxt, xmlRegAtomPtr atom, int neg,
                        xmlRegAtomType type, int start, int end, void *data);