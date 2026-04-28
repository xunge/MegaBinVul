#include <stdlib.h>
#include <string.h>

typedef struct _xmlAutomataState *xmlAutomataStatePtr;
typedef struct _xmlAutomata *xmlAutomataPtr;
typedef unsigned char xmlChar;
typedef struct _xmlRegAtom xmlRegAtom;
typedef xmlRegAtom *xmlRegAtomPtr;
typedef struct _xmlRegCounter xmlRegCounter;

#define XML_REGEXP_STRING 1
#define XML_REGEXP_QUANT_ONCEONLY 1

struct _xmlRegAtom {
    int type;
    xmlChar *valuep;
    void *data;
    int quant;
    int min;
    int max;
};

struct _xmlRegCounter {
    int min;
    int max;
};

struct _xmlAutomata {
    xmlAutomataStatePtr state;
    xmlRegCounter *counters;
};

xmlRegAtomPtr xmlRegNewAtom(xmlAutomataPtr am, int type);
int xmlRegGetCounter(xmlAutomataPtr am);
xmlAutomataStatePtr xmlRegNewState(xmlAutomataPtr am);
void xmlRegStatePush(xmlAutomataPtr am, xmlAutomataStatePtr state);
void xmlRegStateAddTrans(xmlAutomataPtr am, xmlAutomataStatePtr from, xmlRegAtomPtr atom, xmlAutomataStatePtr to, int counter, int other);
void xmlRegAtomPush(xmlAutomataPtr am, xmlRegAtomPtr atom);
void xmlRegFreeAtom(xmlRegAtomPtr atom);
xmlChar *xmlStrdup(const xmlChar *cur);
void *xmlMallocAtomic(size_t size);