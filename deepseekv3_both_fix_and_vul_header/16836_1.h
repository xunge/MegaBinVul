#include <string.h>
#include <stdbool.h>

#define __init
#define cf_check

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
extern int opt_ibpb_entry_pv;
extern int opt_ibpb_entry_hvm;
extern bool opt_ibpb_entry_dom0;
extern int opt_thunk;
extern int opt_ibrs;
extern bool opt_ibpb_ctxt_switch;
extern bool opt_ssbd;
extern int opt_l1d_flush;
extern bool opt_branch_harden;
extern int opt_srb_lock;
extern bool opt_unpriv_mmio;
extern int opt_gds_mit;
extern int opt_div_scrub;
extern int opt_stibp;
extern int opt_psfd;

#define THUNK_JMP 0
#define THUNK_RETPOLINE 1
#define THUNK_LFENCE 2

#define EINVAL 22

static int parse_bool(const char *s, const char *e);
static int parse_boolean(const char *name, const char *s, const char *e);
static int cmdline_strcmp(const char *s1, const char *s2);