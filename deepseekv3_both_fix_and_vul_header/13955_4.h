#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define __init
#define __va(x) ((void *)(x))
#define COMMAND_LINE_SIZE 2048
#define EFI_CONVENTIONAL_MEMORY 0

typedef uint64_t u64;

struct ia64_boot_param {
    char *command_line;
};

struct consw {
    int dummy;
};

struct efi {
    u64 sal_systab;
};

extern struct efi efi;
extern struct consw dummy_con;
extern struct consw vga_con;
extern struct consw *conswitchp;

extern u64 __start___vtop_patchlist;
extern u64 __end___vtop_patchlist;
extern u64 __start___rse_patchlist;
extern u64 __end___rse_patchlist;
extern struct ia64_boot_param *ia64_boot_param;
extern char boot_command_line[];
extern unsigned long early_cpu_possible_map;
extern int additional_cpus;
extern int nomca;

extern void unw_init(void);
extern void ia64_patch_vtop(u64 start, u64 end);
extern void ia64_patch_rse(u64 start, u64 end);
extern void efi_init(void);
extern void io_port_init(void);
extern void machvec_init_from_cmdline(char *cmdline);
extern void parse_early_param(void);
extern int early_console_setup(char *cmdline);
extern void mark_bsp_online(void);
extern void acpi_table_init(void);
extern void acpi_numa_init(void);
extern void per_cpu_scan_finalize(int ncpus, int additional_cpus);
extern void smp_build_cpu_map(void);
extern void find_memory(void);
extern void ia64_sal_init(void *sal_systab);
extern void cpu_init(void);
extern void mmu_context_init(void);
extern void check_sal_cache_flush(void);
extern void acpi_boot_init(void);
extern void ia64_mca_init(void);
extern void platform_setup(char **cmdline_p);
extern void paging_init(void);
extern int cpus_weight(unsigned long mask);
extern int hard_smp_processor_id(void);
extern int cpu_physical_id(int cpu);
extern int efi_mem_type(unsigned long addr);
extern int ia64_pal_rse_info(u64 *num_phys_stacked, int flag);

size_t strlcpy(char *dst, const char *src, size_t size);