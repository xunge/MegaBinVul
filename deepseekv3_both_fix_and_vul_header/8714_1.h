#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Str {
    char *ptr;
    int length;
} *Str;

typedef struct _TextLine {
    Str line;
    int pos;
} TextLine;

typedef struct _TextLineListItem {
    TextLine *ptr;
    struct _TextLineListItem *next;
} TextLineListItem;

typedef struct _TextLineList {
    TextLineListItem *first;
    TextLineListItem *last;
} TextLineList;

struct html_feed_environ {
    TextLineList *buf;
    FILE *f;
    int maxlimit;
    int blank_lines;
};

struct readbuffer {
    Str line;
    int pos;
    int flag;
    int top_margin;
    int bottom_margin;
    struct {
        int len;
        int tlen;
        int pos;
        int init_flag;
    } bp;
    struct {
        char *url;
        char *target;
        char *referer;
        char *title;
        char *accesskey;
        int hseq;
    } anchor;
    Str img_alt;
    struct {
        int in;
        int hseq;
        int fid;
        Str name;
        Str type;
        Str value;
    } input_alt;
    int in_bold;
    int in_italic;
    int in_under;
    int in_strike;
    int in_ins;
    int prev_ctype;
    char prevchar;
};

enum {
    RB_SPECIAL = 1,
    RB_NOBR = 2,
    RB_NFLUSHED = 4,
    RB_CENTER = 8,
    RB_RIGHT = 16,
    RB_LEFT = 32,
    RB_INTABLE = 64,
    RB_FILL = 128
};

enum {
    HTML_A,
    HTML_IMG_ALT,
    HTML_INPUT_ALT,
    HTML_B,
    HTML_I,
    HTML_U,
    HTML_S,
    HTML_INS
};

enum {
    PC_ASCII,
    ALIGN_CENTER,
    ALIGN_RIGHT,
    ALIGN_LEFT
};

struct environment {
    int dummy;
};

extern int w3m_debug;
extern void *link_stack;