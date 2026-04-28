#include <stddef.h>
#include <stdint.h>

typedef struct asymcute_con asymcute_con_t;
typedef struct asymcute_req asymcute_req_t;
typedef struct asymcute_topic asymcute_topic_t;

struct asymcute_con {
    void (*user_cb)(asymcute_req_t *, unsigned);
    void *lock;
};

struct asymcute_req {
    void *arg;
    void *lock;
};

struct asymcute_topic {
    uint16_t id;
    asymcute_con_t *con;
};

#define MINLEN_REGACK 7
#define IDPOS_REGACK 1
#define MQTTSN_ACCEPTED 0
#define ASYMCUTE_REJECTED 0
#define ASYMCUTE_REGISTERED 1

static uint16_t byteorder_bebuftohs(const uint8_t *buf);
static asymcute_req_t *_req_preprocess(asymcute_con_t *con, size_t len, size_t minlen, const uint8_t *data, size_t idpos);
static void mutex_lock(void *lock);
static void mutex_unlock(void *lock);