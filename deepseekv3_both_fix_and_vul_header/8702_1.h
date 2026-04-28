#include <stdio.h>
#include <stdlib.h>

#define FORM_TEXTAREA 1
#define FORM_INPUT_TEXT 2
#define FORM_INPUT_FILE 3
#define FORM_INPUT_PASSWORD 4
#define FORM_INPUT_CHECKBOX 5
#define FORM_INPUT_RADIO 6
#define FORM_SELECT 7

typedef struct Line Line;
typedef struct Buffer Buffer;
typedef struct Anchor Anchor;
typedef struct FormItemList FormItemList;

struct Line {
    char *lineBuf;
    int linenumber;
    int len;
    Line *prev;
    Line *next;
};

struct Buffer {
    Line *currentLine;
    void *href;
    void *hmarklist;
    void *name;
    void *img;
    void *formitem;
};

struct Anchor {
    struct {
        int line;
        int pos;
    } start;
    struct {
        int line;
        int pos;
    } end;
    int y;
};

struct FormItemList {
    int type;
    int checked;
    int rows;
    struct {
        char *ptr;
    } *label;
    struct {
        char *ptr;
    } *value;
    void *select_option;
};

void copyBuffer(Buffer *dest, Buffer *src);
void gotoLine(Buffer *buf, int line);
int COLPOS(Line *l, int pos);
int columnPos(Line *l, int col);
Anchor *retrieveAnchor(void *formitem, int linenumber, int pos);
int form_update_line(Line *l, char **p, int spos, int epos, int width, int multiline, int password);
void shiftAnchorPosition(void *anchor, void *hmarklist, int line, int pos, int shift);
void arrangeLine(Buffer *buf);
#ifdef MENU_SELECT
void updateSelectOption(FormItemList *form, void *select_option);
#endif