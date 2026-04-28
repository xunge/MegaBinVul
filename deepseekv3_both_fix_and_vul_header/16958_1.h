#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define WRITE_BUFFER_SIZE 1024
#define conn_new_cmd 0

typedef struct conn conn;
typedef struct mc_resp mc_resp;

struct mc_resp {
    bool skip;
    char wbuf[WRITE_BUFFER_SIZE];
};

struct conn {
    mc_resp *resp;
    bool noreply;
    int sfd;
};

struct {
    int verbose;
} settings;

void resp_reset(mc_resp *resp);
void resp_add_iov(mc_resp *resp, const char *buf, size_t len);
void conn_set_state(conn *c, int state);