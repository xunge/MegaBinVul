#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define YR_MAX_THREADS 32
#define YR_VERSION "4.2.3"
#define USAGE_STRING "Usage: yara [OPTION]... RULES_FILE FILE|DIR|PID"
#define SCAN_FLAGS_FAST_MODE 1
#define ERROR_SUCCESS 0
#define ERROR_COULD_NOT_OPEN_FILE 1
#define ERROR_INTERNAL_FATAL_ERROR 2
#define ERROR_COULD_NOT_CREATE_THREAD 3
#define YR_CONFIG_STACK_SIZE 0
#define YR_CONFIG_MAX_STRINGS_PER_RULE 1
#define YR_CONFIG_MAX_PROCESS_MEMORY_CHUNK 2

typedef struct _YR_COMPILER YR_COMPILER;
typedef struct _YR_RULES YR_RULES;
typedef struct _YR_SCANNER YR_SCANNER;
typedef size_t (*YR_STREAM_READ_FUNC)(void*, size_t, size_t, void*);

typedef struct {
    int errors;
    int warnings;
} COMPILER_RESULTS;

typedef struct {
    bool follow_symlinks;
    bool recursive_search;
    time_t deadline;
} SCAN_OPTIONS;

typedef struct {
    void* user_data;
    YR_STREAM_READ_FUNC read;
} YR_STREAM;

typedef struct {
    void* handle;
} THREAD;

typedef struct {
    const char* filename;
    int current_count;
} CALLBACK_ARGS;

typedef struct {
    YR_SCANNER* scanner;
    time_t deadline;
    int current_count;
    CALLBACK_ARGS callback_args;
} THREAD_ARGS;

extern bool follow_symlinks;
extern bool recursive_search;
extern bool show_version;
extern bool show_help;
extern bool rules_are_compiled;
extern bool print_count_only;
extern bool fail_on_warnings;
extern bool show_stats;
extern bool fast_scan;
extern bool scan_list_search;
extern int threads;
extern int stack_size;
extern int max_strings_per_rule;
extern long long max_process_memory_chunk;
extern int timeout;
extern char* atom_quality_table;
extern char** ext_vars;
extern void* options;
extern void* output_mutex;

typedef char char_t;
#define _T(x) x
#define _tfopen fopen
#define _ftprintf fprintf
#define _tprintf printf
#define _tcstol strtol

int args_parse(void* options, int argc, const char** argv);
void args_print_usage(void* options, int columns);
void args_free(void* options);
bool load_modules_data(void);
void exit_with_code(int code);
int yr_initialize(void);
void yr_set_configuration(int config, void* value);
int yr_rules_load_stream(YR_STREAM* stream, YR_RULES** rules);
int define_external_variables(char** vars, YR_RULES* rules, YR_COMPILER* compiler);
int yr_compiler_create(YR_COMPILER** compiler);
void print_error(int error);
int yr_compiler_load_atom_quality_table(YR_COMPILER* compiler, char* table, int quality);
void print_compiler_error(int error_level, const char* file_name, int line_number, const char* message, void* user_data);
void yr_compiler_set_callback(YR_COMPILER* compiler, void (*callback)(int, const char*, int, const char*, void*), void* user_data);
bool compile_files(YR_COMPILER* compiler, int argc, const char** argv);
int yr_compiler_get_rules(YR_COMPILER* compiler, YR_RULES** rules);
void yr_compiler_destroy(YR_COMPILER* compiler);
void print_rules_stats(YR_RULES* rules);
void cli_mutex_init(void* mutex);
bool is_directory(const char* path);
int file_queue_init(void);
int yr_scanner_create(YR_RULES* rules, YR_SCANNER** scanner);
void yr_scanner_set_callback(YR_SCANNER* scanner, int (*callback)(int, void*, void*), void* user_data);
void yr_scanner_set_flags(YR_SCANNER* scanner, int flags);
void yr_scanner_set_timeout(YR_SCANNER* scanner, int timeout);
int cli_create_thread(THREAD* thread, void* (*start)(void*), void* arg);
void scan_dir(const char* dir, SCAN_OPTIONS* opts);
int populate_scan_list(const char* file, SCAN_OPTIONS* opts);
void file_queue_finish(void);
void cli_thread_join(THREAD* thread);
void yr_scanner_destroy(YR_SCANNER* scanner);
void file_queue_destroy(void);
int scan_file(YR_SCANNER* scanner, const char* filename);
int yr_scanner_scan_proc(YR_SCANNER* scanner, int pid);
void print_scanner_error(YR_SCANNER* scanner, int error);
void unload_modules_data(void);
void yr_rules_destroy(YR_RULES* rules);
void yr_finalize(void);
int callback(int message, void* message_data, void* user_data);
void* scanning_thread(void* arg);