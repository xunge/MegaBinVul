#include <string.h>
#include <ctype.h>

typedef enum {
    MOBI_SUCCESS,
    MOBI_PARAM_ERR
} MOBI_RET;

typedef enum {
    T_CSS
} MOBIFiletype;

#define MOBI_ATTRNAME_MAXSIZE 256
#define MOBI_ATTRVALUE_MAXSIZE 1024

typedef struct {
    const unsigned char *start;
    const unsigned char *end;
    char value[MOBI_ATTRVALUE_MAXSIZE];
    int is_url;
} MOBIResult;

void debug_print(const char *format, ...);