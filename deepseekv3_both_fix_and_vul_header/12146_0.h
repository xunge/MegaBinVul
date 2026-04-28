#include <stdlib.h>

typedef struct _xmlRegParserCtxt xmlRegParserCtxt;
typedef xmlRegParserCtxt *xmlRegParserCtxtPtr;
typedef struct _xmlRegState xmlRegState;
typedef xmlRegState *xmlRegStatePtr;
typedef struct _xmlRegAtom xmlRegAtom;
typedef xmlRegAtom *xmlRegAtomPtr;

#define XML_REGEXP_SUBREG 1
#define XML_REGEXP_QUANT_RANGE 2
#define XML_REGEXP_QUANT_ONCE 3
#define XML_REGEXP_QUANT_OPT 4
#define XML_REGEXP_QUANT_MULT 5
#define XML_REGEXP_QUANT_PLUS 6

#define ERROR(msg)

struct _xmlRegAtom {
    int type;
    int quant;
    int min;
    int max;
    xmlRegStatePtr start;
    xmlRegStatePtr stop;
    xmlRegStatePtr start0;
};

struct _xmlRegState {
    // State fields would be defined here
};

struct _xmlRegParserCtxt {
    xmlRegStatePtr state;
    struct {
        int min;
        int max;
    } *counters;
};

static int xmlRegAtomPush(xmlRegParserCtxtPtr ctxt, xmlRegAtomPtr atom);
static void xmlFAGenerateEpsilonTransition(xmlRegParserCtxtPtr ctxt, xmlRegStatePtr from, xmlRegStatePtr to);
static xmlRegStatePtr xmlRegNewState(xmlRegParserCtxtPtr ctxt);
static void xmlRegStatePush(xmlRegParserCtxtPtr ctxt, xmlRegStatePtr state);
static void xmlRegStateAddTrans(xmlRegParserCtxtPtr ctxt, xmlRegStatePtr from, xmlRegAtomPtr atom, xmlRegStatePtr to, int counter, int count);
static void xmlRegFreeAtom(xmlRegAtomPtr atom);
static xmlRegAtomPtr xmlRegCopyAtom(xmlRegParserCtxtPtr ctxt, xmlRegAtomPtr atom);
static int xmlRegGetCounter(xmlRegParserCtxtPtr ctxt);
static void xmlFAGenerateCountedEpsilonTransition(xmlRegParserCtxtPtr ctxt, xmlRegStatePtr from, xmlRegStatePtr to, int counter);
static void xmlFAGenerateCountedTransition(xmlRegParserCtxtPtr ctxt, xmlRegStatePtr from, xmlRegStatePtr to, int counter);