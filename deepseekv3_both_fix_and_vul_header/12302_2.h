#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/utsname.h>

typedef struct {
    uint32_t op;
    uint32_t flags;
    uint32_t arg1_offset;
    uint32_t arg2_offset;
} PrivSepOp;

#define PRIV_SEP_OP_DONE 0
#define PRIV_SEP_OP_REMOUNT_RO_NO_RECURSIVE 1
#define PRIV_SEP_OP_BIND_MOUNT 2
#define PRIV_SEP_OP_PROC_MOUNT 3
#define PRIV_SEP_OP_TMPFS_MOUNT 4
#define PRIV_SEP_OP_DEVPTS_MOUNT 5
#define PRIV_SEP_OP_MQUEUE_MOUNT 6
#define PRIV_SEP_OP_SET_HOSTNAME 7

#define BIND_RECURSIVE (1 << 0)

extern int proc_fd;
extern char *opt_file_label;
extern int opt_unshare_uts;
extern char *label_mount(const char *opts, const char *label);

extern void die(const char *fmt, ...);
extern void die_with_error(const char *fmt, ...);
extern int bind_mount(int proc_fd, const char *src, const char *dest, int flags);

#define cleanup_free __attribute__((cleanup(free_ptr)))
static inline void free_ptr(void *p) { free(*(void**)p); }