#include <stddef.h>
#include <stdlib.h>

typedef unsigned char char_u;
typedef struct buf_S buf_T;
typedef struct window_S win_T;
typedef struct regmatch_S regmatch_T;

struct buf_S {
    int b_fnum;
    int b_p_bl;
};

struct window_S {
    buf_T *w_buffer;
    int w_alt_fnum;
};

struct regmatch_S {
    void *regprog;
};

extern buf_T *curbuf;
extern win_T *curwin;

#define FALSE 0
#define TRUE 1
#define RE_MAGIC 0
#define NUL '\0'
#define FEAT_DIFF
#define UNUSED __attribute__((unused))

int in_vim9script(void);
int diff_mode_buf(buf_T *buf);
buf_T *buflist_findnr(int fnum);
char_u *file_pat_to_reg_pat(char_u *pattern, char_u *pattern_end, void *allow_dirs, int no_bslash);
size_t STRLEN(const char_u *str);
void *vim_regcomp(char_u *pattern, int flags);
void vim_regfree(void *regprog);
void vim_free(void *ptr);
char_u *buflist_match(regmatch_T *regmatch, buf_T *buf, int ignore_case);
int magic_isset(void);
void semsg(const char *msg, ...);
#define _(x) x
#define e_more_than_one_match_for_str "E93: More than one match for %s"
#define e_no_matching_buffer_for_str "E94: No matching buffer for %s"

#define FOR_ALL_BUFS_FROM_LAST(buf) /* implementation */
#define FOR_ALL_WINDOWS(wp) /* implementation */