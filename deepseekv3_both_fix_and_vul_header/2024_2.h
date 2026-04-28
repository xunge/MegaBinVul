#include <stddef.h>

struct buffer_head {
    unsigned long b_state;
    void *b_bdev;
};

struct journal_head {
    struct transaction_s *b_transaction;
    struct transaction_s *b_cp_transaction;
    struct transaction_s *b_next_transaction;
};

struct transaction_s {
    // transaction fields
};

typedef struct transaction_s transaction_t;

struct journal_s {
    transaction_t *j_running_transaction;
    transaction_t *j_committing_transaction;
    int j_list_lock;
    int j_state_lock;
};

typedef struct journal_s journal_t;

#define BUFFER_TRACE(bh, msg)
#define JBUFFER_TRACE(jh, msg)
#define J_ASSERT_JH(jh, cond)
#define J_ASSERT_BH(bh, cond)

static inline int buffer_jbd(struct buffer_head *bh) { return 0; }
static inline void jbd_lock_bh_state(struct buffer_head *bh) {}
static inline void jbd_unlock_bh_state(struct buffer_head *bh) {}
static inline void clear_buffer_jbddirty(struct buffer_head *bh) {}
static inline void set_buffer_freed(struct buffer_head *bh) {}
static inline void clear_buffer_dirty(struct buffer_head *bh) {}
static inline void clear_buffer_mapped(struct buffer_head *bh) {}
static inline void clear_buffer_req(struct buffer_head *bh) {}
static inline void clear_buffer_new(struct buffer_head *bh) {}
static inline int buffer_dirty(struct buffer_head *bh) { return 0; }
static inline int buffer_jbddirty(struct buffer_head *bh) { return 0; }

static struct journal_head *jbd2_journal_grab_journal_head(struct buffer_head *bh) { return NULL; }
static void jbd2_journal_put_journal_head(struct journal_head *jh) {}
static int __dispose_buffer(struct journal_head *jh, transaction_t *transaction) { return 0; }

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}
static inline void write_lock(int *lock) {}
static inline void write_unlock(int *lock) {}