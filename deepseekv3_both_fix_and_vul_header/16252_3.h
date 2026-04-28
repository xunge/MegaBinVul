#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <getopt.h>

typedef enum {
    inode_unknown,
    inode_dir,
    inode_file,
    inode_fifo
} inode_t;

extern char *applet;
extern const char *getoptstring;
extern const struct option *longopts;
extern void eerrorx(const char *fmt, ...);
extern void usage(int status);
extern int parse_mode(mode_t *mode, const char *optarg);
extern int parse_owner(struct passwd **pw, struct group **gr, const char *optarg);
extern int selinux_util_open(void);
extern void selinux_util_close(void);
extern int is_writable(const char *path);
extern int do_check(const char *path, uid_t uid, gid_t gid, mode_t mode, inode_t type, bool trunc, bool chowner, bool selinux_on, ...);
extern char *basename_c(const char *path);

#define case_RC_COMMON_GETOPT \
    case 'h': \
        usage(EXIT_SUCCESS); \
        break; \
    case 'v': \
        printf("%s\n", "version"); \
        exit(EXIT_SUCCESS); \
        break;