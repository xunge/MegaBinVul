#include <stdio.h>
#include <stdlib.h>

#define FORM_TEXTAREA 0
#define FORM_INPUT_TEXT 1
#define FORM_INPUT_FILE 2
#define FORM_INPUT_PASSWORD 3
#define FORM_INPUT_CHECKBOX 4
#define FORM_INPUT_RADIO 5
#define FORM_SELECT 6

typedef struct {
    int line;
    int pos;
} Position;

typedef struct {
    Position start;
    Position end;
    int y;
} Anchor;

typedef struct Line {
    char *lineBuf;
    int linenumber;
    int len;
    struct Line *prev;
    struct Line *next;
} Line;

typedef struct {
    Line *currentLine;
    void *formitem;
    void *href;
    void *hmarklist;
    void *name;
    void *img;
} Buffer;

typedef struct {
    char *ptr;
} Text;

typedef struct FormItemList {
    int type;
    int checked;
    int rows;
    Text *value;
    Text *label;
    int select_option;
} FormItemList;

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