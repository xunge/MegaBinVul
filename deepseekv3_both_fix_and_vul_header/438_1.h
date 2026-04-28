#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
  JERRY_INIT_EMPTY = 0,
  JERRY_INIT_MEM_STATS = (1 << 0),
  JERRY_INIT_SHOW_OPCODES = (1 << 1),
  JERRY_INIT_SHOW_REGEXP_OPCODES = (1 << 2)
} jerry_init_flag_t;

typedef enum
{
  JERRY_LOG_LEVEL_ERROR = 0,
  JERRY_LOG_LEVEL_WARNING = 1,
  JERRY_LOG_LEVEL_DEBUG = 2,
  JERRY_LOG_LEVEL_TRACE = 3
} jerry_log_level_t;

typedef enum
{
  JERRY_ERROR_COMMON = 0
} jerry_error_t;

typedef unsigned int jerry_char_t;
typedef unsigned int jerry_size_t;
typedef int jerry_value_t;
typedef unsigned int jerry_length_t;

typedef enum
{
  JERRY_DEBUGGER_SOURCE_RECEIVE_FAILED,
  JERRY_DEBUGGER_SOURCE_END,
  JERRY_DEBUGGER_SOURCE_RECEIVED,
  JERRY_DEBUGGER_CONTEXT_RESET_RECEIVED
} jerry_debugger_wait_for_source_status_t;

typedef struct
{
  const char *error;
  const char *arg;
} cli_state_t;

typedef struct
{
} jerry_instance_t;

#define JERRY_VLA(type, name, size) type name[size]
#define JERRY_STANDALONE_EXIT_CODE_OK 0
#define JERRY_STANDALONE_EXIT_CODE_FAIL 1
#define JERRY_API_MAJOR_VERSION 0
#define JERRY_API_MINOR_VERSION 0
#define JERRY_COMMIT_HASH ""
#define JERRY_FEATURE_MEM_STATS 0
#define JERRY_FEATURE_PARSER_DUMP 0
#define JERRY_FEATURE_REGEXP_DUMP 0
#define JERRY_FEATURE_DEBUGGER 0
#define JERRY_FEATURE_SNAPSHOT_EXEC 0
#define JERRY_ENABLE_EXTERNAL_CONTEXT 0
#define JERRY_PARSE_NO_OPTS 0
#define JERRY_SNAPSHOT_EXEC_COPY_DATA 0

enum
{
  OPT_HELP,
  OPT_VERSION,
  OPT_MEM_STATS,
  OPT_PARSE_ONLY,
  OPT_SHOW_OP,
  OPT_SHOW_RE_OP,
  OPT_DEBUG_SERVER,
  OPT_DEBUG_PORT,
  OPT_DEBUGGER_WAIT_SOURCE,
  OPT_EXEC_SNAP,
  OPT_EXEC_SNAP_FUNC,
  OPT_LOG_LEVEL,
  OPT_ABORT_ON_FAIL,
  OPT_NO_PROMPT,
  CLI_OPT_END,
  CLI_OPT_DEFAULT
};

extern const char *main_opts[];
extern uint8_t buffer[];
extern jerry_value_t (*wait_for_source_callback)(void *);
extern void *instance_alloc(size_t size, void *cb_data);

extern unsigned int jerry_port_get_current_time(void);
extern void jerry_init(jerry_init_flag_t flags);
extern void jerry_port_default_set_log_level(jerry_log_level_t level);
extern void jerry_port_default_set_abort_on_fail(bool abort);
extern void jerry_port_log(jerry_log_level_t level, const char *format, ...);
extern void jerry_port_default_set_instance(jerry_instance_t *instance_p);
extern jerry_instance_t *jerry_create_instance(size_t size, void *(*alloc)(size_t, void *), void *cb_data);
extern jerry_value_t jerry_create_undefined(void);
extern jerry_value_t jerry_create_error(jerry_error_t error_type, const jerry_char_t *message);
extern bool jerry_value_is_error(const jerry_value_t value);
extern bool jerry_is_feature_enabled(int feature);
extern jerry_value_t jerry_parse(const jerry_char_t *resource_name, size_t resource_name_length, const jerry_char_t *source_p, size_t source_size, int parse_opts);
extern jerry_value_t jerry_run(const jerry_value_t func_val);
extern void jerry_release_value(jerry_value_t value);
extern jerry_value_t jerry_get_value_from_error(jerry_value_t error_value, bool release_error);
extern bool jerry_value_is_abort(const jerry_value_t value);
extern bool jerry_value_is_string(const jerry_value_t value);
extern jerry_value_t jerry_value_to_string(const jerry_value_t value);
extern jerry_size_t jerry_get_string_size(const jerry_value_t value);
extern void jerry_string_to_char_buffer(const jerry_value_t value, jerry_char_t *buffer, jerry_size_t buffer_size);
extern jerry_value_t jerry_eval(const uint8_t *source_p, size_t source_size, int parse_opts);
extern jerry_value_t jerry_run_all_enqueued_jobs(void);
extern void jerry_cleanup(void);
extern jerry_value_t jerry_exec_snapshot(const uint32_t *snapshot_p, size_t snapshot_size, uint32_t exec_snapshot_index, int exec_snapshot_opts);
extern bool jerry_is_valid_utf8_string(const jerry_char_t *string_p, jerry_size_t string_size);
extern jerry_value_t jerryx_handler_print(jerry_value_t func_obj, jerry_value_t this_p, const jerry_value_t args_p[], jerry_length_t args_cnt);
extern void *read_file(const char *file_name, size_t *out_size_p);
extern void print_unhandled_exception(jerry_value_t exception_value);
extern cli_state_t cli_init(const char *opts[], int argc, char *argv[]);
extern int cli_consume_option(cli_state_t *state_p);
extern const char *cli_consume_string(cli_state_t *state_p);
extern long int cli_consume_int(cli_state_t *state_p);
extern void cli_help(const char *prog_name, const char *description, const char *opts[]);
extern bool check_feature(int feature, const char *arg);
extern void check_usage(bool condition, const char *prog_name, const char *error_msg, const char *arg);
extern void init_engine(jerry_init_flag_t flags, bool start_debug_server, uint16_t debug_port);
extern jerry_debugger_wait_for_source_status_t jerry_debugger_wait_for_client_source(jerry_value_t (*callback)(void *), void *user_p, jerry_value_t *run_result_p);
extern jerry_value_t jerry_acquire_value(jerry_value_t value);