#include <stddef.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char char_u;

#define CPO_BUFOPTGLOB 'S'
#define CPO_BUFOPT 's'
#define BCO_ENTER 1
#define BCO_ALWAYS 2
#define BCO_NOHELP 4

#define FF_MAC "mac"
#define FF_DOS "dos"
#define FF_UNIX "unix"

#define NO_LOCAL_UNDOLEVEL -1
#define KEYMAP_INIT 1

#define BV_AI 0
#define BV_SW 1
#define BV_TW 2
#define BV_WM 3
#define BV_BIN 4
#define BV_BOMB 5
#define BV_FIXEOL 6
#define BV_ET 7
#define BV_ML 8
#define BV_INF 9
#define BV_SWF 10
#define BV_CPT 11
#define BV_CSL 12
#define BV_CFU 13
#define BV_OFU 14
#define BV_TFU 15
#define BV_STS 16
#define BV_VSTS 17
#define BV_SN 18
#define BV_COM 19
#define BV_CMS 20
#define BV_FO 21
#define BV_FLP 22
#define BV_NF 23
#define BV_MPS 24
#define BV_SI 25
#define BV_CI 26
#define BV_CIN 27
#define BV_CINK 28
#define BV_CINO 29
#define BV_PI 30
#define BV_CINW 31
#define BV_LISP 32
#define BV_SMC 33
#define BV_SPC 34
#define BV_SPF 35
#define BV_SPL 36
#define BV_SPO 37
#define BV_INDE 38
#define BV_INDK 39
#define BV_FEX 40
#define BV_KEY 41
#define BV_SUA 42
#define BV_KMAP 43
#define BV_TWSL 44
#define BV_IMI 45
#define BV_IMS 46
#define BV_INEX 47
#define BV_QE 48
#define BV_UDF 49
#define BV_ISK 50
#define BV_TS 51
#define BV_VTS 52
#define BV_MA 53

#define CMOD_NOSWAPFILE 1

typedef struct {
    int cmod_flags;
} cmdmod_T;

typedef struct {
    char_u *b_p_isk;
    int b_p_initialized;
    int b_help;
    int b_p_ro;
    int b_p_tx;
    char_u *b_p_fenc;
    char_u *b_p_ff;
    char_u b_start_ffc;
    char_u *b_p_bh;
    char_u *b_p_bt;
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
    char_u *b_p_vsts_nopaste;
    int *b_p_vsts_array;
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
    char_u *b_p_tsrfu;
    char_u *b_p_qe;
    char_u *b_p_bexpr;
    char_u *b_p_cm;
    int b_p_udf;
    char_u *b_p_lw;
    char_u *b_p_menc;
    char_u *b_p_ts;
    int b_p_ma;
    void *b_p_script_ctx;
} buf_T;

extern char_u *p_cpo;
extern char_u *p_isk;
extern char_u *p_fenc;
extern char_u *p_ffs;
extern char_u *p_ff;
extern char_u *empty_option;
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
extern char_u *p_vts;
extern int p_ma;
extern char_u *p_inex;
extern char_u *p_qe;
extern int p_tx;
extern int p_ts;

extern cmdmod_T cmdmod;

char_u *vim_strchr(const char_u *str, int c);
char_u *vim_strsave(const char_u *str);
void free_buf_options(buf_T *buf, int free_strings);
void clear_string_option(char_u **pp);
void check_buf_options(buf_T *buf);
int buf_init_chartab(buf_T *buf, int global);
void init_buf_opt_idx(void);
int tabstop_set(char_u *var, int **array);
void compile_cap_prog(void *buf);
void set_buflocal_cfu_callback(buf_T *buf);
void set_buflocal_ofu_callback(buf_T *buf);
void set_buflocal_tfu_callback(buf_T *buf);

#define COPY_OPT_SCTX(buf, idx) /* empty */

#ifdef FEAT_EVAL
#define CLEAR_FIELD(field) /* empty */
#endif