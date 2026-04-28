#include <stdio.h>
#include <string.h>

typedef unsigned char char_u;
typedef int bool;
#define FALSE 0
#define TRUE 1

#define NUL '\0'
#define FAIL 0
#define DIP_ALL 0
#define EVENT_SPELLFILEMISSING 0

#define STRCPY(d, s) strcpy((char *)(d), (char *)(s))
#define STRLEN(s) strlen((char *)(s))
#define _(x) x

typedef struct {
    char_u *sl_lang;
    void *sl_slang;
    bool sl_nobreak;
} spelload_T;

typedef struct {
    int b_locked;
    char *b_fname;
} buf_T;

extern buf_T *curbuf;
extern char *spell_enc();
extern int do_in_runtimepath(char_u *fname, int flags, void (*callback)(), void *cookie);
extern int apply_autocmds(int event, char_u *pat, char_u *fname, int force, buf_T *buf);
extern void vim_snprintf(char *str, size_t size, const char *format, ...);
extern void smsg(const char *fmt, ...);
extern void spell_load_cb();