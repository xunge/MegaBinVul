#include <string.h>

typedef struct js_State js_State;
typedef struct js_Object js_Object;
typedef struct js_Value js_Value;
typedef struct js_Property js_Property;

#define JS_CARRAY 1
#define JS_CSTRING 2
#define JS_CREGEXP 3
#define JS_CUSERDATA 4
#define JS_READONLY 1

struct js_State {
    int strict;
};

struct js_Value {
    int type;
    union {
        double number;
        int boolean;
        char *string;
        js_Object *object;
    } u;
};

struct js_Object {
    int type;
    union {
        struct {
            int length;
        } a;
        struct {
            const char *string;
        } s;
        struct {
            int last;
        } r;
        struct {
            void *data;
            int (*put)(js_State *, void *, const char *);
        } user;
    } u;
};

struct js_Property {
    int atts;
    js_Value value;
    js_Object *setter;
};