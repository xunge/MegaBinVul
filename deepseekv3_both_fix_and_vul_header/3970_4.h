#include <string.h>

typedef struct js_State js_State;
typedef struct js_Object js_Object;
typedef struct js_Property js_Property;

struct js_Property {
    void *getter;
    void *value;
};

struct js_Object {
    int type;
    union {
        struct {
            int length;
        } a;
        struct {
            int length;
            const char *string;
        } s;
        struct {
            const char *source;
            int flags;
            int last;
        } r;
        struct {
            int (*has)(js_State *, void *, const char *);
            void *data;
        } user;
    } u;
};

#define JS_CARRAY 0
#define JS_CSTRING 1
#define JS_CREGEXP 2
#define JS_CUSERDATA 3

#define JS_REGEXP_G 1
#define JS_REGEXP_I 2
#define JS_REGEXP_M 4

void js_pushnumber(js_State *J, double n);
void js_pushrune(js_State *J, int c);
void js_pushliteral(js_State *J, const char *v);
void js_pushboolean(js_State *J, int v);
void js_pushobject(js_State *J, void *v);
void js_pushvalue(js_State *J, void *v);
void js_call(js_State *J, int n);

int js_isarrayindex(js_State *J, const char *name, int *k);
int js_runeat(js_State *J, const char *s, int k);
js_Property *jsV_getproperty(js_State *J, js_Object *obj, const char *name);