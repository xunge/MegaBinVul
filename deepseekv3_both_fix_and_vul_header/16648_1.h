#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>

static atomic_int usage_count;
static uintptr_t fdc_wait;
static unsigned long fdc_busy;
static int command_status;
#define FD_COMMAND_NONE 0
#define EINTR 4

int test_and_set_bit(int n, unsigned long *addr);
bool wait_event_interruptible(uintptr_t q, bool condition);
void reschedule_timeout(int drive, const char *msg);
void set_fdc(int drive);
#define WARN(cond, msg) (cond)