#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Str {
    char *ptr;
    int len;
    int size;
} *Str;

typedef struct parsed_tag parsed_tag;

#define TRUE 1
#define FALSE 0

#define ATTR_TYPE 0
#define ATTR_VALUE 1
#define ATTR_NAME 2
#define ATTR_SIZE 3
#define ATTR_MAXLENGTH 4
#define ATTR_ALT 5
#define ATTR_CHECKED 6
#define ATTR_ACCEPT 7
#define ATTR_READONLY 8
#define ATTR_SRC 9
#define ATTR_WIDTH 10
#define ATTR_HEIGHT 11

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

Str Strnew(void);
Str Strnew_charp(const char *);
void Strcat_charp(Str, const char *);
void Strcat_char(Str, char);
void Strcat(Str, Str);
Str Sprintf(const char *, ...);
int parsedtag_get_value(struct parsed_tag *, int, void *);
int parsedtag_exists(struct parsed_tag *, int);
int formtype(const char *);
char *html_quote(const char *);
int get_strwidth(const char *);
Str getLinkNumberStr(int);
Str textfieldrep(Str, int);
Str process_form(struct parsed_tag *);
struct parsed_tag *parse_tag(char **, int);