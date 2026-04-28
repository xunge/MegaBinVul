#include <stdlib.h>
#include <string.h>

typedef struct Clp_Option {
    int option_id;
    const char *long_name;
    int short_name;
    int flags;
    int val_type;
} Clp_Option;

typedef struct Clp_InternOption {
    int ilong;
    int ishort;
    int ipos;
    int ineg;
    int imandatory;
    int ioptional;
    int iprefmatch;
    int unquoted;
    int ilongoff;
} Clp_InternOption;

typedef struct Clp_Internal {
    const Clp_Option *opt;
    Clp_InternOption *iopt;
    int nopt;
    unsigned opt_generation;
    int current_option;
    int utf8;
} Clp_Internal;

typedef struct Clp_Parser {
    Clp_Internal *internal;
} Clp_Parser;

#define Clp_Negate 0x01
#define Clp_Mandatory 0x02
#define Clp_Optional 0x04
#define Clp_PreferredMatch 0x08
#define Clp_OnlyNegated 0x10

void Clp_OptionError(Clp_Parser *clp, const char *format, ...);
void calculate_lmm(Clp_Parser *clp, const Clp_Option *opt, Clp_InternOption *iopt, int nopt);