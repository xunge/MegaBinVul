#include <stddef.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char char_u;

typedef struct {
    int cmod_flags;
} cmdmod_T;

typedef struct {
    char_u *b_p_isk;
    int b_p_initialized;
    int b_help;
    char_u *b_p_bt;
    int b_p_ro;
    int b_p_tx;
    char_u *b_p_fenc;
    char_u *b_p_ff;
    char b_start_ffc;
    char_u *b_p_bh;
    char_u *empty_option;
    int b_p_ai;
    int b_p_ai_nopaste;
    int b_p_sw;
    int b_p_tw;
    int b_p_tw_nopaste;
    int b_p_tw_nobin;
    int b_p_wm;
    int b_p_wm_nopaste;
    int b_p_wm_nobin;
    int b_p_bin;
    int b_p_bomb;
    int b_p_fixeol;
    int b_p_et;
    int b_p_et_nobin;
    int b_p_et_nopaste;
    int b_p_ml;
    int b_p_ml_nobin;
    int b_p_inf;
    int b_p_swf;
    char_u *b_p_cpt;
    char_u *b_p_csl;
    char_u *b_p_cfu;
    char_u *b_p_ofu;
    char_u *b_p_tfu;
    int b_p_sts;
    int b_p_sts_nopaste;
    char_u *b_p_vsts;
    int *b_p_vsts_array;
    char_u *b_p_vsts_nopaste;
    int b_p_sn;
    char_u *b_p_com;
    char_u *b_p_cms;
    char_u *b_p_fo;
    char_u *b_p_flp;
    char_u *b_p_nf;
    char_u *b_p_mps;
    int b_p_si;
    int b_p_ci;
    int b_p_cin;
    char_u *b_p_cink;
    char_u *b_p_cino;
    char_u *b_p_ft;
    int b_p_pi;
    char_u *b_p_cinw;
    int b_p_lisp;
    char_u *b_p_syn;
    int b_p_smc;
    struct {
        char_u *b_syn_isk;
        char_u *b_p_spc;
        char_u *b_p_spf;
        char_u *b_p_spl;
        char_u *b_p_spo;
    } b_s;
    char_u *b_p_inde;
    char_u *b_p_indk;
    char_u *b_p_fp;
    char_u *b_p_fex;
    char_u *b_p_key;
    char_u *b_p_sua;
    char_u *b_p_keymap;
    int b_kmap_state;
    int b_p_twsl;
    int b_p_iminsert;
    int b_p_imsearch;
    int b_p_ar;
    int b_p_ul;
    char_u *b_p_bkc;
    int b_bkc_flags;
    char_u *b_p_gp;
    char_u *b_p_mp;
    char_u *b_p_efm;
    char_u *b_p_ep;
    char_u *b_p_kp;
    char_u *b_p_path;
    char_u *b_p_tags;
    char_u *b_p_tc;
    int b_tc_flags;
    char_u *b_p_def;
    char_u *b_p_inc;
    char_u *b_p_inex;
    char_u *b_p_dict;
    char_u *b_p_tsr;
    char_u *b_p_qe;
    char_u *b_p_bexpr;
    char_u *b_p_cm;
    int b_p_udf;
    char_u *b_p_lw;
    char_u *b_p_menc;
    int b_p_ts;
    char_u *b_p_vts;
    int b_p_ma;
} buf_T;

#define CPO_BUFOPTGLOB 'S'
#define CPO_BUFOPT 's'
#define BCO_ENTER 1
#define BCO_ALWAYS 2
#define BCO_NOHELP 4
#define CMOD_NOSWAPFILE 1
#define KEYMAP_INIT 1
#define NO_LOCAL_UNDOLEVEL -1

#define FF_MAC "mac"
#define FF_DOS "dos"
#define FF_UNIX "unix"

extern char_u *p_cpo;
extern char_u *p_isk;
extern char_u *p_fenc;
extern char_u *p_ffs;
extern char_u *p_ff;
extern int p_ai;
extern int p_ai_nopaste;
extern int p_sw;
extern int p_tw;
extern int p_tw_nopaste;
extern int p_tw_nobin;
extern int p_wm;
extern int p_wm_nopaste;
extern int p_wm_nobin;
extern int p_bin;
extern int p_bomb;
extern int p_fixeol;
extern int p_et;
extern int p_et_nobin;
extern int p_et_nopaste;
extern int p_ml;
extern int p_ml_nobin;
extern int p_inf;
extern int p_swf;
extern char_u *p_cpt;
extern char_u *p_csl;
extern char_u *p_cfu;
extern char_u *p_ofu;
extern char_u *p_tfu;
extern int p_sts;
extern int p_sts_nopaste;
extern char_u *p_vsts;
extern char_u *p_vsts_nopaste;
extern int p_sn;
extern char_u *p_com;
extern char_u *p_cms;
extern char_u *p_fo;
extern char_u *p_flp;
extern char_u *p_nf;
extern char_u *p_mps;
extern int p_si;
extern int p_ci;
extern int p_cin;
extern char_u *p_cink;
extern char_u *p_cino;
extern int p_pi;
extern char_u *p_cinw;
extern int p_lisp;
extern int p_smc;
extern char_u *p_spc;
extern char_u *p_spf;
extern char_u *p_spl;
extern char_u *p_spo;
extern char_u *p_inde;
extern char_u *p_indk;
extern char_u *p_fex;
extern char_u *p_key;
extern char_u *p_sua;
extern char_u *p_keymap;
extern int p_twsl;
extern int p_iminsert;
extern int p_imsearch;
extern int p_udf;
extern int p_tx;
extern int p_ts;
extern int p_ma;
extern cmdmod_T cmdmod;

static char_u empty_option[] = "";

char_u *vim_strchr(const char_u *str, int c);
char_u *vim_strsave(const char_u *str);
void free_buf_options(buf_T *buf, int free_strings);
void check_buf_options(buf_T *buf);
int buf_init_chartab(buf_T *buf, int global);
void clear_string_option(char_u **pp);
void tabstop_set(char_u *var, int **array);
void init_buf_opt_idx(void);

#define COPY_OPT_SCTX(buf, idx) /* empty */
#define CLEAR_FIELD(field) /* empty */