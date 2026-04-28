#include <stdlib.h>

typedef struct _xmlAutomataState xmlAutomataState;
typedef xmlAutomataState *xmlAutomataStatePtr;
typedef struct _xmlAutomata xmlAutomata;
typedef xmlAutomata *xmlAutomataPtr;
typedef unsigned char xmlChar;

typedef struct _xmlRegAtom xmlRegAtom;
typedef xmlRegAtom *xmlRegAtomPtr;

#define XML_REGEXP_STRING 1

struct _xmlRegAtom {
    int type;
    xmlChar *valuep;
    void *data;
    int min;
    int max;
};

struct _xmlAutomata {
    xmlAutomataStatePtr state;
    struct {
        int min;
        int max;
    } *counters;
};

xmlChar *xmlStrdup(const xmlChar *cur);
xmlRegAtomPtr xmlRegNewAtom(xmlAutomataPtr am, int type);
int xmlRegGetCounter(xmlAutomataPtr am);
xmlAutomataStatePtr xmlRegNewState(xmlAutomataPtr am);
void xmlRegStatePush(xmlAutomataPtr am, xmlAutomataStatePtr state);
void xmlRegStateAddTrans(xmlAutomataPtr am, xmlAutomataStatePtr from, xmlRegAtomPtr atom, xmlAutomataStatePtr to, int counter, int nbTrans);
void xmlRegAtomPush(xmlAutomataPtr am, xmlRegAtomPtr atom);
void xmlFAGenerateEpsilonTransition(xmlAutomataPtr am, xmlAutomataStatePtr from, xmlAutomataStatePtr to);