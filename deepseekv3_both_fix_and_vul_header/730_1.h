#include <stddef.h>
#include <stdint.h>

typedef struct asymcute_con asymcute_con_t;
typedef struct asymcute_req asymcute_req_t;
typedef struct asymcute_sub asymcute_sub_t;

#define ASYMCUTE_REJECTED 0
#define ASYMCUTE_TIMEOUT 1

struct asymcute_req {
    void *arg;
};

struct asymcute_sub {
    void *topic;
};