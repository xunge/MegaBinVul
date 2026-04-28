#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>

typedef uint64_t ut64;
typedef uint8_t ut8;

#define UT64_MAX UINT64_MAX
#define IS_WHITESPACE(c) (c == ' ' || c == '\t' || c == '\n' || c == '\r')
#define ISWHITECHAR(c) (c == ' ' || c == '\t' || c == '\n' || c == '\r')
#define IS_DIGIT(c) (c >= '0' && c <= '9')
#define R_ABS(x) ((x) < 0 ? -(x) : (x))
#define R_FREE(x) { free(x); x = NULL; }
#define R_ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))
#define PFMT64x "llx"

typedef struct RNum {
    ut64 value;
} RNum;

typedef struct RIO {
    int raised;
} RIO;

typedef struct RCore {
    void *rcmd;
    void *config;
    RNum *num;
    void *flags;
    void *dbg;
    RIO *io;
    void *sdb;
    ut64 offset;
    char *block;
    int blocksize;
    bool fixedblock;
    bool tmpseek;
    char *oobi;
    int oobi_len;
} RCore;

static char* r_str_trim_head_tail(char *str) { return str; }
static char* r_str_replace(char *str, const char *key, const char *val, bool global) { return str; }
static char* r_str_clean(char *str) { return str; }
static char* r_str_append(char *str, const char *append) { return str; }
static bool r_str_endswith(const char *str, const char *suffix) { return false; }
static const char* r_str_lastbut(const char *str, char ch, const char *ignore) { return NULL; }
static char* find_eoq(char *str) { return NULL; }
static char* findSeparator(char *str) { return NULL; }
static char* parse_tmp_evals(RCore *core, char *str) { return NULL; }
static void helpCmdAt(RCore *core) {}
static void recursive_help(RCore *core, char *cmd) {}
static int r_cmd_call(void *rcmd, char *cmd) { return 0; }
static int r_core_cmd_subst(RCore *core, char *cmd) { return 0; }
static char* r_core_cmd_str(RCore *core, char *cmd) { return NULL; }
static char* r_core_cmd_str_pipe(RCore *core, char *cmd) { return NULL; }
static void r_core_cmd_pipe(RCore *core, char *cmd1, char *cmd2) {}
static void r_core_cmd0(RCore *core, char *cmd) {}
static bool r_core_seek(RCore *core, ut64 addr, bool silent) { return false; }
static void r_core_block_read(RCore *core) {}
static void r_core_block_size(RCore *core, int size) {}
static int r_core_cmd_foreach(RCore *core, char *cmd, char *arg) { return 0; }
static int r_core_cmd_foreach3(RCore *core, char *cmd, char *arg) { return 0; }
static int r_cons_pipe_open(char *file, int fd, bool append) { return 0; }
static void r_cons_pipe_close(int fd) {}
static void r_cons_flush() {}
static void r_cons_set_interactive(bool b) {}
static void r_cons_set_last_interactive() {}
static void r_cons_grep_help() {}
static void r_cons_grep_parsecmd(char *cmd, const char *quotestr) {}
static void r_cons_break_push(void *a, void *b) {}
static void r_cons_break_pop() {}
static int r_config_get_i(void *config, const char *key) { return 0; }
static void r_config_set_i(void *config, const char *key, int val) {}
static char* r_config_get(void *config, const char *key) { return NULL; }
static void r_config_set(void *config, const char *key, const char *val) {}
static ut64 r_num_math(void *num, const char *str) { return 0; }
static void* r_flag_get(void *flags, const char *name) { return NULL; }
static ut64 r_debug_reg_get(void *dbg, const char *name) { return 0; }
static void r_io_raise(void *io, int fd) {}
static int r_io_system(void *io, char *cmd) { return 0; }
static char* r_file_temp(const char *prefix) { return NULL; }
static void r_file_rm(const char *file) {}
static int r_hex_str2bin(const char *str, char *out) { return 0; }
static void* r_file_slurp(const char *file, int *size) { return NULL; }
static void eprintf(const char *fmt, ...) {}
static int r_sys_cmdf(const char *fmt, ...) { return 0; }
static char* r_str_newf(const char *fmt, ...) { return NULL; }
static char* r_str_trim_head(char *str) { return str; }
static void r_core_cmdf(RCore *core, const char *fmt, ...) {}
static char* sdb_querys(void *sdb, void *a, int b, char *c) { return NULL; }