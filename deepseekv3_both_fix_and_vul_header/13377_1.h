#include <stdbool.h>

#define FALSE false
#define JS_CLASS_PROXY 0

typedef struct JSContext JSContext;
typedef struct JSRuntime JSRuntime;
typedef struct JSValueConst {} JSValueConst;
typedef struct JSProxyData JSProxyData;

struct JSProxyData {
    bool is_revoked;
    JSValueConst *target;
};

struct JSContext {
    JSRuntime *rt;
};

int JS_IsArray(JSContext *ctx, JSValueConst *obj);
JSProxyData *JS_GetOpaque(JSValueConst obj, int class_id);
int js_check_stack_overflow(JSRuntime *rt, int size);
void JS_ThrowStackOverflow(JSContext *ctx);
void JS_ThrowTypeErrorRevokedProxy(JSContext *ctx);