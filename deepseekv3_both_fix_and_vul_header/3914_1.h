#include <stddef.h>

#define MAX_AMBIGUOUS_VALUES 10

typedef struct Clp_Internal {
    int could_be_short;
} Clp_Internal;

typedef struct Clp_Option {
    const char *long_name;
} Clp_Option;

typedef struct Clp_InternOption {
    int ilong;
    int ineg;
    int ipos;
    int ilongoff;
    int lmmneg;
    int lmmpos;
    int lmmneg_short;
    int lmmpos_short;
} Clp_InternOption;

typedef struct Clp_Parser {
    int negated;
    Clp_Internal *internal;
} Clp_Parser;

extern int argcmp(const char *s1, const char *s2, int lmm, int fewer_dashes);
extern int clp_utf8_charlen(Clp_Internal *internal, const char *arg);