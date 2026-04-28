#include <stddef.h>
#include <string.h>

typedef unsigned char char_u;
typedef int int_T;
typedef struct cctx_T cctx_T;
typedef struct {} type_T;
typedef int isntype_T;

#define FAIL 1
#define ISN_LOADENV ((isntype_T)0)

static type_T t_string;

extern int get_env_len(char_u **arg);
extern char_u *vim_strnsave(const char_u *str, size_t len);
extern void vim_free(void *ptr);
extern int generate_LOAD(cctx_T *cctx, isntype_T isn, int argcount, char_u *name, type_T *type);
extern void semsg(const char *msg, ...);
extern const char *e_syntax_error_at_str;
extern const char *_(const char *str);