#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>

typedef struct stream_s stream;
typedef struct gs_parsed_file_name_s {
    const char *fname;
    size_t len;
    struct {
        struct {
            int (*file_status)(void*, const char*, struct stat*);
        } procs;
    } *iodev;
} gs_parsed_file_name_t;
typedef struct i_ctx_s {
    int LockFilePermissions;
} i_ctx_t;
typedef struct ref_s {
    int type;
    union {
        int intval;
        int boolval;
    } value;
} ref;
typedef ref *os_ptr;

extern os_ptr osp;
extern void *imemory;

enum {
    t_file,
    t_string,
    t_boolean,
    t_integer,
    gs_error_undefinedfilename,
    gs_error_typecheck,
    gs_error_limitcheck
};

#define r_type(op) ((op)->type)
#define make_bool(op, val) ((op)->value.boolval = (val), (op)->type = t_boolean)
#define make_int(op, val) ((op)->value.intval = (val), (op)->type = t_integer)
#define push(n) (osp += (n))
#define check_ostack(n) (0)
#define return_error(code) (code)
#define return_op_typecheck(op) (gs_error_typecheck)

static int file_is_valid(stream *s, os_ptr op);
static int parse_file_name(os_ptr op, gs_parsed_file_name_t *pname, int perms, void *imemory);
static int gs_terminate_file_name(gs_parsed_file_name_t *pname, void *imemory, const char *mode);
static int check_file_permissions(i_ctx_t *i_ctx_p, const char *fname, size_t len, const char *permission);
static void gs_free_file_name(gs_parsed_file_name_t *pname, const char *mode);
static long stat_blocks(const struct stat *fstat);