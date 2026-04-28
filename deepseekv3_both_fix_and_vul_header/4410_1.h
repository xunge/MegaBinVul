#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

struct file;

struct scm_fp_list {
    int count;
    uid_t user;
    struct file *fp[];
};

struct scm_cookie {
    struct scm_fp_list *fp;
};

void fput(struct file *);
void free_uid(uid_t);
void kfree(void *);