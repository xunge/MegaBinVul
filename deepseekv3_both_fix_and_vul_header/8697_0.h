#include <stdio.h>
#include <stdlib.h>

typedef struct Line {
    char *lineBuf;
    int linenumber;
    struct Line *prev;
    struct Line *next;
} Line;

typedef struct Buffer {
    Line *currentLine;
    void *href;
    void *hmarklist;
    void *name;
    void *img;
    void *formitem;
} Buffer;

typedef struct Anchor {
    struct {
        int line;
        int pos;
    } start;
    struct {
        int line;
        int pos;
    } end;
    int y;
} Anchor;

typedef struct FormItemList {
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
} FormItemList;

#define FORM_TEXTAREA 1
#define FORM_INPUT_TEXT 2
#define FORM_INPUT_FILE 3
#define FORM_INPUT_PASSWORD 4
#define FORM_INPUT_CHECKBOX 5
#define FORM_INPUT_RADIO 6
#define FORM_SELECT 7
#define MENU_SELECT 1

void copyBuffer(Buffer *dest, Buffer *src);
void gotoLine(Buffer *buf, int line);
int COLPOS(Line *l, int pos);
int columnPos(Line *l, int col);
Anchor *retrieveAnchor(void *formitem, int linenumber, int pos);
int form_update_line(Line *l, char **p, int spos, int epos, int width, int multiline, int is_password);
void shiftAnchorPosition(void *anchor, void *hmarklist, int line, int pos, int delta);
void arrangeLine(Buffer *buf);
void updateSelectOption(FormItemList *form, int option);