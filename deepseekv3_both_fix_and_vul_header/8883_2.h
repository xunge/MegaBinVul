#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAG_LEN 256
#define MAX_TAGATTR 256
#define HTML_UNKNOWN 0
#define ATTR_UNKNOWN 0
#define TRUE 1
#define FALSE 0
#define TFLG_INT 1
#define AFLG_INT 1
#define VTYPE_METHOD 1
#define HTML_INPUT 1
#define HTML_INPUT_ALT 2
#define ATTR_TYPE 1
#define ATTR_VALUE 2

struct parsed_tag {
    int tagid;
    unsigned char *attrid;
    char **value;
    unsigned char *map;
    int need_reconstruct;
};

struct tagmap {
    int flag;
    int max_attribute;
    unsigned char *accept_attribute;
};

struct attrmap {
    int flag;
    int vtype;
    char *name;
};

typedef struct {
    char *ptr;
} *Str;

extern struct tagmap TagMAP[];
extern struct attrmap AttrMAP[];
extern void *tagtable;

Str Strnew(void);
void Strcat_char(Str s, char c);
int getHash_si(void *table, char *key, int def);
void *New(size_t size);
void *NewAtom_N(size_t size, int n);
void *New_N(size_t size, int n);
void bzero(void *s, size_t n);
void *memset(void *s, int c, size_t n);
int is_html_quote(char c);
char *html_unquote(char *s);
int strcasecmp(const char *s1, const char *s2);

#define SKIP_BLANKS(p) while (IS_SPACE(*(p))) (p)++
#define IS_SPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')
#define TOLOWER(c) tolower((unsigned char)(c))

#define New(type) ((type *)malloc(sizeof(type)))
#define NewAtom_N(type, n) ((type *)malloc((n) * sizeof(type)))
#define New_N(type, n) ((type *)malloc((n) * sizeof(type)))