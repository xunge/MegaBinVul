#include <stdbool.h>
#include <stddef.h>

struct serio {
    struct i8042_port *port_data;
};

struct i8042_port {
    bool exists;
    struct serio *serio;
};

extern int i8042_lock;
#define spin_lock_irq(lock) (void)0
#define spin_unlock_irq(lock) (void)0
#define synchronize_irq(irq) (void)0
#define I8042_AUX_IRQ 12
#define I8042_KBD_IRQ 1