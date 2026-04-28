#include <stdbool.h>

struct domain {
    struct {
        struct arch_csw *ctxt_switch;
        struct {
            struct {
                bool exec_sp;
            } vmx;
        } hvm;
    } arch;
};

struct arch_csw {
    void (*from)(void);
    void (*to)(void);
    void (*tail)(void);
};

extern void vmx_ctxt_switch_from(void);
extern void vmx_ctxt_switch_to(void);
extern void vmx_do_resume(void);
extern bool is_hardware_domain(struct domain *d);
extern bool opt_ept_exec_sp;

#define cf_check