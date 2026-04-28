#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAXWLEN 256
#define NUL '\0'
#define TRUE 1
#define FALSE 0
#define BO_SPELL 0
#define FORWARD 1
#define OK 1
#define ESC 27
#define IOSIZE 1024
#define Rows 25
#define Columns 80

typedef unsigned char char_u;
typedef long colnr_T;

typedef struct {
    colnr_T col;
    int lnum;
} pos_T;

typedef struct {
    int ga_len;
    void *ga_data;
} garray_T;

typedef struct {
    char_u *st_word;
    int st_wordlen;
    int st_orglen;
    int st_score;
    int st_altscore;
    int st_salscore;
} suggest_T;

typedef struct {
    char_u *su_badptr;
    int su_badlen;
    garray_T su_ga;
} suginfo_T;

typedef struct buf_S {
    char_u *b_p_spl;
} buf_S;

typedef struct win_S {
    pos_T w_cursor;
    buf_S *w_s;
    int w_p_spell;
    int w_p_rl;
} win_T;

extern win_T *curwin;
extern int VIsual_active;
extern pos_T VIsual;
extern int sps_limit;
extern int sps_flags;
extern int p_verbose;
extern int msg_scroll;
extern int cmdmsg_rl;
extern int msg_row;
extern int msg_col;
extern int lines_left;
extern char_u IObuff[IOSIZE];
extern char_u *repl_from;
extern char_u *repl_to;

#define SUG(ga, i) ((suggest_T *)((ga).ga_data))[i]
#define SPS_DOUBLE 1
#define SPS_BEST 2
#define STRLEN(s) strlen((char *)(s))
#define STRCPY(d, s) strcpy((char *)(d), (char *)(s))
#define STRCAT(d, s) strcat((char *)(d), (char *)(s))
#define STRNCMP(s1, s2, n) strncmp((char *)(s1), (char *)(s2), (n))
#define MB_PTR_BACK(s, p) ((p)--)
#define MB_PTR_ADV(p) ((p)++)
#define mch_memmove(d, s, n) memmove((d), (s), (n))

#define _(x) x
#define e_spell_checking_is_not_possible "e_spell_checking_is_not_possible"

void did_set_spelllang(win_T *win);
void emsg(const char *msg);
void vim_beep(int type);
void end_visual_mode();
int spell_move_to(win_T *win, int dir, int allwords, int keepcap, char_u *capcol);
char_u *ml_get_curline();
int spell_iswordp_nmw(char_u *p, win_T *win);
void beep_flush();
int check_need_cap(int lnum, colnr_T col);
char_u *vim_strsave(char_u *str);
void spell_find_suggest(char_u *badptr, int badlen, suginfo_T *su, int maxcount, int banbadword, int need_cap, int interactive);
void msg(const char *str);
void smsg(const char *str, long n);
void msg_start();
void msg_puts(const char *str);
void msg_clr_eos();
void msg_putchar(char c);
void msg_advance(int col);
void rl_mirror(char_u *str);
int prompt_for_number(int *mouse_used);
int u_save_cursor();
void VIM_CLEAR(void *ptr);
char_u *vim_strnsave(char_u *str, int len);
char_u *alloc(size_t size);
void ResetRedobuff();
void AppendToRedobuff(char_u *str);
void AppendToRedobuffLit(char_u *str, int len);
void AppendCharToRedobuff(int c);
void ml_replace(int lnum, char_u *line, int copy);
void changed_bytes(int lnum, colnr_T col);
void spell_find_cleanup(suginfo_T *su);
void vim_free(void *ptr);
void vim_strncpy(char_u *to, char_u *from, size_t len);
int vim_snprintf(char *str, size_t size, const char *format, ...);