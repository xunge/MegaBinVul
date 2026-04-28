#include <string.h>
#include <stdlib.h>

struct fsck_gitmodules_data {
    void *options;
    void *obj;
    int ret;
};

enum fsck_msg_type {
    FSCK_MSG_GITMODULES_NAME,
    FSCK_MSG_GITMODULES_URL,
    FSCK_MSG_GITMODULES_PATH
};

extern int parse_config_key(const char *var, const char *section,
                          const char **subsection, int *subsection_len,
                          const char **key);
extern int check_submodule_name(const char *name);
extern int looks_like_command_line_option(const char *value);
extern char *xmemdupz(const char *data, size_t len);
extern int report(void *options, void *obj, enum fsck_msg_type msg_type,
                 const char *fmt, ...);