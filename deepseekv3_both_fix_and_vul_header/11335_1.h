#include <stdint.h>
#include <stdio.h>

#define EROFS 30
#define EUCLEAN 117
#define ENOSPC 28
#define EINVAL 22

typedef unsigned int tid_t;

struct buffer_head {
    unsigned long long b_blocknr;
    void *b_private;
};

struct handle_s {
    struct transaction_s *h_transaction;
    unsigned int h_type;
    unsigned int h_line_no;
    int h_buffer_credits;
};
typedef struct handle_s handle_t;

struct transaction_s {
    struct journal_s *t_journal;
    tid_t t_tid;
};
typedef struct transaction_s transaction_t;

struct journal_s {
    char *j_devname;
    transaction_t *j_running_transaction;
    transaction_t *j_committing_transaction;
    int j_list_lock;
};
typedef struct journal_s journal_t;

struct journal_head {
    transaction_t *b_transaction;
    transaction_t *b_next_transaction;
    unsigned int b_jlist;
    int b_modified;
    void *b_frozen_data;
};
typedef struct journal_head journal_head_t;

enum {
    BJ_Metadata
};

#define J_ASSERT_JH(jh, cond) do { if (!(cond)) { } } while (0)
#define JBUFFER_TRACE(jh, msg) do {} while (0)
#define is_handle_aborted(handle) (0)
#define buffer_jbd(bh) (1)
#define bh2jh(bh) ((journal_head_t *)(bh)->b_private)
#define jbd_lock_bh_state(bh) do {} while (0)
#define jbd_unlock_bh_state(bh) do {} while (0)
#define set_buffer_jbddirty(bh) do {} while (0)
#define __jbd2_journal_file_buffer(jh, transaction, BJ_Metadata) do {} while (0)
#define unlikely(x) (x)
#define WARN_ON(cond) do { if (cond) {} } while (0)
#define KERN_ERR ""
#define pr_err(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define printk(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define spin_lock(lock) do {} while (0)
#define spin_unlock(lock) do {} while (0)