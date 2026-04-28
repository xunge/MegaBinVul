#include <stddef.h>

typedef unsigned char char_u;
typedef int isntype_T;

#define SKIP_YES 1
#define OK 1
#define FAIL 0
#define FNE_CHECK_START 0
#define ISN_EXEC 0
#define ISN_LOCKUNLOCK 1
#define CMD_lockvar 0
#define NUL '\0'
#define FALSE 0

typedef struct {
    char_u *ll_name;
} lval_T;

typedef struct {
    int cmdidx;
} exarg_T;

typedef struct {
    int ctx_skip;
} cctx_T;

#define _(x) x
#define e_argument_required_for_str ""
#define e_cannot_lock_unlock_local_variable ""

char_u *find_name_end(char_u *p, void *arg1, void *arg2, int flag);
int lookup_local(char_u *p, int len, void *arg, cctx_T *cctx);
int compile_load(char_u **s, char_u *end, cctx_T *cctx, int flag1, int flag2);
char_u *alloc(size_t len);
int vim_snprintf(char *str, size_t size, const char *format, ...);
int generate_EXEC_copy(cctx_T *cctx, isntype_T isn, char_u *buf);
void vim_free(char_u *p);
void emsg(const char *msg);
void semsg(const char *msg, const char *cmd);