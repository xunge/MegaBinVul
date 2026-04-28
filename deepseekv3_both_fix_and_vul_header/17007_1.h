#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define _SUCCESS 0
#define _FAIL -1

#define MAX_XMIT_EXTBUF_SZ 0
#define NR_XMIT_EXTBUFF 0
#define NR_XMITFRAME 0
#define MAX_FRAG_THRESHOLD 0
#define NR_XMITBUFF 0
#define MAX_XMITBUF_SZ 0
#define XMITBUF_ALIGN_SZ 0
#define NULL_FRAMETAG 0
#define XMIT_VO_QUEUE 0

typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;

struct list_head {
    struct list_head *next, *prev;
};

struct __queue {
    struct list_head queue;
};

struct xmit_buf {
    struct list_head list;
    void *priv_data;
    struct adapter *padapter;
    bool ext_tag;
    unsigned int flags;
};

struct xmit_frame {
    struct list_head list;
    struct adapter *padapter;
    void *frame_tag;
    void *pkt;
    void *buf_addr;
    struct xmit_buf *pxmitbuf;
};

struct xmit_priv {
    int lock;
    int terminate_xmitthread_sema;
    struct adapter *adapter;
    struct __queue be_pending;
    struct __queue bk_pending;
    struct __queue vi_pending;
    struct __queue vo_pending;
    struct __queue bm_pending;
    struct __queue free_xmit_queue;
    void *pallocated_frame_buf;
    u8 *pxmit_frame_buf;
    u32 free_xmitframe_cnt;
    u32 frag_len;
    struct __queue free_xmitbuf_queue;
    struct __queue pending_xmitbuf_queue;
    void *pallocated_xmitbuf;
    u8 *pxmitbuf;
    u32 free_xmitbuf_cnt;
    struct __queue free_xmit_extbuf_queue;
    void *pallocated_xmit_extbuf;
    u8 *pxmit_extbuf;
    u32 free_xmit_extbuf_cnt;
    void *hwxmits;
    u32 hwxmit_entry;
    u8 wmm_para_seq[4];
    u32 txirp_cnt;
    int tx_retevt;
    u32 beq_cnt;
    u32 bkq_cnt;
    u32 viq_cnt;
    u32 voq_cnt;
    bool ack_tx;
    int ack_tx_mutex;
    void *ack_tx_ops;
};

struct adapter;

#define N_BYTE_ALIGMENT(__sz, __align) (((__sz) + (__align - 1)) & ~(__align - 1))

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline void spin_lock_init(int *lock) {}
static inline void sema_init(int *sem, int val) {}
static inline void mutex_init(int *lock) {}

void *valloc(size_t size);
void msleep(unsigned int msecs);

void rtw_init_queue(struct __queue *queue);
int rtw_os_xmit_resource_alloc(struct adapter *padapter, struct xmit_buf *pxmitbuf, int size);
int rtw_alloc_hwxmits(struct adapter *padapter);
void rtw_init_hwxmits(void *hwxmits, u32 hwxmit_entry);
void rtw_sctx_init(void *sctx, int timeout_ms);
void rtl8188eu_init_xmit_priv(struct adapter *padapter);