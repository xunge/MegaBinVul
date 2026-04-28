#include <stddef.h>
#include <sys/types.h>

struct n_tty_data;
struct file;

struct tty_struct {
    struct n_tty_data *disc_data;
    void *termios_rwsem;  // Simplified from rw_semaphore to void*
};

#define L_ICANON(tty) (0)
#define __user
#define TIOCOUTQ 0x5411
#define TIOCINQ 0x541B

int tty_chars_in_buffer(struct tty_struct *tty);
int inq_canon(struct n_tty_data *ldata);
int read_cnt(struct n_tty_data *ldata);
int n_tty_ioctl_helper(struct tty_struct *tty, struct file *file, unsigned int cmd, unsigned long arg);
int put_user(int val, void *ptr);
void down_write(void *sem);
void up_write(void *sem);