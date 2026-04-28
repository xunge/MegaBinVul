#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

typedef enum {
    inode_file,
    inode_dir,
    inode_fifo
} inode_t;

extern char *applet;
extern void einfo(const char *fmt, ...);
extern void eerror(const char *fmt, ...);
extern void selinux_util_label(const char *path);