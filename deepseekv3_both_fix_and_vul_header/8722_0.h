#include <stdio.h>
#include <stdlib.h>

typedef struct Buffer Buffer;
typedef struct Line Line;
typedef struct Anchor Anchor;
typedef struct FormItemList FormItemList;

struct Buffer {
    Line *currentLine;
    void *href;
    void *hmarklist;
    void *name;
    void *img;
    void *formitem;
};

struct Line {
    char *lineBuf;
    int len;
    int linenumber;
    Line *prev;
    Line *next;
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
    } *value;
    struct {
        char *ptr;
    } *label;
    int select_option;
};

#define FORM_TEXTAREA 0
#define FORM_INPUT_TEXT 1
#define FORM_INPUT_FILE 2
#define FORM_INPUT_PASSWORD 3
#define FORM_INPUT_CHECKBOX 4
#define FORM_INPUT_RADIO 5
#define FORM_SELECT 6
#define MENU_SELECT 1

void copyBuffer(Buffer *dest, Buffer *src);
void gotoLine(Buffer *buf, int line);
int COLPOS(Line *l, int pos);
int columnPos(Line *l, int col);
Anchor *retrieveAnchor(void *formitem, int linenumber, int pos);
int form_update_line(Line *l, char **p, int spos, int epos, int diff, int multi_line, int is_password);
void shiftAnchorPosition(void *anchor, void *hmarklist, int line, int pos, int diff);
void arrangeLine(Buffer *buf);
#ifdef MENU_SELECT
void updateSelectOption(FormItemList *form, int option);
#endif