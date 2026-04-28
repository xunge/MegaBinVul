#include <stdint.h>

#define FYI 1
#define VFS 2

#define MID_RESPONSE_READY 0
#define MID_RESPONSE_RECEIVED 0
#define MID_RETRY_NEEDED 1
#define MID_RESPONSE_MALFORMED 2
#define MID_SHUTDOWN 3

#define MID_DELETED (1 << 0)

#define EAGAIN 11
#define EIO 5
#define EHOSTDOWN 112

struct list_head {
    struct list_head *next, *prev;
};

struct mid_q_entry {
    uint16_t command;
    uint64_t mid;
    int mid_state;
    unsigned int mid_flags;
    struct list_head qhead;
};

struct TCP_Server_Info {
    int mid_lock;
};

void cifs_dbg(int level, const char *fmt, ...);
void cifs_server_dbg(int level, const char *fmt, ...);
void release_mid(struct mid_q_entry *mid);
void spin_lock(int *lock);
void spin_unlock(int *lock);
uint16_t le16_to_cpu(uint16_t val);