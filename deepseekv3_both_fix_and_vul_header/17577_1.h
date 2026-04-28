#include <stdbool.h>
#include <string.h>
#include <strings.h>

#define GIT_INLINE(type) static inline type

typedef struct git_buf {
    char *ptr;
    size_t size;
} git_buf;

typedef struct git_repository git_repository;

extern git_buf *git_repository__reserved_names_win32;
extern size_t git_repository__reserved_names_win32_len;

void git_repository__reserved_names(git_buf **reserved, size_t *reserved_len, git_repository *repo, bool include_ntfs);