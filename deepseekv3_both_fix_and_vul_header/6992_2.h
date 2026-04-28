#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint64_t ut64;
#define UT64_MAX UINT64_MAX
#define PFMT64x PRIx64
#define R_SYS_DIR "/"

typedef struct RCore {
    ut64 offset;
    void *anal;
    void *num;
    void *config;
} RCore;

typedef struct RAnalFunction {
    void *bbs;
} RAnalFunction;

typedef struct RAnalBlock {
    ut64 addr;
    int size;
} RAnalBlock;

typedef struct RListIter {
    void *data;
    struct RListIter *n;
    struct RListIter *p;
} RListIter;

typedef struct RCoreUndo {
    ut64 offset;
    char *redo;
    char *undo;
} RCoreUndo;

enum {
    R_META_TYPE_COMMENT,
};

static const char *help_msg_CC = "";

void r_core_cmd_help(RCore *core, const char *help);
void r_meta_print_list_all(void *anal, int type, char delim, const char *input);
void r_meta_print_list_in_function(void *anal, int type, char delim, ut64 addr, const char *input);
void r_meta_set_string(void *anal, int type, ut64 addr, const char *str);
void r_meta_set(void *anal, int type, ut64 addr, ut64 size, const char *str);
void r_meta_del(void *anal, int type, ut64 addr, ut64 size);
void r_cons_printf(const char *fmt, ...);
void r_cons_println(const char *str);
void eprintf(const char *fmt, ...);
void r_core_cmdf(RCore *core, const char *fmt, ...);
void r_core_undo_push(RCore *core, RCoreUndo *undo);
void r_sys_perror(const char *msg);

const char* r_meta_get_string(void *anal, int type, ut64 addr);
RAnalFunction* r_anal_get_fcn_in(void *anal, ut64 addr, int type);
ut64 r_num_math(void *num, const char *str);
bool r_config_get_b(void *config, const char *key);
RCoreUndo* r_core_undo_new(ut64 offset, const char *redo, const char *undo);

char* r_str_newf(const char *fmt, ...);
char* r_str_trim_head_ro(const char *str);
char* r_str_between(const char *str, const char *prefix, const char *suffix);
char* r_str_unescape(char *str);
char* r_core_editor(RCore *core, const char *file, const char *str);
char* getcommapath(RCore *core);

#define r_list_foreach(list, it, pos) \
    for ((it) = (list)? (RListIter *)(list): NULL; (it) && ((pos) = (it)->data, 1); (it) = (it)->n)