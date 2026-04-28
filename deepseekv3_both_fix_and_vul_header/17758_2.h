#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct _agooCon *agooCon;
typedef struct _agooReq *agooReq;
typedef struct _agooUp *agooUp;

enum {
    AGOO_WS_OP_BIN,
    AGOO_ON_BIN,
    AGOO_ON_MSG,
    AGOO_UP_NONE,
    AGOO_NONE,
    PUSH_HOOK
};

struct _agooReq {
    char *msg;
    long mlen;
    int method;
    int upgrade;
    agooUp up;
    char remote[0];
    void *res;
    void *hook;
};

struct _agooCon {
    uint8_t *buf;
    agooReq req;
    size_t bcnt;
    agooUp up;
    char remote[0];
};

struct _agooUp {
    void *ctx;
    bool (*on_msg)();
};

struct {
    void *ctx_nil_value;
    void *eval_queue;
} agoo_server;

struct {
    int dummy;
} agoo_error_cat;

extern agooReq agoo_req_create(long mlen);
extern void agoo_log_cat(void *cat, const char *msg);
extern void *agoo_hook_create(int type, void *arg, void *ctx, int hook_type, void *queue);