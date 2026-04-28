#include <stdint.h>
#include <string.h>

#define N_TTY_BUF_SIZE 4096
#define BITS_PER_LONG (sizeof(unsigned long) * 8)
#define __DISABLED_CHAR 0xff

typedef unsigned int tcflag_t;

struct ktermios {
    tcflag_t c_lflag;
    tcflag_t c_iflag;
};

struct n_tty_data {
    unsigned long read_flags[(N_TTY_BUF_SIZE + BITS_PER_LONG - 1) / BITS_PER_LONG];
    unsigned long char_map[256 / BITS_PER_LONG];
    unsigned int line_start;
    unsigned int read_tail;
    unsigned int read_head;
    unsigned int canon_head;
    unsigned int commit_head;
    unsigned int erasing;
    unsigned int lnext;
    unsigned int push;
    unsigned int icanon;
    unsigned int raw;
    unsigned int real_raw;
};

struct tty_driver {
    int flags;
};

struct tty_struct {
    struct n_tty_data *disc_data;
    struct ktermios termios;
    struct tty_driver *driver;
    int flow_stopped;
    void *write_wait;
    void *read_wait;
};

#define ICANON 0000002
#define EXTPROC 0200000
#define ISTRIP 0000040
#define IUCLC 0001000
#define IGNCR 0000200
#define ICRNL 0000400
#define INLCR 0000100
#define IXON 0002000
#define ISIG 0000001
#define ECHO 0000010
#define PARMRK 0000010
#define IEXTEN 0100000
#define IGNBRK 0000001
#define BRKINT 0000002
#define INPCK 0000020
#define IGNPAR 0000004

#define TTY_DRIVER_REAL_RAW 0x01

static inline void bitmap_zero(unsigned long *addr, unsigned int size)
{
    memset(addr, 0, (size + BITS_PER_LONG - 1) / BITS_PER_LONG * sizeof(unsigned long));
}

static inline void set_bit(int nr, volatile unsigned long *addr)
{
    addr[nr / BITS_PER_LONG] |= (1UL << (nr % BITS_PER_LONG));
}

static inline void clear_bit(int nr, volatile unsigned long *addr)
{
    addr[nr / BITS_PER_LONG] &= ~(1UL << (nr % BITS_PER_LONG));
}

#define L_ICANON(tty)   ((tty)->termios.c_lflag & ICANON)
#define I_ISTRIP(tty)   ((tty)->termios.c_iflag & ISTRIP)
#define I_IUCLC(tty)    ((tty)->termios.c_iflag & IUCLC)
#define I_IGNCR(tty)    ((tty)->termios.c_iflag & IGNCR)
#define I_ICRNL(tty)    ((tty)->termios.c_iflag & ICRNL)
#define I_INLCR(tty)    ((tty)->termios.c_iflag & INLCR)
#define I_IXON(tty)     ((tty)->termios.c_iflag & IXON)
#define L_ISIG(tty)     ((tty)->termios.c_lflag & ISIG)
#define L_ECHO(tty)     ((tty)->termios.c_lflag & ECHO)
#define I_PARMRK(tty)   ((tty)->termios.c_iflag & PARMRK)
#define L_IEXTEN(tty)   ((tty)->termios.c_lflag & IEXTEN)
#define I_IGNBRK(tty)   ((tty)->termios.c_iflag & IGNBRK)
#define I_BRKINT(tty)   ((tty)->termios.c_iflag & BRKINT)
#define I_INPCK(tty)    ((tty)->termios.c_iflag & INPCK)
#define I_IGNPAR(tty)   ((tty)->termios.c_iflag & IGNPAR)

static inline unsigned int read_cnt(struct n_tty_data *ldata)
{
    return ldata->read_head - ldata->read_tail;
}

static inline void start_tty(struct tty_struct *tty) {}
static inline void process_echoes(struct tty_struct *tty) {}
static inline void wake_up_interruptible(void *wait) {}

#define ERASE_CHAR(tty) 0x7f
#define KILL_CHAR(tty) 0x15
#define EOF_CHAR(tty) 0x04
#define EOL_CHAR(tty) '\0'
#define WERASE_CHAR(tty) 0x17
#define LNEXT_CHAR(tty) 0x16
#define EOL2_CHAR(tty) '\0'
#define REPRINT_CHAR(tty) 0x12
#define START_CHAR(tty) 0x11
#define STOP_CHAR(tty) 0x13
#define INTR_CHAR(tty) 0x03
#define QUIT_CHAR(tty) 0x1c
#define SUSP_CHAR(tty) 0x1a