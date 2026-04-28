#include <string.h>
#include <ctype.h>

#define MOBI_ATTRVALUE_MAXSIZE 1024
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef enum {
    MOBI_SUCCESS,
    MOBI_PARAM_ERR
} MOBI_RET;

typedef struct {
    const unsigned char *start;
    const unsigned char *end;
    char value[MOBI_ATTRVALUE_MAXSIZE];
} MOBIResult;

extern void debug_print(const char *format, ...);