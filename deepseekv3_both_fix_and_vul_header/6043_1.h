#include <assert.h>
#include <string.h>

typedef struct JsVar JsVar;
typedef struct JsvStringIterator JsvStringIterator;

#define JSET_INTERNALERROR 0

struct JsVar {
    union {
        int integer;
        double floating;
    } varData;
};

struct JsvStringIterator {
    // Implementation details would go here
};

const char *jsvGetConstString(const JsVar *v);
int jsvIsInt(const JsVar *v);
int jsvIsFloat(const JsVar *v);
int jsvHasCharacterData(const JsVar *v);
int jsvIsStringExt(const JsVar *v);
void jsvStringIteratorNewConst(JsvStringIterator *it, const JsVar *v, int pos);
int jsvStringIteratorHasChar(const JsvStringIterator *it);
char jsvStringIteratorGetChar(const JsvStringIterator *it);
void jsvStringIteratorNext(JsvStringIterator *it);
void jsvStringIteratorFree(JsvStringIterator *it);
JsVar *jsvAsString(JsVar *v);
void jsvUnLock(JsVar *v);
void jsExceptionHere(int type, const char *message);
void itostr(int value, char *str, int base);
void ftoa_bounded(double value, char *str, size_t len);