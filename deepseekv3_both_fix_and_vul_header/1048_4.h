#include <stdio.h>
#include <stdlib.h>

#define _T(x) x
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ERROR_SUCCESS 0
#define YR_VERSION ""
#define USAGE_STRING ""
#define YR_CONFIG_MAX_STRINGS_PER_RULE 0

typedef struct {
    int errors;
    int warnings;
} COMPILER_RESULTS;

typedef struct YR_COMPILER YR_COMPILER;
typedef struct YR_RULES YR_RULES;

typedef struct {
    void* user_data;
    int (*write)(const void* ptr, size_t size, size_t count, void* user_data);
} YR_STREAM;

typedef int (*YR_STREAM_WRITE_FUNC)(const void*, size_t, size_t, void*);

int args_parse(void* options, int argc, const char** argv);
void args_print_usage(void* options, int width);
void args_free(void* options);
int define_external_variables(void* ext_vars, void* null, YR_COMPILER* compiler);
int compile_files(YR_COMPILER* compiler, int argc, const char** argv);
void report_error(int error_level, const char* file_name, int line_number, const char* message, void* user_data);
void exit_with_code(int code);
int yr_initialize();
int yr_compiler_create(YR_COMPILER** compiler);
int yr_compiler_load_atom_quality_table(YR_COMPILER* compiler, void* table, int flags);
void yr_set_configuration(int config, int* value);
void yr_compiler_set_callback(YR_COMPILER* compiler, void* callback, COMPILER_RESULTS* cr);
int yr_compiler_get_rules(YR_COMPILER* compiler, YR_RULES** rules);
int yr_rules_save_stream(YR_RULES* rules, YR_STREAM* stream);
void yr_compiler_destroy(YR_COMPILER* compiler);
void yr_rules_destroy(YR_RULES* rules);
void yr_finalize();

int show_version = 0;
int show_help = 0;
void* options = NULL;
void* ext_vars = NULL;
void* atom_quality_table = NULL;
int max_strings_per_rule = 0;
int fail_on_warnings = 0;

#define _tfopen fopen

typedef char char_t;