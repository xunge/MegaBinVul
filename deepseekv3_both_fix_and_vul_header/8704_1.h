#include <stdlib.h>
#include <string.h>

#define TRUE 1

typedef char* Str;
Str Strnew(void);
void Strcat(Str s1, Str s2);
Str Sprintf(const char *format, ...);
char *html_quote(const char *str);

struct parsed_tag;
int parsedtag_get_value(struct parsed_tag *tag, int attr, char **value);
struct parsed_tag *parse_tag(char **s, int flag);

extern int cur_form_id;
extern int cur_hseq;

enum {
    ATTR_TYPE,
    ATTR_VALUE,
    ATTR_NAME
};

enum {
    FORM_UNKNOWN,
    FORM_INPUT_SUBMIT,
    FORM_INPUT_BUTTON,
    FORM_INPUT_RESET
};

int formtype(const char *type);
Str process_form(struct parsed_tag *tag);