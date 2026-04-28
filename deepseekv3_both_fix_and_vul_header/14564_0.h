#include <stddef.h>
#include <string.h>

typedef struct JsVar JsVar;

typedef enum {
    JSON_IGNORE_FUNCTIONS,
    JSON_NO_UNDEFINED,
    JSON_ARRAYBUFFER_AS_ARRAY,
    JSON_JSON_COMPATIBILE,
    JSON_ALLOW_TOJSON,
    JSON_ALL_NEWLINES,
    JSON_PRETTY
} JSONFlags;

#define NOT_USED(x) (void)(x)

JsVar *jsvNewFromEmptyString(void);
int jsvIsUndefined(JsVar *v);
int jsvIsNull(JsVar *v);
int jsvIsNumeric(JsVar *v);
int jsvGetInteger(JsVar *v);
size_t jsvGetString(JsVar *v, char *str, size_t len);
void jsfGetJSONWhitespace(JsVar *v, JsVar *result, JSONFlags flags, const char *whitespace);