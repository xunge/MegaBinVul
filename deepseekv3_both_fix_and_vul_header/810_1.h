#include <stdbool.h>

enum bp_state {
    BP_DONE,
    BP_EAGAIN
};

struct balloon_stats {
    long schedule_delay;
};

struct work_struct;
struct delayed_work;

extern struct balloon_stats balloon_stats;
extern struct delayed_work balloon_worker;
extern int balloon_mutex;

long current_credit(void);
bool balloon_is_inflated(void);
enum bp_state increase_reservation(long credit);
enum bp_state reserve_additional_memory(void);
enum bp_state decrease_reservation(long n_pages, int gfp_flags);
enum bp_state update_schedule(enum bp_state state);
long si_mem_available(void);
long totalreserve_pages;

#define GFP_BALLOON 0
#define HZ 1

void mutex_lock(int *mutex);
void mutex_unlock(int *mutex);
void cond_resched(void);
void schedule_delayed_work(struct delayed_work *work, unsigned long delay);
long min(long a, long b);