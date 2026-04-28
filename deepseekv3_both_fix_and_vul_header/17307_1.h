#include <string.h>

typedef struct gs_memory_s gs_memory_t;
typedef struct i_ctx_s i_ctx_t;
typedef struct gs_parsed_file_name_s gs_parsed_file_name_t;
typedef struct iodev_s iodev_t;

struct iodev_s {
    const char *dname;
};

struct gs_parsed_file_name_s {
    iodev_t *iodev;
};

struct gs_minst_s {
    i_ctx_t *i_ctx_p;
};

struct i_ctx_s {
    int LockFilePermissions;
};

extern struct gs_minst_s *get_minst_from_memory(gs_memory_t *mem);
extern int gs_parse_file_name(gs_parsed_file_name_t *pname, const char *fname, int len, void *imemory);
extern int check_file_permissions(i_ctx_t *i_ctx_p, const char *fname, const int len, const char *permitgroup);
extern void *imemory;

#define gs_error_invalidfileaccess (-1)