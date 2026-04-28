#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct js_State js_State;
typedef struct js_Object js_Object;
typedef struct Reprog Reprog;

struct js_Object {
    int type;
    void *prototype;
    union {
        struct {
            Reprog *prog;
            char *source;
            int flags;
            int last;
        } r;
    } u;
};

struct js_State {
    void *(*alloc)(void *, void *, size_t);
    void *actx;
    js_Object *RegExp_prototype;
};

enum {
    JS_CREGEXP,
    JS_REGEXP_I,
    JS_REGEXP_M
};

js_Object *jsV_newobject(js_State *J, int type, void *proto);
Reprog *js_regcompx(void *(*alloc)(void *, void *, size_t), void *actx, const char *pattern, int opts, const char **error);
char *js_strdup(js_State *J, const char *s);
void js_pushobject(js_State *J, js_Object *obj);
void js_syntaxerror(js_State *J, const char *fmt, ...);