#include <stdint.h>

#define GIT_PATH_REJECT_WORKDIR_DEFAULTS (1u << 0)
#define GIT_PATH_REJECT_DOT_GIT_NTFS (1u << 1)
#define CHECKOUT_ACTION__REMOVE (1u << 0)

typedef struct {
    const char *path;
    uint16_t mode;
} git_diff_file;

typedef struct {
    git_diff_file old_file;
    git_diff_file new_file;
} git_diff_delta;

typedef struct git_repository git_repository;

enum {
    GIT_ERROR_CHECKOUT = 1
};

void git_error_set(int error_class, const char *message, ...);
int git_path_isvalid(git_repository *repo, const char *path, uint16_t mode, unsigned int flags);