#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define ABC_F_GRACE 0x01
#define ABC_F_LYRIC_START 0x02
#define ABC_F_INVIS 0x04
#define ABC_F_STEMLESS 0x08
#define ABC_F_ERROR 0x10

#define ABC_T_NOTE 1
#define ABC_T_MREST 2
#define ABC_T_REST 3

#define MAXHD 10

#define SL_DOTTED 1
#define SL_ABOVE 2
#define SL_BELOW 3
#define SL_AUTO 4

struct NOTE {
    int pit;
    int len;
    int acc;
    int color;
    int shhd;
    int ti1;
    int sl1;
    int sl2;
};

struct BAR {
    int type;
    int len;
    struct {
        int n;
    } dc;
};

struct NOTE_DATA {
    struct NOTE notes[MAXHD];
    int microscale;
    int nhd;
    struct {
        int n;
    } dc;
    int brhythm;
};

struct SYMBOL {
    int abc_type;
    int flags;
    union {
        struct NOTE_DATA note;
        struct BAR bar;
    } u;
    int *pits;
    int nhd;
    struct SYMBOL *abc_prev;
    struct SYMBOL *abc_next;
};

struct VOICE {
    struct SYMBOL *last_note;
};

struct PARSER {
    struct SYMBOL *first_sym;
    struct SYMBOL *last_sym;
};

struct DECO {
    int n;
};

extern struct SYMBOL *abc_new(int type, void *gchord);
extern void syntax(const char *msg, char *pos);
extern char *parse_len(char *p, int ulen, int *len);
extern char *parse_deco(char *p, struct DECO *dc, int m);
extern char *parse_acc_pit(char *p, int *pit, int *acc);
extern void broken_rhythm(struct SYMBOL *s, int brhythm);

extern int ulen;
extern int BASE_LEN;
extern int microscale;
extern int lyric_started;
extern struct SYMBOL *deco_start;
extern void *gchord;
extern struct VOICE *curvoice;
extern struct PARSER parse;
extern struct DECO dc;