#include <stdarg.h>
#include <stdint.h>

#define MAX_AMBIGUOUS_VALUES 10

typedef struct Clp_BuildString {
    char *buffer;
    int capacity;
    int length;
} Clp_BuildString;

typedef struct Clp_InternOption {
    int unquoted;
    int ilongoff;
} Clp_InternOption;

typedef struct Clp_Option {
    const char *long_name;
} Clp_Option;

typedef struct Clp_Internal {
    int utf8;
} Clp_Internal;

typedef struct Clp_Parser {
    Clp_Internal *internal;
} Clp_Parser;

void build_string_init(Clp_BuildString *bs, Clp_Parser *clp);
void Clp_vbsprintf(Clp_Parser *clp, Clp_BuildString *bs, const char *fmt, va_list val);
void append_build_string(Clp_BuildString *bs, const char *str, int len);
void build_string_program_prefix(Clp_BuildString *bs, Clp_Parser *clp);
void do_error(Clp_Parser *clp, Clp_BuildString *bs);
void build_string_cleanup(Clp_BuildString *bs);