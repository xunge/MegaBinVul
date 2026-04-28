#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define MAXPATHLEN 4096

typedef struct {
    char *std_err;
    char *std_out;
    unsigned int job_id;
    char *work_dir;
    uid_t uid;
    gid_t gid;
} batch_job_launch_msg_t;

extern char *slurm_strerror(int errnum);
extern void error(const char *format, ...);
extern ssize_t safe_write(int fd, const void *buf, size_t count);