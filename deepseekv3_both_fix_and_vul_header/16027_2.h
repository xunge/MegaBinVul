#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char char_u;
typedef int int_T;

typedef struct slang_T slang_T;
typedef struct langp_T langp_T;
typedef struct bufref_T bufref_T;

typedef struct garray_T {
    int ga_len;
    void *ga_data;
    int ga_maxlen;
    int ga_itemsize;
} garray_T;

struct slang_T {
    char_u *sl_fname;
    char_u *sl_name;
    char_u *sl_regions;
    int sl_nobreak;
    slang_T *sl_next;
    garray_T sl_sal;
    garray_T sl_rep;
    int sl_add;
};

struct langp_T {
    slang_T *lp_slang;
    slang_T *lp_sallang;
    slang_T *lp_replang;
    int lp_region;
};

struct bufref_T {
    void *br_buf;
};

typedef struct synblock_T {
    char_u *b_p_spl;
    char_u *b_p_spf;
    int b_cjk;
    garray_T b_langp;
} synblock_T;

typedef struct win_T {
    void *w_buffer;
    synblock_T *w_s;
} win_T;

#define NUL '\0'
#define FALSE 0
#define TRUE 1
#define MAXWLEN 64
#define MAXPATHL 256
#define FPC_SAME 0
#define FAIL -1
#define OK 0
#define REGION_ALL 0
#define UPD_NOT_VALID 0

#define FOR_ALL_SPELL_LANGS(slang) for ((slang) = first_lang; (slang) != NULL; (slang) = (slang)->sl_next)
#define LANGP_ENTRY(ga, idx) ((langp_T *)(ga).ga_data + (idx))
#define ASCII_ISALPHA(c) isalpha((unsigned char)(c))

extern slang_T *first_lang;
extern char_u *int_wordlist;
extern char *e_out_of_memory;
extern char *e_spellfilemising_autocommand_deleted_buffer;
extern win_T *curwin;

void ga_init2(garray_T *gap, int itemsize, int growsize);
void ga_clear(garray_T *gap);
int ga_grow(garray_T *gap, int n);
void clear_midword(win_T *wp);
void use_midword(slang_T *slang, win_T *wp);
int valid_spelllang(char_u *lang);
int find_region(char_u *regions, char_u *region);
void copy_option_part(char_u **option, char_u *buf, int maxlen, char *sep);
char_u *vim_strsave(char_u *str);
char_u *vim_strchr(char_u *string, int c);
char_u *gettail(char_u *fname);
int fnamecmp(char_u *fname1, char_u *fname2);
int fullpathcmp(char_u *fname1, char_u *fname2, int checkname, int expandenv);
int STRCMP(char_u *s1, char_u *s2);
int STRICMP(char_u *s1, char_u *s2);
int STRNCMP(char_u *s1, char_u *s2, size_t n);
size_t STRLEN(char_u *str);
void STRCAT(char_u *to, char_u *from);
void STRCPY(char_u *to, char_u *from);
void vim_strncpy(char_u *to, char_u *from, size_t len);
void mch_memmove(void *to, void *from, size_t len);
slang_T *spell_load_file(char_u *fname, char_u *lang, char_u *region, int silent);
void spell_load_lang(char_u *lang);
int bufref_valid(bufref_T *bufref);
void set_bufref(bufref_T *bufref, void *buf);
void int_wordlist_spl(char_u *fname);
void redraw_win_later(win_T *wp, int type);
const char *_(const char *str);
const char *N_(const char *str);
void smsg(const char *fmt, ...);
void vim_free(void *ptr);