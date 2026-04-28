#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct snd_sof_dev {
    struct {
        void *tx_mutex;
    } *ipc;
};

struct sof_ipc_ctrl_data {
    int type;
    size_t hdr_bytes;
    size_t num_elems;
    size_t elems_remaining;
    size_t msg_index;
    struct {
        struct {
            unsigned int cmd;
            size_t size;
        } hdr;
    } rhdr;
};

struct sof_ipc_ctrl_data_params {
    size_t msg_bytes;
    size_t pl_size;
    size_t num_msg;
    size_t hdr_bytes;
    void *src;
    void *dst;
};

extern int sof_get_ctrl_copy_params(int type, void *src, void *dst, struct sof_ipc_ctrl_data_params *sparams);
extern int sof_ipc_tx_message_unlocked(void *ipc, unsigned int cmd, void *msg_data, size_t msg_bytes, void *reply_data, size_t reply_bytes);

#define SOF_IPC_MSG_MAX_SIZE 1024
#define GFP_KERNEL 0
#define ENOMEM 12

void *kzalloc(size_t size, int flags);
void kfree(void *ptr);
void mutex_lock(void *mutex);
void mutex_unlock(void *mutex);