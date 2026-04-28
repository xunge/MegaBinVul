#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int line;
    int pos;
} Point;

typedef struct Anchor {
    Point start;
    Point end;
    int y;
} Anchor;

typedef struct Buffer {
    struct Line *currentLine;
    struct FormItemList *formitem;
    struct HrefList *href;
    struct HmarkList *hmarklist;
    struct NameList *name;
    struct ImgList *img;
} Buffer;

typedef struct Line {
    char *lineBuf;
    int linenumber;
    int len;
    struct Line *prev;
    struct Line *next;
} Line;

typedef struct FormItemList {
    int type;
    int checked;
    int rows;
    struct Value *value;
    struct Label *label;
    int select_option;
} FormItemList;

typedef struct Value {
    char *ptr;
} Value;

typedef struct Label {
    char *ptr;
} Label;

typedef struct HrefList {
    // placeholder structure
} HrefList;

typedef struct HmarkList {
    // placeholder structure
} HmarkList;

typedef struct NameList {
    // placeholder structure
} NameList;

typedef struct ImgList {
    // placeholder structure
} ImgList;

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
Anchor *retrieveAnchor(FormItemList *formitem, int linenumber, int pos);
int form_update_line(Line *l, char **p, int spos, int epos, int diff, int multi_line, int is_password);
void shiftAnchorPosition(void *list, void *hmarklist, int line, int pos, int diff);
void arrangeLine(Buffer *buf);
void updateSelectOption(FormItemList *form, int option);