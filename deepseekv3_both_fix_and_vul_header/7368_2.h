#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct SYMBOL {
    int abc_type;
    int flags;
    int nhd;
    union {
        struct {
            int len;
            int slur_st;
            int slur_end;
            int brhythm;
            struct {
                int ti1;
                int len;
            } notes[1];
        } note;
        struct {
            int type;
            int len;
            int dotted;
        } bar;
        struct {
            int p_plet;
            int q_plet;
            int r_plet;
        } tuplet;
        struct {
            int type;
            int voice;
        } v_over;
        struct {
            int type;
        } eoln;
    } u;
};

struct decos {
    int n;
};

struct voice {
    struct SYMBOL *last_note;
    int mvoice;
};

struct parse_state {
    int abc_state;
    struct SYMBOL *last_sym;
    int abc_vers;
};

static struct parse_state parse;
static struct voice *curvoice;
static struct voice voice_tb[1];
static int vover;
static int colnum;
static int meter;
static int microscale;
static int lyric_started;
static char *abc_line;
static char char_tb[256];
static struct decos dc;
static struct SYMBOL *deco_start;
static struct SYMBOL *deco_cont;

enum {
    ABC_T_NULL,
    ABC_T_PSCOM,
    ABC_T_EOLN,
    ABC_T_MREP,
    ABC_T_TUPLET,
    ABC_T_V_OVER,
    ABC_T_NOTE,
    ABC_T_REST
};

enum {
    ABC_S_GLOBAL,
    ABC_S_HEAD,
    ABC_S_TUNE
};

enum {
    ABC_F_GRACE = 1,
    ABC_F_SAPPO = 2,
    ABC_F_GR_END = 4,
    ABC_F_SPACE = 8
};

enum {
    CHAR_DECOS,
    CHAR_BAD,
    CHAR_LINEBREAK,
    CHAR_GCHORD,
    CHAR_GR_ST,
    CHAR_GR_EN,
    CHAR_DECO,
    CHAR_NOTE,
    CHAR_SLASH,
    CHAR_BSLASH,
    CHAR_OBRA,
    CHAR_BAR,
    CHAR_OPAR,
    CHAR_CPAR,
    CHAR_VOV,
    CHAR_SPAC,
    CHAR_MINUS,
    CHAR_BRHY,
    CHAR_IGN
};

enum {
    SL_DOTTED = 1,
    SL_ABOVE = 2,
    SL_BELOW = 4,
    SL_AUTO = 8
};

enum {
    V_OVER_S,
    V_OVER_E
};

struct SYMBOL *abc_new(int type, char *p);
void syntax(const char *msg, char *p);
void get_user(char *p, struct SYMBOL *s);
int parse_info(char *p);
char *parse_gchord(char *p);
int check_nl(char *p);
char *parse_deco(char *p, struct decos *dc, int i);
char *parse_note(char *p, int flags);
char *parse_bar(char *p);
void vover_new(void);
void broken_rhythm(struct SYMBOL *s, int i);