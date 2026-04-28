#include <stdbool.h>
#include <string.h>
#include <errno.h>

#define __init
#define cf_check

enum thunk {
    THUNK_RETPOLINE,
    THUNK_LFENCE,
    THUNK_JMP
};

extern bool opt_msr_sc_pv;
extern bool opt_msr_sc_hvm;
extern int opt_eager_fpu;
extern int opt_xpti_hwdom;
extern int opt_xpti_domu;
extern int opt_smt;
extern int opt_pv_l1tf_hwdom;
extern int opt_pv_l1tf_domu;
extern int opt_tsx;
extern bool opt_rsb_pv;
extern bool opt_rsb_hvm;
extern int opt_md_clear_pv;
extern int opt_md_clear_hvm;
extern enum thunk opt_thunk;
extern int opt_ibrs;
extern bool opt_ibpb;
extern bool opt_ssbd;
extern int opt_l1d_flush;
extern bool opt_branch_harden;
extern int opt_srb_lock;
extern bool opt_unpriv_mmio;

extern int parse_bool(const char *s, const char *e);
extern int parse_boolean(const char *name, const char *s, const char *e);
extern int cmdline_strcmp(const char *a, const char *b);