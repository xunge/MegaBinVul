#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef unsigned int colnr_T;
typedef unsigned char char_u;

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define CTRL_X_DICTIONARY 1
#define CTRL_X_THESAURUS 2
#define CTRL_X_TAGS 3
#define CTRL_X_PATH_PATTERNS 4
#define CTRL_X_PATH_DEFINES 5
#define INS_COMPL_CPT_OK 0
#define INS_COMPL_CPT_END 1
#define INS_COMPL_CPT_CONT 2
#define DICT_EXACT 0
#define DICT_FIRST 1
#define HLF_R 0
#define FEAT_FIND_ID 1
#define IOSIZE 1024

typedef struct {
    int lnum;
    colnr_T col;
} pos_T;

typedef struct {
    char *e_cpt;
    bool found_all;
    struct buf_T *ins_buf;
    pos_T first_match_pos;
    pos_T last_match_pos;
    bool set_match_pos;
    char *dict;
    int dict_f;
} ins_compl_next_state_T;

typedef struct buf_T {
    int b_scanned;
    struct {
        int ml_line_count;
        void *ml_mfp;
    } b_ml;
    char *b_fname;
    char *b_sfname;
    char *(*buf_spname)(struct buf_T *);
} buf_T;

extern buf_T *curbuf;
extern char_u IObuff[IOSIZE];
extern bool compl_started;
extern bool msg_hist_off;

char_u *vim_strchr(char_u *str, int c);
int ctrl_x_mode_normal(void);
int ctrl_x_mode_line_or_eval(void);
int dec(pos_T *pos);
char_u *ml_get(int lnum);
size_t STRLEN(const char *str);
int vim_snprintf(char *str, size_t size, const char *format, ...);
int msg_trunc_attr(char *str, bool attr, int hl_attr);
buf_T *ins_compl_next_buf(buf_T *buf, int c);
void copy_option_part(char **option, char *buf, int buflen, char *sep);