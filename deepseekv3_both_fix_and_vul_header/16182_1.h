#include <stdbool.h>
#include <stdint.h>

struct bt_att_chan;
struct att_send_op;

struct queue_entry {
    void *data;
    struct queue_entry *next;
};

struct bt_att {
    void *chans;
    bool in_disc;
    void *req_queue;
    void *ind_queue;
    void *write_queue;
};

bool bt_att_chan_cancel(struct bt_att_chan *chan, unsigned int id);
bool bt_att_disc_cancel(struct bt_att *att, unsigned int id);
bool match_op_id(const void *data, const void *user_data);
void *queue_get_entries(void *queue);
void *queue_remove_if(void *queue, bool (*func)(const void *, const void *), const void *user_data);
void destroy_att_send_op(struct att_send_op *op);
void wakeup_writer(struct bt_att *att);
#define UINT_TO_PTR(x) ((void *)(uintptr_t)(x))