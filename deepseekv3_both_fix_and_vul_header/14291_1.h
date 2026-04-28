#include <stddef.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define SMB2_MAX_CREDITS 8192
#define SIGNING_ALG_AES_CMAC 1

#define SMB2_GLOBAL_CAP_LEASING (1 << 0)
#define SMB2_GLOBAL_CAP_ENCRYPTION (1 << 1)
#define SMB2_GLOBAL_CAP_MULTI_CHANNEL (1 << 2)

#define KSMBD_GLOBAL_FLAG_SMB2_LEASES (1 << 0)
#define KSMBD_GLOBAL_FLAG_SMB3_MULTICHANNEL (1 << 1)

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

struct smb311_values {
    unsigned int capabilities;
};

struct smb3_11_server_ops {
    // placeholder for operations
};

struct ksmbd_conn {
    struct smb311_values *vals;
    struct smb3_11_server_ops *ops;
    void *cmds;
    size_t max_cmds;
    unsigned int max_credits;
    int signing_algorithm;
    int cipher_type;
    struct list_head preauth_sess_table;
};

struct server_conf {
    unsigned int flags;
};

extern struct server_conf server_conf;
extern struct smb311_values smb311_server_values;
extern struct smb3_11_server_ops smb3_11_server_ops;
extern void *smb2_0_server_cmds;