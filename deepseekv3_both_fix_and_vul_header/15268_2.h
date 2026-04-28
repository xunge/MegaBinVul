#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

struct file;
struct nfs_open_context {
    struct nfs4_state *state;
};
struct nfs4_state;
struct file_lock {
    long fl_start;
    long fl_end;
    unsigned char fl_type;
};

#define NFS4_LOCK_MINTIMEOUT 0
#define EINVAL 22
#define ENOLCK 37
#define EAGAIN 11
#define ERESTARTSYS 512

#define F_GETLK 5
#define F_SETLK 6
#define F_SETLKW 7
#define F_UNLCK 2

#define IS_GETLK(cmd) ((cmd) == F_GETLK)
#define IS_SETLK(cmd) ((cmd) == F_SETLK)
#define IS_SETLKW(cmd) ((cmd) == F_SETLKW)

static struct nfs_open_context *nfs_file_open_context(struct file *filp) { return 0; }
static int nfs4_proc_getlk(struct nfs4_state *state, int cmd, struct file_lock *request) { return 0; }
static int nfs4_proc_unlck(struct nfs4_state *state, int cmd, struct file_lock *request) { return 0; }
static int nfs4_proc_setlk(struct nfs4_state *state, int cmd, struct file_lock *request) { return 0; }
static unsigned long nfs4_set_lock_task_retry(unsigned long timeout) { return 0; }
static int signalled(void) { return 0; }