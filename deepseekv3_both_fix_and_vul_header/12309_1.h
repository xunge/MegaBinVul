#define TIMER_SOFTIRQ 0

struct softirq_action {
    void (*action)(struct softirq_action *);
};

void init_timer_cpus(void);
void init_timer_stats(void);
void open_softirq(int nr, void (*action)(struct softirq_action *));
void run_timer_softirq(struct softirq_action *);

#define __init