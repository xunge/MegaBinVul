#include <stdio.h>
#include <string.h>

#define MAXWLEN 256
#define IOSIZE 1024
#define DUMPFLAG_ICASE 1
#define DUMPFLAG_ONECAP 2
#define DUMPFLAG_ALLCAP 4
#define DUMPFLAG_KEEPCASE 8
#define WF_ONECAP 1
#define WF_ALLCAP 2
#define WF_KEEPCAP 4
#define WF_NEEDCOMP 8
#define WF_REGION 16
#define FALSE 0
#define TRUE 1
#define NUL '\0'

typedef unsigned char char_u;
typedef long idx_T;
typedef long linenr_T;
typedef int colnr_T;

typedef struct slang_S slang_T;
typedef struct langp_S langp_T;

struct slang_S {
    char_u *sl_regions;
    char_u *sl_fname;
    char_u *sl_fbyts;
    idx_T *sl_fidxs;
    char_u *sl_kbyts;
    idx_T *sl_kidxs;
    char_u *sl_pbyts;
};

struct langp_S {
    slang_T *lp_slang;
    int lp_region;
};

typedef struct {
    int ga_len;
    langp_T *ga_data;
} garray_T;

typedef struct {
    garray_T b_langp;
} bufstate_T;

typedef struct {
    bufstate_T *w_s;
} win_T;

#define LANGP_ENTRY(ga, i)  ((langp_T *)(ga).ga_data + (i))
#define STRCMP strcmp

extern win_T *curwin;
extern int got_int;
extern char_u IObuff[IOSIZE];

int captype(char_u *word, char_u *end);
int MB_STRNICMP(char_u *s1, char_u *s2, size_t len);
size_t STRLEN(char_u *str);
size_t mb_ptr2len(char_u *str);
void vim_snprintf(char *str, size_t size, const char *format, ...);
void ml_append(linenr_T lnum, char_u *line, colnr_T len, int newfile);
int ins_compl_interrupted(void);
void ins_compl_check_keys(int timeout, int yield);
void line_breakcheck(void);
void dump_word(slang_T *slang, char_u *word, char_u *pat, int *dir, int dumpflags, int flags, linenr_T lnum);
linenr_T dump_prefixes(slang_T *slang, char_u *word, char_u *pat, int *dir, int dumpflags, int flags, linenr_T lnum);