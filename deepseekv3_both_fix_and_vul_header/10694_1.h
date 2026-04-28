#include <sys/time.h>
#include <string.h>
#include <arpa/nameser.h>
#include <netinet/in.h>

typedef struct __res_state *res_state;

struct __res_state {
    int options;
    int id;
};

#define RES_RECURSE 0x01