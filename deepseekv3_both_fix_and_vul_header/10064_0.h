#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EC_COLOR_BOLD ""
#define EC_COLOR_END ""
#define PROGRAM ""
#define EC_VERSION ""
#define EC_COPYRIGHT ""
#define EC_AUTHORS ""
#define E_NOTHANDLED -1
#define E_INVALID -2
#define E_SUCCESS 0

struct ef_globals {
    int lineno;
};

struct ef_globals_options {
    char *source_file;
    char *output_file;
};

extern struct ef_globals *EF_GBL;
extern struct ef_globals_options *EF_GBL_OPTIONS;
extern FILE *yyin;

void libettercap_init(void);
void ef_globals_alloc(void);
void select_text_interface(void);
void libettercap_ui_init(void);
void parse_options(int argc, char *argv[]);
void load_tables(void);
void load_constants(void);
int yyparse(void);
int write_output(void);
void ef_globals_free(void);
void ef_debug(int level, const char *fmt, ...);
void FATAL_ERROR(const char *fmt, ...);