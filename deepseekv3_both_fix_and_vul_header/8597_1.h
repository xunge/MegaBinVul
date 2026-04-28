#include <stdint.h>

typedef struct handle_s {
    int h_err;
    struct transaction_s *h_transaction;
} handle_t;

typedef struct transaction_s {
    struct journal_s *t_journal;
} transaction_t;

typedef struct journal_s {
    void *j_private;
} journal_t;

struct super_block;

int ext4_handle_valid(handle_t *handle);
void ext4_put_nojournal(handle_t *handle);
int jbd2_journal_stop(handle_t *handle);
void __ext4_std_error(struct super_block *sb, const char *where, unsigned int line, int err);