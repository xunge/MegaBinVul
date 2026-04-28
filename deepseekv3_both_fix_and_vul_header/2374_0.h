#include <string.h>
#include <stdlib.h>

struct line_info_table {
    unsigned int num_files;
    unsigned int num_dirs;
    char **dirs;
    char *comp_dir;
    struct {
        char *name;
        unsigned int dir;
    } *files;
};

#define IS_ABSOLUTE_PATH(filename) ((filename)[0] == '/')

extern void _bfd_error_handler(const char *fmt, ...);
extern void *bfd_malloc(size_t size);