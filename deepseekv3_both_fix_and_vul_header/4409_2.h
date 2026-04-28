#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define SCM_MAX_FD 253
#define GFP_KERNEL 0

struct file;
struct user_struct;

struct scm_fp_list {
    struct file *fp[SCM_MAX_FD];
    int count;
    int max;
    struct user_struct *user;
};

struct file *fget_raw(int fd);
struct user_struct *current_user();
struct user_struct *get_uid(struct user_struct *user);
void *kmalloc(size_t size, int flags);