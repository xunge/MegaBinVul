#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef void (*vcbprintf_callback)(const char *, void *);
typedef long long JsVarInt;
typedef double JsVarFloat;
typedef struct JsVar JsVar;
typedef int Pin;

#define JSON_SOME_NEWLINES  (1<<0)
#define JSON_PRETTY         (1<<1)
#define JSON_SHOW_DEVICES   (1<<2)
#define JSON_ALLOW_TOJSON   (1<<3)

void itostr(int val, char *buf, int radix);
void itostr_extra(JsVarInt val, char *buf, bool signedVal, int radix);
void ftoa_bounded(JsVarFloat val, char *buf, int bufSize);
JsVar *jsvAsString(JsVar *v);
bool jsvIsString(JsVar *v);
void jsvUnLock(JsVar *v);
const char *escapeCharacter(char c, bool isJSONStyle);
void jsfGetJSONWithCallback(JsVar *v, void *unused, int flags, int indent, vcbprintf_callback callback, void *user_data);
const char *jsvGetTypeOf(JsVar *v);
bool jsvIsNull(JsVar *v);
const char *jswGetBasicObjectName(JsVar *v);
void jshGetPinString(char *buf, Pin pin);

typedef struct JsvStringIterator {
    JsVar *var;
    size_t charIdx;
} JsvStringIterator;

void jsvStringIteratorNew(JsvStringIterator *it, JsVar *v, size_t startChar);
bool jsvStringIteratorHasChar(JsvStringIterator *it);
char jsvStringIteratorGetCharAndNext(JsvStringIterator *it);
void jsvStringIteratorFree(JsvStringIterator *it);