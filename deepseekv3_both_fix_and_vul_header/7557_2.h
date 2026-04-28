#include <stdatomic.h>
#include <unistd.h>

typedef struct journal_s journal_t;
typedef struct transaction_s transaction_t;
typedef struct wait_queue_s wait_queue_t;

#define TASK_UNINTERRUPTIBLE 0

struct wait_queue_s {
    int dummy;
};

struct journal_s {
    struct transaction_s *j_running_transaction;
    wait_queue_t j_wait_updates;
    int j_state_lock;
};

struct transaction_s {
    atomic_int t_updates;
    int t_handle_lock;
};

#define DEFINE_WAIT(name) wait_queue_t name
#define spin_lock(lock) (void)0
#define spin_unlock(lock) (void)0
#define write_lock(lock) (void)0
#define write_unlock(lock) (void)0
#define prepare_to_wait(wq, wait, state) (void)0
#define finish_wait(wq, wait) (void)0
#define schedule() sleep(1)
#define atomic_read(v) atomic_load(v)