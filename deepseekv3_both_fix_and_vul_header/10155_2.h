#include <stdlib.h>

typedef struct js_State js_State;
typedef struct js_Object js_Object;
typedef struct js_Property js_Property;

struct js_State {
    void *alloc;
    void *actx;
};

struct js_Object {
    int type;
    js_Property *head;
    union {
        struct {
            char *source;
            void *prog;
        } r;
        struct {
            js_Property *head;
        } iter;
        struct {
            void (*finalize)(js_State *J, void *data);
            void *data;
        } user;
    } u;
};

enum {
    JS_CREGEXP,
    JS_CITERATOR,
    JS_CUSERDATA
};

static void jsG_freeproperty(js_State *J, js_Property *prop);
static void jsG_freeiterator(js_State *J, js_Property *head);
static void js_free(js_State *J, void *ptr);
static void js_regfreex(void *alloc, void *actx, void *prog);