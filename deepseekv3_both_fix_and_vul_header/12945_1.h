#include <stddef.h>
#include <stdio.h>
#include <string.h>

typedef enum {
    KDB_REASON_DEBUG,
    KDB_REASON_ENTER,
    KDB_REASON_KEYBOARD,
    KDB_REASON_ENTER_SLAVE,
    KDB_REASON_SWITCH,
    KDB_REASON_OOPS,
    KDB_REASON_SYSTEM_NMI,
    KDB_REASON_NMI,
    KDB_REASON_SSTEP,
    KDB_REASON_BREAK,
    KDB_REASON_RECURSE
} kdb_reason_t;

typedef enum {
    KDB_DB_BPT,
    KDB_DB_SS,
    KDB_DB_SSBPT
} kdb_dbtrap_t;

typedef enum {
    KDB_NOTFOUND,
    KDB_CMD_GO,
    KDB_CMD_CPU,
    KDB_CMD_SS,
    KDB_CMD_KGDB
} kdb_cmddiag_t;

#define KDB_CMD_HISTORY_COUNT 16
#define CMD_BUFLEN 256
#define kdb_machreg_fmt "%lx"

struct task_struct {
    int pid;
};

struct pt_regs {
    unsigned long ip;
};

static inline unsigned long instruction_pointer(struct pt_regs *regs) {
    return regs->ip;
}

extern char *cmd_cur;
extern char *cmd_hist[KDB_CMD_HISTORY_COUNT];
extern int cmd_head;
extern int cmd_tail;
extern int cmdptr;
extern int kdb_go_count;
extern char kdb_diemsg[];
extern char kdb_prompt_str[CMD_BUFLEN];
extern int kdb_nextline;
extern int kdb_grepping_flag;
extern char kdb_grep_string[];
extern int defcmd_in_progress;

#define KDB_STATE(x) (0)
#define KDB_STATE_SET(x) do {} while (0)
#define KDB_STATE_CLEAR(x) do {} while (0)
#define KDB_DEBUG_STATE(msg, val) do {} while (0)

extern struct task_struct *kdb_curr_task(int cpu);
extern int raw_smp_processor_id(void);
extern void kdb_printf(const char *fmt, ...);
extern void kdb_dumpregs(struct pt_regs *regs);
extern char *kdb_getstr(char *buf, size_t buflen, const char *prompt);
extern int kdb_parse(char *cmd);
extern int handle_ctrl_cmd(char *cmd);
extern void drop_newline(char *cmd);
extern void kdb_cmderror(int diag);
extern const char *kdbgetenv(const char *name);