#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLE 10
#define RB_INTXTA 0x01
#define RB_INSELECT 0x02
#define RB_TITLE 0x04

#define HTML_N_IMG_ALT 0
#define HTML_N_INPUT_ALT 0
#define HTML_N_B 0
#define HTML_N_I 0
#define HTML_N_U 0
#define HTML_N_S 0
#define HTML_N_INS 0

#define TBLM_SCRIPT 0x01
#define TBLM_STYLE 0x02
#define TBLM_PLAIN 0x04

struct html_feed_environ;
struct readbuffer;

struct input_alt {
    int hseq;
    int fid;
    int in;
    char *type;
    char *name;
    char *value;
};

struct table_mode {
    int pre_mode;
};

struct readbuffer {
    char *img_alt;
    struct input_alt input_alt;
    int in_bold;
    int in_italic;
    int in_under;
    int in_strike;
    int in_ins;
    int flag;
    int table_level;
};

struct html_feed_environ;

extern void close_anchor(struct html_feed_environ *h_env, struct readbuffer *obuf);
extern void push_tag(struct readbuffer *obuf, const char *tag, int type);
extern void HTMLlineproc1(const char *str, struct html_feed_environ *h_env);

struct table_mode table_mode[MAX_TABLE];