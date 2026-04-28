#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <regex.h>
#include <ctype.h>

typedef unsigned char char_u;
typedef int colnr_T;

typedef struct {
    int ga_len;
    void *ga_data;
} garray_T;

typedef struct {
    int rm_ic;
    regex_t *regprog;
} regmatch_T;

typedef struct stat stat_T;

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define EW_ICASE 1
#define EW_NOERROR 2
#define EW_NOTWILD 4
#define EW_DODOT 8
#define EW_ALLLINKS 16
#define RE_MAGIC REG_EXTENDED
#define BASENAMELEN 256
#define PTR2CHAR(x) (*x)
#define STRLEN strlen
#define STRMOVE(d, s) memmove(d, s, strlen(s)+1)
#define STRCPY strcpy
#define STRNCPY strncpy
#define vim_strchr strchr
#define vim_free free
#define vim_regcomp(preg, pattern) regcomp(preg, (const char *)pattern, RE_MAGIC)
#define vim_regfree regfree
#define vim_regexec(a, b, c) regexec((a)->regprog, (b), 0, NULL, 0)
#define alloc malloc
#define ui_breakcheck()
#define got_int 0
#define p_fic 0
static int emsg_silent = 0;
#define has_mbyte 0
static int (*mb_ptr2len)(char_u *) = NULL;
#define mch_has_exp_wildcard(x) 0
#define mch_lstat lstat
#define mch_getperm(x) 0
#define backslash_halve(x)
#define addfile(x, y, z)
static int pstrcmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
#define rem_backslash(x) 0
#define file_pat_to_reg_pat(x, y, z, w) NULL
#define fnamencmp(x, y, n) strncmp(x, y, n)