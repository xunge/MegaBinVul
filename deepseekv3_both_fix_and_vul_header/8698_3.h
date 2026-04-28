#include <stdlib.h>
#include <string.h>

#define FORM_UNKNOWN 0
#define FORM_INPUT_TEXT 1
#define FORM_INPUT_FILE 2
#define FORM_INPUT_PASSWORD 3
#define FORM_SELECT 4
#define FORM_INPUT_HIDDEN 5
#define FORM_I_TEXT_DEFAULT_SIZE 20
#define ATTR_TYPE 0
#define ATTR_NAME 1
#define ATTR_VALUE 2
#define ATTR_CHECKED 3
#define ATTR_ACCEPT 4
#define ATTR_SIZE 5
#define ATTR_MAXLENGTH 6
#define ATTR_READONLY 7
#define ATTR_TEXTAREANUMBER 8
#define ATTR_SELECTNUMBER 9
#define ATTR_ROWS 10

struct Strnew_charp {
    char *ptr;
    int length;
};

struct form_item_list {
    int type;
    int size;
    int rows;
    int checked;
    int init_checked;
    int accept;
    struct Strnew_charp *name;
    struct Strnew_charp *value;
    struct Strnew_charp *init_value;
    int readonly;
    int maxlength;
    struct form_item_list *next;
    struct form_list *parent;
    void *select_option;
    int selected;
    struct Strnew_charp *label;
    int init_selected;
    struct Strnew_charp *init_label;
};

struct form_list {
    struct form_item_list *item;
    struct form_item_list *lastitem;
    int nitems;
};

struct parsed_tag {
    int dummy;
};

struct select_option {
    struct select_option *first;
};

extern struct Strnew_charp *Strnew_charp(char *p);
extern int parsedtag_get_value(struct parsed_tag *tag, int attr, void *value);
extern int parsedtag_exists(struct parsed_tag *tag, int attr);
extern int formtype(char *p);
extern struct form_item_list *New_form_item_list(void);
extern int max_textarea;
extern struct Strnew_charp *textarea_str[];
extern int max_select;
extern struct select_option select_option[];
extern void chooseSelectOption(struct form_item_list *item, void *select_option);

#define New(type) ((type *)malloc(sizeof(type)))