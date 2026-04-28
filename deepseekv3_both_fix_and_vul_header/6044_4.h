#include <assert.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct JsVar JsVar;

struct JsvStringIterator {
    const JsVar *var;
    size_t pos;
};
typedef struct JsvStringIterator JsvStringIterator;

bool jsvHasCharacterData(const JsVar *v);
void jsvStringIteratorNewConst(JsvStringIterator *it, const JsVar *v, size_t startChar);
bool jsvStringIteratorHasChar(JsvStringIterator *it);
char jsvStringIteratorGetChar(JsvStringIterator *it);
void jsvStringIteratorNext(JsvStringIterator *it);
void jsvStringIteratorFree(JsvStringIterator *it);