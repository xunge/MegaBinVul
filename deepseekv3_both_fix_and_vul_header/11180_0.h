#include <stdlib.h>
#include <string.h>

typedef enum {
    M_FS_SYSTEM_UNIX,
    M_FS_SYSTEM_WINDOWS
} M_fs_system_t;

typedef struct M_list_str_t M_list_str_t;

size_t M_list_str_len(const M_list_str_t *list);
M_list_str_t *M_list_str_duplicate(const M_list_str_t *list);
const char *M_list_str_at(const M_list_str_t *list, size_t idx);
void M_list_str_remove_at(M_list_str_t *list, size_t idx);
void M_list_str_destroy(M_list_str_t *list);
void M_list_str_insert_at(M_list_str_t *list, const char *str, size_t idx);
char *M_list_str_join(const M_list_str_t *list, unsigned char sep);

M_fs_system_t M_fs_path_get_system_type(M_fs_system_t sys_type);
unsigned char M_fs_path_get_system_sep(M_fs_system_t sys_type);
int M_fs_path_isabs(const char *path, M_fs_system_t sys_type);

char *M_strdup(const char *str);