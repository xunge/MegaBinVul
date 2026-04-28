#include <stdbool.h>
#include <stddef.h>

#define X86_CR4_VMXE 0x2000
#define HVM_HAP_SUPERPAGE_2MB (1 << 0)
#define HVM_HAP_SUPERPAGE_1GB (1 << 1)
#define __init

struct hvm_function_table {
    bool singlestep_supported;
    void (*set_descriptor_access_exiting)(void);
    int hap_supported;
    int altp2m_supported;
    unsigned int hap_capabilities;
    void (*update_eoi_exit_bitmap)(void);
    void (*process_isr)(void);
    void (*handle_eoi)(void);
    bool virtual_intr_delivery_enabled;
    void (*deliver_posted_intr)(void);
    void (*sync_pir_to_irr)(void);
    void (*test_pir)(void);
    struct {
        unsigned int ratio_frac_bits;
        void (*setup)(void);
    } tsc_scaling;
};

extern struct hvm_function_table vmx_function_table;
extern bool cpu_has_monitor_trap_flag;
extern bool cpu_has_vmx_dt_exiting;
extern bool cpu_has_vmx_ept;
extern bool cpu_has_vmx_pat;
extern bool opt_force_ept;
extern bool cpu_has_vmx_ept_2mb;
extern bool cpu_has_vmx_ept_1gb;
extern bool cpu_has_vmx_virtual_intr_delivery;
extern bool cpu_has_vmx_posted_intr_processing;
extern bool cpu_has_vmx_tsc_scaling;
extern bool iommu_intpost;
extern int opt_ept_exec_sp;
extern int posted_intr_vector;
extern int pi_wakeup_vector;

void set_in_cr4(unsigned long);
int vmx_vmcs_init(void);
int alloc_vlapic_mapping(void);
void printk(const char *);
void vmx_set_descriptor_access_exiting(void);
bool has_if_pschange_mc(void);
void setup_ept_dump(void);
void vmx_update_eoi_exit_bitmap(void);
void vmx_process_isr(void);
void vmx_handle_eoi(void);
void alloc_direct_apic_vector(int *, void (*)(void));
void pi_notification_interrupt(void);
void pi_wakeup_interrupt(void);
void vmx_deliver_posted_intr(void);
void vmx_sync_pir_to_irr(void);
void vmx_test_pir(void);
void vmx_setup_tsc_scaling(void);
void lbr_tsx_fixup_check(void);
void ler_to_fixup_check(void);