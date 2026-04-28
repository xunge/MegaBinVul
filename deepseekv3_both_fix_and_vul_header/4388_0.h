#include <stddef.h>

void (*pgm_check_table[128])(void);

void default_trap_handler(void);
void illegal_op(void);
void privileged_op(void);
void execute_exception(void);
void do_protection_exception(void);
void addressing_exception(void);
void specification_exception(void);
void data_exception(void);
void overflow_exception(void);
void divide_exception(void);
void hfp_overflow_exception(void);
void hfp_underflow_exception(void);
void hfp_significance_exception(void);
void hfp_divide_exception(void);
void do_dat_exception(void);
void translation_exception(void);
void special_op_exception(void);
void do_asce_exception(void);
void operand_exception(void);
void space_switch_exception(void);
void hfp_sqrt_exception(void);
void do_monitor_call(void);
void pfault_irq_init(void);

#define __init
#define CONFIG_64BIT