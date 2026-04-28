#include <stddef.h>
#include <stdbool.h>

#define FEAT_FIND_ID
#define FEAT_EVAL
#define FNAME_INCL 1
#define FNAME_EXP 2
#define FNAME_MESS 4
#define NUL '\0'
#define TRUE true
#define FALSE false

typedef char char_u;

struct buf {
    char_u *b_p_inex;
};

extern struct buf *curbuf;

char_u *eval_includeexpr(char_u *ptr, int len);
char_u *find_file_in_path(char_u *ptr, int len, int options, bool first, char_u *rel_fname);
void vim_free(void *ptr);
char_u *vim_strnsave(char_u *ptr, int len);
size_t STRLEN(const char_u *str);
void semsg(const char *msg, ...);
#define _(x) x