#include <stdint.h>
#include <string.h>
#include <errno.h>

#define TIPC_NET_MODE 1
#define TIPC_MIN_LINK_PRI 0
#define TIPC_MAX_LINK_PRI 31
#define TIPC_MIN_LINK_TOL 0
#define TIPC_MAX_LINK_TOL 5000
#define MAX_MEDIA 32

typedef uint32_t u32;

struct tipc_bearer;
struct sk_buff;

struct tipc_media_addr {
    char addr[16];
    u32 scope;
};

struct media {
    u32 type_id;
    char name[16];
    int (*enable_bearer)(struct tipc_bearer *);
    void (*disable_bearer)(struct tipc_bearer *);
    int (*send_msg)(struct sk_buff *, struct tipc_bearer *, struct tipc_media_addr *);
    char *(*addr2str)(struct tipc_media_addr *a, char *str_buf, int str_size);
    struct tipc_media_addr bcast_addr;
    u32 bcast;
    u32 priority;
    u32 tolerance;
    u32 window;
};

extern struct media media_list[MAX_MEDIA];
extern u32 media_count;
extern int tipc_mode;
extern int tipc_net_lock;

int media_name_valid(char *name);
void warn(const char *fmt, ...);
void dbg(const char *fmt, ...);

void write_lock_bh(int *lock);
void write_unlock_bh(int *lock);