#include <stdbool.h>
#include <stddef.h>

#define I8042_STR_OBF       0x01
#define I8042_STR_AUXDATA   0x20
#define I8042_STR_MUXERR    0x80
#define I8042_STR_PARITY    0x80
#define I8042_STR_TIMEOUT   0x40

#define I8042_MUX_PORT_NO   4
#define I8042_AUX_PORT_NO   1
#define I8042_KBD_PORT_NO   0

#define SERIO_TIMEOUT       1
#define SERIO_PARITY        2

typedef int irqreturn_t;
#define IRQ_RETVAL(x) ((x) != 0)

struct serio;
struct i8042_port {
    bool exists;
    bool driver_bound;
    struct serio *serio;
};

extern struct i8042_port i8042_ports[];
extern bool i8042_mux_present;
extern bool i8042_notimeout;
extern void spin_lock_irqsave(void *, unsigned long);
extern void spin_unlock_irqrestore(void *, unsigned long);
extern unsigned char i8042_read_status(void);
extern unsigned char i8042_read_data(void);
extern bool i8042_filter(unsigned char, unsigned char, struct serio *);
extern void serio_interrupt(struct serio *, unsigned char, unsigned int);
extern void dbg(const char *, ...);
extern void filter_dbg(bool, unsigned char, const char *, ...);
extern unsigned long jiffies;
extern void i8042_lock;

#define HZ 100
#define unlikely(x) (x)
#define likely(x) (x)
#define time_before(a,b) ((a)<(b))