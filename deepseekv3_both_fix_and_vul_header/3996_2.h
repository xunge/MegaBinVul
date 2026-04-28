#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define BUG_ON(cond) do { if (cond) abort(); } while (0)
#define TF_ONE_WAY 0x01
#define TF_UPDATE_TXN 0x02
#define BR_FROZEN_REPLY 0
#define BR_DEAD_REPLY 1
#define BINDER_DEBUG_TRANSACTION 0
#define BINDER_STAT_TRANSACTION 0

struct list_head {
    struct list_head *next, *prev;
};

struct binder_work {
    struct list_head entry;
};

struct binder_alloc {
    // dummy definition
    int dummy;
};

struct binder_buffer {
    struct binder_node *target_node;
    struct binder_transaction *transaction;
};

struct binder_node {
    bool has_async_transaction;
    int debug_id;
    struct list_head async_todo;
};

struct binder_thread {
    bool is_dead;
    void *task;
};

struct binder_proc {
    bool is_frozen;
    bool is_dead;
    bool sync_recv;
    bool async_recv;
    struct list_head todo;
    struct binder_alloc alloc;
    int outstanding_txns;
};

struct binder_transaction {
    struct binder_buffer *buffer;
    unsigned int flags;
    int debug_id;
    struct binder_work work;
};

static inline void list_del_init(struct list_head *entry) {
    entry->next = entry;
    entry->prev = entry;
}

static inline void binder_node_lock(struct binder_node *node) {}
static inline void binder_node_unlock(struct binder_node *node) {}
static inline void binder_inner_proc_lock(struct binder_proc *proc) {}
static inline void binder_inner_proc_unlock(struct binder_proc *proc) {}
static inline void trace_android_vh_binder_proc_transaction_entry(struct binder_proc *proc, struct binder_transaction *t, struct binder_thread **thread, int debug_id, bool pending_async, bool sync, bool *skip) {}
static inline struct binder_thread *binder_select_thread_ilocked(struct binder_proc *proc) { return NULL; }
static inline void binder_transaction_priority(struct binder_thread *thread, struct binder_transaction *t, struct binder_node *node) {}
static inline void binder_enqueue_thread_work_ilocked(struct binder_thread *thread, struct binder_work *work) {}
static inline void binder_enqueue_work_ilocked(struct binder_work *work, struct list_head *list) {}
static inline struct binder_transaction *binder_find_outdated_transaction_ilocked(struct binder_transaction *t, struct list_head *list) { return NULL; }
static inline void binder_debug(int level, const char *fmt, ...) {}
static inline void trace_android_vh_binder_proc_transaction_finish(struct binder_proc *proc, struct binder_transaction *t, void *task, bool pending_async, bool sync) {}
static inline void binder_wakeup_thread_ilocked(struct binder_proc *proc, struct binder_thread *thread, bool sync) {}
static inline void trace_binder_transaction_update_buffer_release(struct binder_buffer *buffer) {}
static inline void binder_transaction_buffer_release(struct binder_proc *proc, void *a, struct binder_buffer *buffer, int b, int c) {}
static inline void binder_alloc_free_buf(struct binder_alloc *alloc, struct binder_buffer *buffer) {}
static inline void kfree(void *ptr) { free(ptr); }
static inline void binder_stats_deleted(int stat) {}