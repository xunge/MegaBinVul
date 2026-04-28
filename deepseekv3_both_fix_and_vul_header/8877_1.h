#include <string.h>

typedef struct js_State js_State;
typedef struct js_Object js_Object;
typedef struct js_Function js_Function;

enum {
    JS_CFUNCTION,
    JS_CSCRIPT
};

struct js_Object {
    int type;
    union {
        struct {
            js_Function *function;
        } f;
    } u;
};

struct js_Function {
    char *name;
    int numparams;
    char **vartab;
};

js_Object *js_toobject(js_State *J, int idx);
int js_iscallable(js_State *J, int idx);
void js_typeerror(js_State *J, const char *msg);
void *js_malloc(js_State *J, int size);
int js_try(js_State *J);
void js_free(js_State *J, void *ptr);
void js_throw(js_State *J);
void js_pushstring(js_State *J, const char *v);
void js_endtry(js_State *J);
void js_pushliteral(js_State *J, const char *v);