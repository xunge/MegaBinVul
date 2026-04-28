#define SOFTIRQ_MASK 0x000000ff
#define CALLER_ADDR0 ((unsigned long)__builtin_return_address(0))
#define _RET_IP_ ((unsigned long)__builtin_return_address(0))

static inline void lockdep_assert_irqs_disabled(void) {}
static inline unsigned int preempt_count(void) { return 0; }
static inline void trace_preempt_on(unsigned long a, unsigned long b) {}
static inline unsigned int softirq_count(void) { return 0; }
static inline void trace_softirqs_on(unsigned long ip) {}
static inline void __preempt_count_sub(unsigned int cnt) {}