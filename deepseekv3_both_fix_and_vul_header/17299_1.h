#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct JsVar JsVar;
typedef struct JsvStringIterator JsvStringIterator;

struct JsVar {
    union {
        int integer;
        double floating;
    } varData;
};

struct JsvStringIterator {
    // Placeholder for iterator implementation
};

enum {
    JSET_INTERNALERROR
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
JsVar *jsvAsString(JsVar *v, bool b);
void jsvUnLock(JsVar *v);
void jsExceptionHere(int type, const char *msg);
void itostr(int num, char *str, int base);
void ftoa_bounded(double num, char *str, size_t len);