#include <pthread.h>
#include <stddef.h>
#include <stdbool.h>

struct mm_slot;
struct task_struct {
    int nice;
};
extern struct task_struct *current;

struct {
    struct mm_slot *mm_slot;
} khugepaged_scan;

extern struct task_struct *khugepaged_thread;
extern pthread_mutex_t khugepaged_mutex;
extern pthread_spinlock_t khugepaged_mm_lock;

void set_freezable(void);
void set_user_nice(struct task_struct *tsk, int nice);
void mutex_lock(pthread_mutex_t *mutex);
void mutex_unlock(pthread_mutex_t *mutex);
void spin_lock(pthread_spinlock_t *lock);
void spin_unlock(pthread_spinlock_t *lock);
bool khugepaged_enabled(void);
void khugepaged_loop(void);
void collect_mm_slot(struct mm_slot *mm_slot);
int kthread_should_stop(void);
#define BUG_ON(cond) do { if (cond) abort(); } while (0)
#define unlikely(x) (x)