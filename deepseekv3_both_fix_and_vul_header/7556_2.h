#include <stdatomic.h>
#include <pthread.h>

typedef struct journal_t {
    pthread_rwlock_t j_state_lock;
    atomic_int j_reserved_credits;
    pthread_cond_t j_wait_reserved;
    unsigned int j_barrier_count;
    pthread_mutex_t j_barrier;
} journal_t;

#define DEFINE_WAIT(name) int name

void write_lock(pthread_rwlock_t *lock);
void write_unlock(pthread_rwlock_t *lock);
void jbd2_might_wait_for_commit(journal_t *journal);
void jbd2_journal_wait_updates(journal_t *journal);
void wait_event(pthread_cond_t cond, int condition);
void mutex_lock(pthread_mutex_t *mutex);