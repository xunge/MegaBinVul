#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef char char_u;

#define FAIL 1
#define UC_VIM9 0
#define GETLINE_CONCAT_CONTBAR 0
#define e_missing_rcurly "e_missing_rcurly"

typedef struct exarg_T {
    char_u *arg;
    char_u *(*getline)(int, void *, int, int);
    void *cookie;
} exarg_T;

typedef struct {
    size_t ga_len;
    size_t ga_maxlen;
    char_u **ga_data;
} garray_T;

char_u *skipwhite(char_u *p);
int ends_excmd2(char_u *arg, char_u *p);
void ga_init2(garray_T *gap, size_t size, int grow);
int ga_add_string(garray_T *gap, char_u *s);
char_u *ga_concat_strings(garray_T *gap, char_u *sep);
void ga_clear_strings(garray_T *gap);
void vim_free(void *ptr);
char *_(const char *str);
void emsg(const char *str);

#define STRLEN strlen