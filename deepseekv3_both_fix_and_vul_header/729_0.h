#include <stddef.h>
#include <stdint.h>

typedef struct asymcute_con asymcute_con_t;
typedef struct asymcute_req asymcute_req_t;
typedef struct asymcute_sub asymcute_sub_t;

struct asymcute_sub {
    asymcute_sub_t *next;
    const char *topic;
};

struct asymcute_req {
    void *arg;
    void *lock;
};

struct asymcute_con {
    asymcute_sub_t *subscriptions;
    void *lock;
    void (*user_cb)(asymcute_req_t *, int);
};

enum {
    MINLEN_UNSUBACK,
    IDPOS_UNSUBACK,
    ASYMCUTE_UNSUBSCRIBED
};

void mutex_lock(void *lock);
void mutex_unlock(void *lock);
asymcute_req_t *_req_preprocess(asymcute_con_t *con, size_t len, int minlen, const uint8_t *data, int idpos);