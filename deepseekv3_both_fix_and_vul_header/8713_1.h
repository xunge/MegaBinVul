#include <stdlib.h>
#include <string.h>

#define TRUE 1

typedef char *Str;
struct parsed_tag;
extern int cur_form_id;
extern int cur_hseq;
extern int formtype(const char *);
extern Str Strnew(void);
extern void Strcat(Str, Str);
extern Str Sprintf(const char *, ...);
extern char *html_quote(const char *);
extern Str process_form(struct parsed_tag *);
extern struct parsed_tag *parse_tag(char **, int);
extern void parsedtag_get_value(struct parsed_tag *, int, char **);

#define ATTR_TYPE 0
#define ATTR_VALUE 1
#define ATTR_NAME 2

#define FORM_UNKNOWN 0
#define FORM_INPUT_SUBMIT 1
#define FORM_INPUT_BUTTON 2
#define FORM_INPUT_RESET 3