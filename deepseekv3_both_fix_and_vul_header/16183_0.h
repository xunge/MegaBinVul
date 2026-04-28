#include <stdbool.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>

struct io;
struct bt_att_chan;
struct bt_att;

struct bt_att_chan {
    struct bt_att *att;
    int fd;
    void *pending_req;
    void *pending_ind;
};

struct bt_att {
    void *debug_callback;
    void *debug_data;
    void *chans;
    void *req_queue;
    void *ind_queue;
    void *write_queue;
    void *disconn_list;
    bool in_disc;
};

void util_debug(void *debug_callback, void *debug_data, const char *format, ...);
void queue_remove(void *queue, void *item);
bool queue_isempty(void *queue);
void queue_remove_all(void *queue, void *match, void *data, void *callback);
void queue_foreach(void *queue, void *func, void *user_data);
void bt_att_chan_free(struct bt_att_chan *chan);
void bt_att_ref(struct bt_att *att);
void bt_att_unregister_all(struct bt_att *att);
void bt_att_unref(struct bt_att *att);
void disc_att_send_op(void *op);
void disconn_handler(void *data, void *user_data);