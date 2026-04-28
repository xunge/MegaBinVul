#include <stdlib.h>
#include <string.h>

#define NUL '\0'
#define NO_LOCAL_UNDOLEVEL -1
#define FEAT_FIND_ID
#define FEAT_EVAL
#define FEAT_CINDENT
#define FEAT_BEVAL
#define FEAT_CRYPT
#define FEAT_SODIUM
#define FEAT_VARTABS
#define FEAT_KEYMAP
#define FEAT_FOLDING
#define FEAT_SYN_HL
#define FEAT_SPELL
#define FEAT_SEARCHPATH
#define FEAT_SMARTINDENT
#define FEAT_COMPL_FUNC
#define FEAT_QUICKFIX
#define FEAT_TEXTOBJ
#define FEAT_LISP

typedef struct growarray {
    void *ga_data;
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
} growarray;

typedef struct callback {
    void *cb_name;
    void *cb_partial;
    void *cb_free_name;
    void *cb_free_partial;
} callback;

typedef struct buf {
    char *b_p_fenc;
    char *b_p_ff;
    char *b_p_bh;
    char *b_p_bt;
    char *b_p_def;
    char *b_p_inc;
    char *b_p_inex;
    char *b_p_inde;
    char *b_p_indk;
    char *b_p_bexpr;
    char *b_p_cm;
    char *b_p_fp;
    char *b_p_fex;
    char *b_p_key;
    char *b_p_kp;
    char *b_p_mps;
    char *b_p_fo;
    char *b_p_flp;
    char *b_p_isk;
    char *b_p_vsts;
    char *b_p_vsts_nopaste;
    char *b_p_vsts_array;
    char *b_p_vts;
    char *b_p_vts_array;
    char *b_p_keymap;
    growarray b_kmap_ga;
    char *b_p_com;
    char *b_p_cms;
    char *b_p_nf;
    char *b_p_syn;
    struct {
        char *b_syn_isk;
        char *b_p_spc;
        char *b_p_spf;
        void *b_cap_prog;
        char *b_p_spl;
        char *b_p_spo;
    } b_s;
    char *b_p_sua;
    char *b_p_ft;
    char *b_p_cink;
    char *b_p_cino;
    char *b_p_cinw;
    char *b_p_cpt;
    char *b_p_cfu;
    callback b_cfu_cb;
    char *b_p_ofu;
    callback b_ofu_cb;
    char *b_p_tsrfu;
    callback b_tsrfu_cb;
    char *b_p_gp;
    char *b_p_mp;
    char *b_p_efm;
    char *b_p_ep;
    char *b_p_path;
    char *b_p_tags;
    char *b_p_tc;
    char *b_p_tfu;
    callback b_tfu_cb;
    char *b_p_dict;
    char *b_p_tsr;
    char *b_p_qe;
    int b_p_ar;
    int b_p_ul;
    char *b_p_lw;
    char *b_p_bkc;
    char *b_p_menc;
} buf_T;

#define STRLEN(s) strlen(s)
#define VIM_CLEAR(ptr) free(ptr), (ptr) = NULL
#define CRYPT_M_SOD 0

void clear_string_option(char **option);
void vim_free(void *ptr);
int crypt_get_method_nr(buf_T *buf);
void crypt_sodium_munlock(char *key, size_t len);
void keymap_clear(growarray *gap);
void ga_clear(growarray *gap);
void vim_regfree(void *prog);
void free_callback(callback *cb);