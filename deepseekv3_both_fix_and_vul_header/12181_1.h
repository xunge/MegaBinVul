#include <stddef.h>

#define MID_RESPONSE_RECEIVED 0
#define MID_RESPONSE_READY 1

struct mid_q_entry {
    struct TCP_Server_Info *server;
    int mid_state;
    int optype;
};

struct TCP_Server_Info {
    struct {
        int (*get_credits)(struct mid_q_entry *);
    } *ops;
    int reconnect_instance;
};

struct cifs_credits {
    int value;
    int instance;
};

void add_credits(struct TCP_Server_Info *server, struct cifs_credits *credits, int optype);