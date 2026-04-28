#include <assert.h>
#include <string.h>
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
    // Add necessary fields here
};

enum {
    JSET_INTERNALERROR
};

const char *jsvGetConstString(const JsVar *v);
bool jsvIsInt(const JsVar *v);
bool jsvIsFloat(const JsVar *v);
bool jsvHasCharacterData(const JsVar *v);
bool jsvIsStringExt(const JsVar *v);
void jsvStringIteratorNewConst(JsvStringIterator *it, const JsVar *v, size_t pos);
bool jsvStringIteratorHasChar(const JsvStringIterator *it);
char jsvStringIteratorGetChar(const JsvStringIterator *it);
void jsvStringIteratorNext(JsvStringIterator *it);
void jsvStringIteratorFree(JsvStringIterator *it);
JsVar *jsvAsString(JsVar *v, bool forceCopy);
void jsvUnLock(JsVar *v);
void jsExceptionHere(int type, const char *message);
void itostr(int value, char *str, int base);
void ftoa_bounded(double value, char *str, size_t len);