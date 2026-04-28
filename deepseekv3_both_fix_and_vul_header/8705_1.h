#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_INPUT_SIZE 100

typedef struct Str *Str;
typedef struct parsed_tag parsed_tag;

enum {
    ATTR_TYPE,
    ATTR_VALUE,
    ATTR_NAME,
    ATTR_SIZE,
    ATTR_MAXLENGTH,
    ATTR_ALT,
    ATTR_CHECKED,
    ATTR_ACCEPT,
    ATTR_READONLY,
    ATTR_SRC,
    ATTR_WIDTH,
    ATTR_HEIGHT
};

enum {
    FORM_UNKNOWN,
    FORM_INPUT_IMAGE,
    FORM_INPUT_SUBMIT,
    FORM_INPUT_BUTTON,
    FORM_INPUT_RESET,
    FORM_INPUT_CHECKBOX,
    FORM_INPUT_FILE,
    FORM_INPUT_PASSWORD,
    FORM_INPUT_TEXT,
    FORM_INPUT_RADIO,
    FORM_INPUT_HIDDEN
};

extern int cur_form_id;
extern int cur_hseq;
extern int displayLinkNumber;

struct Str {
    char *ptr;
    int len;
    int size;
};

Str Strnew(void);
void Strcat(Str s1, Str s2);
void Strcat_char(Str s, char c);
void Strcat_charp(Str s, const char *p);
Str Sprintf(const char *fmt, ...);
Str Strnew_charp(const char *p);
Str textfieldrep(Str s, int size);
char *html_quote(const char *s);
int get_strwidth(const char *s);
int formtype(const char *p);
Str getLinkNumberStr(int n);
Str process_form(struct parsed_tag *tag);
struct parsed_tag *parse_tag(char **s, int flag);
int parsedtag_get_value(struct parsed_tag *tag, int attr, void *value);
int parsedtag_exists(struct parsed_tag *tag, int attr);