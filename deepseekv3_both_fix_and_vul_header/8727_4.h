#include <stdio.h>
#include <stdlib.h>

struct html_feed_environ {
    char *title;
    void *buf;
    FILE *f;
};

typedef struct _Str {
    char *ptr;
} *Str;

typedef struct _TextLine {
    Str line;
    int flags;
} TextLine;

typedef struct _TextLineListItem {
    TextLine *ptr;
    struct _TextLineListItem *next;
} TextLineListItem;

typedef struct _TextLineList {
    TextLineListItem *first;
    TextLineListItem *last;
} TextLineList;

typedef struct _FormSelectOptionItem {
    Str value;
    Str label;
    int checked;
    struct _FormSelectOptionItem *next;
} FormSelectOptionItem;

typedef struct {
    FormSelectOptionItem *first;
} FormSelectOption;

Str Strnew_charp(const char *);
Str Strnew_m_charp(const char *, ...);
Str Sprintf(const char *, ...);
void Strcat_charp(Str, const char *);
void Strcat(Str, Str);
char *html_quote(const char *);
TextLine *newTextLine(Str, int);
TextLineList *newTextLineList();
void pushTextLine(TextLineList *, TextLine *);
void appendTextLineList(void *, TextLineList *);
Str Str_conv_to_halfdump(Str);

extern int n_select;
extern int n_textarea;
extern FormSelectOption *select_option;
extern Str *textarea_str;