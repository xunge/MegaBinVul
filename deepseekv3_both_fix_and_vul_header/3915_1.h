#include <stdlib.h>
#include <string.h>

#define MAX_AMBIGUOUS_VALUES 10

typedef struct Clp_Parser Clp_Parser;

typedef struct Clp_Option {
    const char *long_name;
} Clp_Option;

typedef struct Clp_StringList {
    Clp_Option *items;
    struct Clp_InternOption *iopt;
    int nitems;
    int allow_int;
    int val_long;
    int nitems_invalid_report;
} Clp_StringList;

typedef struct Clp_InternOption {
    int ilong;
    int ipos;
    int ishort;
    int ineg;
    int ilongoff;
    int iprefmatch;
    int unquoted;
} Clp_InternOption;

enum {
    Clp_AllowNumbers = 1,
    Clp_StringListLong = 2
};

int Clp_AddType(Clp_Parser *clp, int val_type, int flags, void *parse_func, void *data);
void calculate_lmm(Clp_Parser *clp, Clp_Option *items, Clp_InternOption *iopt, int nitems);
int parse_string_list(Clp_Parser *clp, const char *arg, int complain, void *data);