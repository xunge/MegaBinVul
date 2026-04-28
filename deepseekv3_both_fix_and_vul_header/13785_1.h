#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

typedef uint64_t ut64;

typedef struct {
    int cmd_depth;
} RConsContext;

typedef struct {
    RConsContext *context;
} RCons;

typedef struct {
    bool cur_enabled;
} RPrint;

typedef struct {
    ut64 offset;
    ut64 prompt_offset;
    int max_cmd_depth;
    RCons *cons;
    int cmdrepeat;
    bool tmpseek;
    bool break_loop;
    RPrint *print;
    int seltab;
    int curtab;
    const char *cmdtimes;
} RCore;

#define IS_DIGIT(c) ((c) >= '0' && (c) <= '9')
#define INTERACTIVE_MAX_REP 1000
#define PFMT64d "llu"

static int r_core_cmd0(RCore *core, char *cmd);
static int r_core_cmd_repeat(RCore *core, bool b);
static int r_core_cmd_nullcallback(RCore *core);
static int r_core_cmd_subst_i(RCore *core, char *cmd, char *colon, bool *tmpseek);
static void r_core_seek(RCore *core, ut64 offset, int b);
static bool r_cons_is_interactive(void);
static bool r_cons_yesno(char c, const char *msg, ut64 rep);
static void r_cons_break_push(void *a, void *b);
static void r_cons_break_pop(void);
static bool r_cons_is_breaked(void);
static void r_cons_flush(void);
static void r_cons_printf(const char *fmt, ...);
static char *r_str_trim_head_tail(char *s);
static bool r_str_startswith(const char *str, const char *prefix);
static char *r_str_firstbut(const char *str, char c, const char *b);
static bool r_sandbox_enable(int b);
static void eprintf(const char *fmt, ...);