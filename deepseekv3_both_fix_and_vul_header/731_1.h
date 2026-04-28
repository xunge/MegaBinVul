#include <stddef.h>
#include <stdint.h>

typedef struct asymcute_con asymcute_con_t;
typedef struct asymcute_req asymcute_req_t;
typedef struct asymcute_sub asymcute_sub_t;
typedef struct asymcute_topic asymcute_topic_t;

#define MINLEN_SUBACK 8
#define IDPOS_SUBACK 1
#define MQTTSN_ACCEPTED 0

enum {
    ASYMCUTE_REJECTED,
    ASYMCUTE_SUBSCRIBED
};

struct asymcute_topic {
    uint16_t id;
    asymcute_con_t *con;
};

struct asymcute_sub {
    asymcute_sub_t *next;
    asymcute_topic_t *topic;
};

struct asymcute_req {
    void *arg;
    void *lock;
};

struct asymcute_con {
    void *lock;
    asymcute_sub_t *subscriptions;
    void (*user_cb)(asymcute_req_t *, unsigned);
};

static uint16_t byteorder_bebuftohs(const uint8_t *buf) {
    return (buf[0] << 8) | buf[1];
}

static asymcute_req_t *_req_preprocess(asymcute_con_t *con, size_t len, size_t minlen, const uint8_t *data, size_t idpos);
static void mutex_lock(void *lock);
static void mutex_unlock(void *lock);