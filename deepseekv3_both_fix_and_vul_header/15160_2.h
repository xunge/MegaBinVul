#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

struct linux_binprm {
    char *filename;
    int file;
    void *cred;
};

struct lib_info {
    int dummy;
};

#define PTR_ERR(x) ((long)(x))
#define IS_ERR(x) ((unsigned long)(x) >= (unsigned long)-4095)
#define ENOMEM 12

void *prepare_exec_creds(void);
int prepare_binprm(struct linux_binprm *);
int load_flat_file(struct linux_binprm *, struct lib_info *, int, void *);
void abort_creds(void *);
void allow_write_access(int);
void fput(int);
int open_exec(const char *);