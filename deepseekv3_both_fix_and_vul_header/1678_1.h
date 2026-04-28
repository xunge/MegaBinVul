#include <stdlib.h>
#include <string.h>

typedef unsigned char char_u;

#define FAIL 1
#define OK 0
#define FALSE 0
#define TRUE 1
#define FEAT_VIMINFO 1
#define FEAT_DIFF 1
#define BUF_DIFF_FILTER 1
#define WILD_HOME_REPLACE 1
#define WILD_BUFLASTUSED 1
#define RE_MAGIC 1
#define STRLEN(s) strlen((char *)(s))
#define STRCPY(d, s) strcpy((char *)(d), (char *)(s))
#define ALLOC_MULT(type, count) ((type *)malloc((count) * sizeof(type)))
#define vim_free free
#define vim_strsave strdup
#define alloc malloc

typedef struct {
    void *regprog;
} regmatch_T;

typedef struct win_S {
    int w_p_diff;
} win_T;

typedef struct buf_S {
    int b_p_bl;
    char_u *b_sfname;
    char_u *b_ffname;
    struct buf_S *b_next;
} buf_T;

typedef struct {
    buf_T *buf;
    char_u *match;
} bufmatch_T;

typedef struct {
    int idx;
    char_u *str;
    int score;
} fuzmatch_str_T;

#define FOR_ALL_BUFFERS(buf) for (buf = firstbuf; buf != NULL; buf = buf->b_next)

extern int cmdline_fuzzy_complete(char_u *pat);
extern void *vim_regcomp(char_u *pat, int magic);
extern void vim_regfree(void *regprog);
extern char_u *buflist_match(regmatch_T *regmatch, buf_T *buf, int p_wic);
extern int fuzzy_match_str(char_u *str, char_u *pat);
extern char_u *home_replace_save(buf_T *buf, char_u *p);
extern int fuzzymatches_to_strmatches(fuzmatch_str_T *fuzmatch, char_u ***file, int count, int sort);
extern int buf_compare(const void *a, const void *b);
extern int diff_mode_buf(buf_T *buf);
extern int p_wic;
extern buf_T *curbuf;
extern win_T *curwin;
extern buf_T *firstbuf;