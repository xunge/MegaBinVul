#include <stdatomic.h>
#include <string.h>

struct list_head {
    struct list_head *next, *prev;
};

static struct list_head cifs_tcp_ses_list;
static struct list_head GlobalDnotifyReqList;
static struct list_head GlobalDnotifyRsp_Q;

static atomic_int sesInfoAllocCount;
static atomic_int tconInfoAllocCount;
static atomic_int tcpSesAllocCount;
static atomic_int tcpSesReconnectCount;
static atomic_int tconInfoReconnectCount;
static atomic_int bufAllocCount;
static atomic_int smBufAllocCount;
static atomic_int totBufAllocCount;
static atomic_int totSmBufAllocCount;
static atomic_int midCount;

static unsigned int GlobalCurrentXid;
static unsigned int GlobalTotalActiveXid;
static unsigned int GlobalMaxActiveXid;
static char Local_System_Name[15];

struct rwlock_t {
    int lock;
};
static struct rwlock_t GlobalSMBSeslock;
static struct rwlock_t cifs_tcp_ses_lock;

struct spinlock_t {
    int lock;
};
static struct spinlock_t GlobalMid_Lock;

static int cifs_max_pending;

struct file_system_type {
    int dummy;
};
static struct file_system_type cifs_fs_type;

struct key_type {
    int dummy;
};
static struct key_type cifs_spnego_key_type;
static struct key_type key_type_dns_resolver;

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

#define atomic_set(v, i) atomic_store(v, i)
#define rwlock_init(lock) ((void)0)
#define spin_lock_init(lock) ((void)0)
#define __init
#define cFYI(level, fmt, ...) ((void)0)
#define THIS_MODULE NULL