#include <stdint.h>

struct rq {
    int skip_clock_update;
    uint64_t clock;
    uint64_t clock_task;
};

typedef uint64_t u64;

uint64_t sched_clock_cpu(int cpu);
uint64_t irq_time_cpu(int cpu);
void sched_irq_time_avg_update(struct rq *rq, uint64_t irq_time);
int cpu_of(struct rq *rq);