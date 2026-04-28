#include <stdlib.h>
#include <string.h>

struct dump_dir {
    char *dd_dirname;
    unsigned dd_uid;
    unsigned dd_gid;
    unsigned mode;
    int locked;
};

extern int str_is_correct_filename(const char *name);
extern void error_msg_and_die(const char *fmt, ...);
extern char *concat_path_file(const char *dir, const char *filename);
extern void save_binary_file(const char *path, const char *data, unsigned size, unsigned uid, unsigned gid, unsigned mode);