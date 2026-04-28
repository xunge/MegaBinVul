#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <signal.h>
#include <dirent.h>
#include <errno.h>
#include <stdbool.h>
#include <limits.h>

#define LOGMODE_JOURNAL 1
#define DEFAULT_DUMP_DIR_MODE 0755
#define VAR_RUN "/var/run"
#define FILENAME_COREDUMP "coredump"
#define FILENAME_MAPS "maps"
#define FILENAME_LIMITS "limits"
#define FILENAME_CGROUP "cgroup"
#define FILENAME_OPEN_FDS "open_fds"
#define FILENAME_ANALYZER "analyzer"
#define FILENAME_TYPE "type"
#define FILENAME_EXECUTABLE "executable"
#define FILENAME_PID "pid"
#define FILENAME_PROC_PID_STATUS "proc_pid_status"
#define FILENAME_PWD "pwd"
#define FILENAME_ROOTDIR "rootdir"
#define FILENAME_REASON "reason"
#define FILENAME_CMDLINE "cmdline"
#define FILENAME_ENVIRON "environ"
#define FILENAME_ABRT_VERSION "abrt_version"
#define FILENAME_BINARY "binary"
#define COPYFD_SPARSE 1
#define O_EXCL 0200
#define DUMP_SUID_UNSAFE 0
#define VERSION "1.0.0"

typedef struct {
    char *dd_dirname;
    uid_t dd_uid;
    gid_t dd_gid;
} dump_dir_t;

typedef struct {
    char *item;
    char *value;
} map_string_t;

int xopen(const char *pathname, int flags);
int xdup(int oldfd);
void error_msg(const char *format, ...);
void error_msg_and_die(const char *format, ...);
char *strchrnul(const char *s, int c);
void load_abrt_conf();
map_string_t *new_map_string();
void load_abrt_plugin_conf_file(const char *filename, map_string_t *settings);
const char *get_map_string_item_or_NULL(map_string_t *settings, const char *key);
bool string_to_bool(const char *value);
int xatoi_positive(const char *str);
void perror_msg(const char *format, ...);
void perror_msg_and_die(const char *format, ...);
char *xmalloc_fopen_fgetline_fclose(const char *filename);
char *get_executable(pid_t pid, int *src_fd_binary);
char *get_cwd(pid_t pid);
void log_notice(const char *format, ...);
void log(const char *format, ...);
char *xmalloc_xopen_read_close(const char *path, size_t *maxsz);
uid_t get_fsuid();
int dump_suid_policy();
int open_user_core(uid_t uid, uid_t fsuid, pid_t pid, char **argv);
bool daemon_is_ok();
bool low_free_space(off_t max_size, const char *path);
bool check_recent_crash_file(const char *path, const char *executable);
char *iso_date_string(time_t *time);
dump_dir_t *dd_create_skeleton(const char *path, uid_t uid, mode_t mode, int flags);
void dd_create_basic_files(dump_dir_t *dd, uid_t fsuid, const char *rootdir);
char *get_rootdir(pid_t pid);
char *concat_path_file(const char *path, const char *filename);
void copy_file_ext(const char *src, const char *dst, mode_t mode, uid_t uid, gid_t gid, int src_flags, int dst_flags);
void dump_fd_info(const char *dst, const char *src, int src_base_ofs, uid_t uid, gid_t gid);
void dd_save_text(dump_dir_t *dd, const char *filename, const char *text);
char *xasprintf(const char *format, ...);
char *get_cmdline(pid_t pid);
char *get_environ(pid_t pid);
int create_or_die(const char *path);
off_t copyfd_eof(int src_fd, int dst_fd, int flags);
void dd_delete(dump_dir_t *dd);
off_t copyfd_sparse(int src_fd, int dst_fd1, int dst_fd2, off_t maxsize);
void dd_reset_ownership(dump_dir_t *dd);
void dd_close(dump_dir_t *dd);
char *xstrndup(const char *s, size_t n);
void notify_new_path(const char *path);
void trim_problem_dirs(const char *dump_location, double max_size, const char *path);
void free_map_string(map_string_t *settings);
int xopen3(const char *path, int flags, mode_t mode);

int logmode;
bool g_verbose;
int g_user_core_flags;
int g_need_nonrelative;
bool g_settings_privatereports;
off_t g_settings_nMaxCrashReportsSize;
char *g_settings_dump_location;
char *core_basename;
char *proc_pid_status;
char *user_pwd;
int user_core_fd;
DIR *proc_cwd;
dump_dir_t *dd;