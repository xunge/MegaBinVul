#include <assert.h>

struct nbd_handle;
struct nbd_completion_callback {
    int (*callback)(void *user_data);
    void *user_data;
};

extern int nbd_unlocked_aio_opt_go(struct nbd_handle *h, struct nbd_completion_callback *c);
extern int wait_for_option(struct nbd_handle *h);
extern int nbd_internal_is_state_negotiating(int state);
extern int nbd_internal_is_state_ready(int state);
extern int get_next_state(struct nbd_handle *h);
extern void set_error(int err, const char *msg);
extern int go_complete(void *user_data);

typedef struct nbd_completion_callback nbd_completion_callback;