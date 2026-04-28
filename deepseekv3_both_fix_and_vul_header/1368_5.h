#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/resource.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/statvfs.h>
#include <fcntl.h>

#define SANDBOX_NAMESPACE 1
#define FUSE_ROOT_ID 1
#define CACHE_AUTO 0
#define CACHE_NONE 1
#define CACHE_ALWAYS 2
#define FUSE_LOG_ERR 1
#define FUSE_LOG_INFO 2
#define FUSE_LOG_DEBUG 3

struct fuse_args {
    int argc;
    char **argv;
    int allocated;
};

struct fuse_session;
struct fuse_file_info;
struct fuse_conn_info;
struct fuse_pollhandle;
struct fuse_bufvec;
typedef int (*fuse_fill_dir_t)(void *buf, const char *name, const struct stat *stbuf, off_t off);

struct fuse_operations {
    int (*getattr)(const char *, struct stat *);
    int (*readlink)(const char *, char *, size_t);
    int (*mknod)(const char *, mode_t, dev_t);
    int (*mkdir)(const char *, mode_t);
    int (*unlink)(const char *);
    int (*rmdir)(const char *);
    int (*symlink)(const char *, const char *);
    int (*rename)(const char *, const char *);
    int (*link)(const char *, const char *);
    int (*chmod)(const char *, mode_t);
    int (*chown)(const char *, uid_t, gid_t);
    int (*truncate)(const char *, off_t);
    int (*open)(const char *, struct fuse_file_info *);
    int (*read)(const char *, char *, size_t, off_t, struct fuse_file_info *);
    int (*write)(const char *, const char *, size_t, off_t, struct fuse_file_info *);
    int (*statfs)(const char *, struct statvfs *);
    int (*flush)(const char *, struct fuse_file_info *);
    int (*release)(const char *, struct fuse_file_info *);
    int (*fsync)(const char *, int, struct fuse_file_info *);
    int (*setxattr)(const char *, const char *, const char *, size_t, int);
    int (*getxattr)(const char *, const char *, char *, size_t);
    int (*listxattr)(const char *, char *, size_t);
    int (*removexattr)(const char *, const char *);
    int (*opendir)(const char *, struct fuse_file_info *);
    int (*readdir)(const char *, void *, fuse_fill_dir_t, off_t, struct fuse_file_info *);
    int (*releasedir)(const char *, struct fuse_file_info *);
    int (*fsyncdir)(const char *, int, struct fuse_file_info *);
    void *(*init)(struct fuse_conn_info *conn);
    void (*destroy)(void *);
    int (*access)(const char *, int);
    int (*create)(const char *, mode_t, struct fuse_file_info *);
    int (*ftruncate)(const char *, off_t, struct fuse_file_info *);
    int (*fgetattr)(const char *, struct stat *, struct fuse_file_info *);
    int (*lock)(const char *, struct fuse_file_info *, int cmd, struct flock *);
    int (*utimens)(const char *, const struct timespec tv[2]);
    int (*bmap)(const char *, size_t blocksize, uint64_t *idx);
    int (*ioctl)(const char *, int cmd, void *arg, struct fuse_file_info *, unsigned int flags, void *data);
    int (*poll)(const char *, struct fuse_file_info *, struct fuse_pollhandle *ph, unsigned *reventsp);
    int (*write_buf)(const char *, struct fuse_bufvec *buf, off_t off, struct fuse_file_info *);
    int (*read_buf)(const char *, struct fuse_bufvec **bufp, size_t size, off_t off, struct fuse_file_info *);
    int (*flock)(const char *, struct fuse_file_info *, int op);
    int (*fallocate)(const char *, int, off_t, off_t, struct fuse_file_info *);
};

struct fuse_cmdline_opts {
    int singlethread;
    int foreground;
    int debug;
    int syslog;
    int show_help;
    int show_version;
    int print_capabilities;
    unsigned int rlimit_nofile;
    int log_level;
};

struct lo_data {
    int sandbox;
    int debug;
    int writeback;
    int posix_lock;
    int allow_direct_io;
    int proc_self_fd;
    int user_killpriv_v2;
    int user_posix_acl;
    char *source;
    int xattr;
    char *xattrmap;
    double timeout;
    int timeout_set;
    int cache;
    bool use_statx;
    pthread_mutex_t mutex;
    void *inodes;
    struct {
        int fd;
        unsigned long fuse_ino;
    } root;
    struct {
        void *map;
    } ino_map;
    struct {
        void *map;
    } dirp_map;
    struct {
        void *map;
    } fd_map;
};

struct lo_map_elem {
    bool in_use;
    void *inode;
};

struct fuse_opt {
    const char *templ;
    unsigned long offset;
    int value;
};

static int current_log_level;
static int use_syslog;
static struct fuse_operations lo_oper = {0};
static struct fuse_opt lo_opts[] = { {0} };
static void (*log_func)(int level, const char *fmt, ...);

static void *g_hash_table_new(unsigned int (*hash_func)(const void *), 
                            int (*key_equal_func)(const void *, const void *)) {
    return NULL;
}

static unsigned int lo_key_hash(const void *key) { return 0; }
static int lo_key_equal(const void *a, const void *b) { return 0; }
static void lo_map_init(void *map) {}
static void *lo_map_reserve(void *map, int id) { return NULL; }
static void fuse_log(int level, const char *fmt, ...) {}
static void qemu_init_exec_dir(const char *argv0) {}
static void fuse_set_log_func(void (*func)(int, const char *, ...)) {}
static void fuse_cmdline_help(void) {}
static void fuse_lowlevel_help(void) {}
static void qemu_version(void) {}
static void fuse_lowlevel_version(void) {}
static void print_capabilities(void) {}
static int fuse_parse_cmdline(struct fuse_args *args, struct fuse_cmdline_opts *opts) { return 0; }
static int fuse_opt_parse(struct fuse_args *args, void *data, const struct fuse_opt *opts, int (*proc)(void *, const char *, int)) { return 0; }
static void parse_xattrmap(struct lo_data *lo) {}
static struct fuse_session *fuse_session_new(struct fuse_args *args, const struct fuse_operations *op, size_t op_size, void *private_data) { return NULL; }
static int fuse_set_signal_handlers(struct fuse_session *se) { return 0; }
static int fuse_session_mount(struct fuse_session *se) { return 0; }
static void fuse_daemonize(int foreground) {}
static void setup_nofile_rlimit(unsigned int rlimit_nofile) {}
static void setup_capng(void) {}
static void setup_sandbox(struct lo_data *lo, struct fuse_session *se, int syslog) {}
static void setup_root(struct lo_data *lo, void *root) {}
static int virtio_loop(struct fuse_session *se) { return 0; }
static void fuse_session_unmount(struct fuse_session *se) {}
static void cleanup_capng(void) {}
static void fuse_remove_signal_handlers(struct fuse_session *se) {}
static void fuse_session_destroy(struct fuse_session *se) {}
static void fuse_opt_free_args(struct fuse_args *args) {}
static void fuse_lo_data_cleanup(struct lo_data *lo) {}

#define FUSE_ARGS_INIT(argc, argv) {argc, argv, 0}