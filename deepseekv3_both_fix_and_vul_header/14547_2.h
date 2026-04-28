#include <stdbool.h>
#include <stddef.h>

typedef unsigned int fmode_t;

struct file {
    fmode_t f_mode;
};

struct files_struct;

static struct file *files_lookup_fd_rcu(struct files_struct *files, unsigned int fd);
static bool get_file_rcu_many(struct file *file, unsigned int refs);
static void rcu_read_lock(void);
static void rcu_read_unlock(void);