#include <stdlib.h>
#include <string.h>

struct dump_dir {
    char *dd_dirname;
    int locked;
    uid_t dd_uid;
    gid_t dd_gid;
    mode_t mode;
};

extern char *concat_path_file(const char *path, const char *filename);
extern void save_binary_file(const char *path, const void *data, size_t size, uid_t uid, gid_t gid, mode_t mode);
extern void error_msg_and_die(const char *format, ...);