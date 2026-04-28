#include <stdlib.h>
#include <stdio.h>

typedef struct _xmlDict xmlDict;
typedef xmlDict *xmlDictPtr;

struct _xmlDict {
    unsigned int seed;
    xmlDictPtr subdict;
};

xmlDictPtr xmlDictCreate(void);
void xmlDictReference(xmlDictPtr dict);