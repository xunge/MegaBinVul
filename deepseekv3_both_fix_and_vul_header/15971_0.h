#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Object js_Object;
typedef struct js_Property js_Property;

struct js_Property {
    int atts;
    js_Object *getter;
    js_Object *setter;
    void *value;
};

#define JS_READONLY  0x01
#define JS_DONTENUM  0x02
#define JS_DONTCONF  0x04