#include <stdlib.h>
#include <string.h>

struct to_param {
    int type;
    struct {
        char *s;
        int len;
    } name;
    struct {
        char *s;
        int len;
    } value;
};

struct to_body {
    int error;
};

enum {
    TAG_PARAM,
    GENERAL_PARAM
};

enum {
    E_PARA_VALUE,
    TAG1,
    TAG2,
    TAG3,
    PARA_NAME,
    S_EQUAL,
    PARA_VALUE_TOKEN,
    F_CRLF,
    F_LF,
    F_CR,
    S_PARA_NAME,
    S_PARA_VALUE,
    PARA_VALUE_QUOTED,
    PARSE_ERROR
};

static void add_param(struct to_param *param, struct to_body *to_b);
static void free_to_params(struct to_body *to_b);
static void *pkg_malloc(size_t size);
static void pkg_free(void *p);
#define LM_ERR(fmt, ...)
#define ZSW(s) (s?s:"")