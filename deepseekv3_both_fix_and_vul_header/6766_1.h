#include <stdbool.h>

struct serio {
    struct i8042_port *port_data;
};

struct i8042_port {
    bool exists;
};

typedef struct {
    int dummy;
} spinlock_t;

#define spin_lock_irq(lock) (void)(lock)
#define spin_unlock_irq(lock) (void)(lock)

static spinlock_t i8042_lock;