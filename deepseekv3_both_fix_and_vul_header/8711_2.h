#include <stdlib.h>
#include <string.h>

typedef char *Str;
struct parsed_tag;
typedef struct FormList FormList;

#define ATTR_METHOD 0
#define ATTR_ACTION 1
#define ATTR_ACCEPT_CHARSET 2
#define ATTR_CHARSET 3
#define ATTR_ENCTYPE 4
#define ATTR_TARGET 5
#define ATTR_NAME 6

#define USE_M17N

extern char *cur_baseURL;
extern char *cur_document_charset;
extern int form_max;
extern int form_sp;
extern int forms_size;
extern FormList **forms;
extern int *form_stack;
extern int w3m_halfdump;

#define INITIAL_FORM_SIZE 16

char *url_encode(const char *, const char *, const char *);
char *remove_space(const char *);
char *html_quote(const char *);
char *check_accept_charset(const char *);
char *check_charset(const char *);
int parsedtag_get_value(struct parsed_tag *, int, char **);
Str Sprintf(const char *, ...);
void Strcat(Str, Str);
void Strcat_charp(Str, const char *);
FormList *newFormList(char *, char *, char *, char *, char *, char *, void *);

#define New_N(type, size) ((type*)malloc(sizeof(type) * (size)))
#define New_Reuse(type, ptr, size) ((type*)realloc(ptr, sizeof(type) * (size)))
#define NewAtom_N(type, size) ((type*)calloc((size), sizeof(type)))