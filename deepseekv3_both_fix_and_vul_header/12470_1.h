#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef unsigned long mjs_val_t;
typedef enum mjs_err mjs_err_t;

enum mjs_err {
    MJS_OK,
    MJS_TYPE_ERROR,
    MJS_UNDEFINED
};

struct json_parse_ctx {
    struct mjs *mjs;
    mjs_val_t result;
    void *frame;
    enum mjs_err rcode;
};

struct mjs;

#define MJS_PRIVATE
#define mjs_own(mjs, val)
#define mjs_disown(mjs, val)
#define mjs_prepend_errorf(mjs, err, msg)

int json_walk(const char *str, size_t len, void (*cb)(void *), void *ctx);
void frozen_cb(void *ctx);
void *free_json_frame(struct json_parse_ctx *ctx, void *frame);