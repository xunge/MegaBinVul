#include <string.h>

#define MAXVOICE 32
#define ABC_T_BAR 1
#define V_OVER_E 2
#define V_OVER_S 3
#define S_BEAM_END 0x01
#define BAR 1

struct V_OVER {
    int type;
    int voice;
};

struct SYMBOL {
    int abc_type;
    struct {
        struct V_OVER v_over;
    } u;
    int type;
    int time;
    struct SYMBOL *prev;
    unsigned sflags;
    struct SYMBOL *last_sym;
};

struct VOICE_S {
    int ignore;
    int time;
    struct SYMBOL *last_sym;
    char id[2];
    int second;
    int scale;
    int octave;
    int transpose;
    int key;
    int ckey;
    int okey;
    int posit;
    int staff;
    int cstaff;
    int color;
    char *map_name;
    int clone;
};

struct {
    struct {
        int range;
        int second;
        int staff;
    } voice[MAXVOICE];
} *parsys;

struct {
    int abc2pscompat;
} cfmt;

extern struct VOICE_S voice_tb[MAXVOICE];
extern struct VOICE_S *curvoice;
extern int over_bar;
extern int over_time;
extern int over_mxtime;
extern int over_voice;

void error(int level, struct SYMBOL *s, const char *msg);
void voice_link(struct VOICE_S *voice);