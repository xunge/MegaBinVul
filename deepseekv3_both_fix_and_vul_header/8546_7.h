#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define __init
#define __pa_symbol(x) ((unsigned long)(x))
#define KERN_INFO ""
#define KERN_DEBUG ""
#define CONFIG_X86_32 1
#define CONFIG_EFI 1
#define CONFIG_BLK_DEV_RAM 1
#define CONFIG_CMDLINE_BOOL 1
#define CONFIG_CMDLINE_OVERRIDE 1
#define COMMAND_LINE_SIZE 2048
#define MS_RDONLY 1
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define E820_RAM 1
#define E820_RESERVED 2
#define EFI_BOOT 0
#define EFI_64BIT 1
#define EFI_MEMMAP 2
#define X86_FEATURE_APIC (1 << 5)
#define KERNEL_PGD_BOUNDARY 0
#define KERNEL_PGD_PTRS 0
#define RAMDISK_IMAGE_START_MASK 0x07FF
#define RAMDISK_PROMPT_FLAG 0x8000
#define RAMDISK_LOAD_FLAG 0x4000
#define EFI32_LOADER_SIGNATURE "EL32"
#define EFI64_LOADER_SIGNATURE "EL64"
#define ISA_END_ADDRESS 0x100000
#define CLOCK_TICK_RATE 1193182
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

struct boot_params {
    struct {
        unsigned int root_dev;
        unsigned int vid_mode;
        unsigned char type_of_loader;
        unsigned char ext_loader_type;
        unsigned char ext_loader_ver;
        unsigned int root_flags;
        unsigned int ram_size;
    } hdr;
    struct {
        char efi_loader_signature[4];
    } efi_info;
    unsigned long screen_info;
    unsigned long edid_info;
    unsigned long apm_bios_info;
    unsigned long ist_info;
};

struct cpuinfo_x86 {
    unsigned long x86_phys_bits;
    unsigned int cpuid_level;
};

struct mm_struct {
    unsigned long start_code;
    unsigned long end_code;
    unsigned long end_data;
    unsigned long brk;
};

struct resource {
    unsigned long start;
    unsigned long end;
};

struct e820_entry {
    unsigned long long addr;
    unsigned long long size;
    int type;
};

struct e820_table {
    struct e820_entry *map;
    unsigned int nr_map;
};

struct x86_init_ops {
    struct {
        void (*arch_setup)(void);
        void (*banner)(void);
    } oem;
    struct {
        void (*probe_roms)(void);
        void (*reserve_resources)(void);
    } resources;
    struct {
        void (*wallclock_init)(void);
    } timers;
    struct {
        void (*pagetable_init)(void);
    } paging;
};

struct apm_info {
    unsigned long bios;
};

struct ist_info {
    unsigned long info;
};

struct efi {
    unsigned long flags;
};

extern char _text[], _etext[], _edata[], __bss_start[], __bss_stop[], _brk_end[];
extern char boot_command_line[], builtin_cmdline[], command_line[];
extern struct boot_params boot_params;
extern struct cpuinfo_x86 boot_cpu_data, new_cpu_data;
extern struct mm_struct init_mm;
extern struct resource code_resource, data_resource, bss_resource, iomem_resource;
extern unsigned long max_pfn, max_low_pfn, max_possible_pfn;
extern unsigned long max_pfn_mapped;
extern void *high_memory;
extern unsigned int root_mountflags;
extern unsigned long saved_video_mode;
extern unsigned long bootloader_type, bootloader_version;
extern unsigned long rd_image_start;
extern int rd_prompt, rd_doload;
extern unsigned long mmu_cr4_features, *trampoline_cr4_features;
extern int disable_apic;
extern char *conswitchp;
extern struct x86_init_ops x86_init;
extern struct e820_table e820;
extern struct efi efi;
extern struct apm_info apm_info;
extern unsigned long ist_info;
extern unsigned long screen_info;
extern unsigned long edid_info;
extern unsigned long ROOT_DEV;
extern unsigned long *swapper_pg_dir;
extern unsigned long *initial_page_table;
extern int smp_found_config;

/* Function declarations */
void memblock_reserve(unsigned long base, unsigned long size);
void early_reserve_initrd(void);
void clone_pgd_range(unsigned long *dst, unsigned long *src, unsigned long count);
void load_cr3(unsigned long *pgd);
void __flush_tlb_all(void);
void olpc_ofw_detect(void);
void early_trap_init(void);
void early_cpu_init(void);
void early_ioremap_init(void);
void setup_olpc_ofw_pgd(void);
unsigned long old_decode_dev(unsigned long dev);
void efi_memblock_x86_reserve_range(void);
void setup_memory_map(void);
void parse_setup_data(void);
void copy_edd(void);
void mpx_mm_init(struct mm_struct *mm);
void x86_configure_nx(void);
void parse_early_param(void);
void x86_report_nx(void);
void memblock_x86_reserve_range_setup_data(void);
int acpi_mps_check(void);
void setup_clear_cpu_cap(unsigned long cap);
void e820_reserve_setup_data(void);
void finish_e820_parsing(void);
void efi_init(void);
void dmi_scan_machine(void);
void dmi_memdev_walk(void);
void dmi_set_dump_stack_arch_desc(void);
void init_hypervisor_platform(void);
void insert_resource(struct resource *parent, struct resource *new);
void e820_add_kernel_range(void);
void trim_bios_range(void);
int ppro_with_ram_bug(void);
void e820_update_range(unsigned long long start, unsigned long long size, int old_type, int new_type);
void sanitize_e820_map(struct e820_entry *map, unsigned int size, unsigned int *nr_map);
void e820_print_map(const char *who);
unsigned long e820_end_of_ram_pfn(void);
void mtrr_bp_init(void);
int mtrr_trim_uncached_memory(unsigned long max_pfn);
void find_low_pfn_range(void);
void find_smp_config(void);
void reserve_ibft_region(void);
void early_alloc_pgt_buf(void);
void reserve_brk(void);
void cleanup_highmap(void);
void memblock_set_current_limit(unsigned long limit);
void memblock_x86_fill(void);
void efi_fake_memmap(void);
void efi_find_mirror(void);
void efi_reserve_boot_services(void);
void early_reserve_e820_mpc_new(void);
void reserve_real_mode(void);
void trim_platform_memory_ranges(void);
void trim_low_memory_range(void);
void init_mem_mapping(void);
void early_trap_pf_init(void);
void setup_real_mode(void);
unsigned long get_max_mapped(void);
void setup_log_buf(int early);
void reserve_initrd(void);
void vsmp_init(void);
void io_delay_init(void);
void acpi_boot_table_init(void);
void early_acpi_boot_init(void);
void initmem_init(void);
void dma_contiguous_reserve(unsigned long limit);
void reserve_crashkernel(void);
void memblock_find_dma_reserve(void);
void kasan_init(void);
void tboot_probe(void);
void map_vsyscall(void);
void generic_apic_probe(void);
void early_quirks(void);
void acpi_boot_init(void);
void sfi_init(void);
void x86_dtb_init(void);
void get_smp_config(void);
void prefill_possible_map(void);
void init_cpu_to_node(void);
void init_apic_mappings(void);
void io_apic_init_mappings(void);
void kvm_guest_init(void);
void e820_reserve_resources(void);
void e820_mark_nosave_regions(unsigned long max_low_pfn);
void e820_setup_gap(void);
void mcheck_init(void);
void arch_init_ideal_nops(void);
void register_refined_jiffies(unsigned long tick_rate);
void efi_apply_memmap_quirks(void);

/* Utility functions */
void *memset(void *s, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
int strncmp(const char *s1, const char *s2, size_t n);
size_t strlcpy(char *dest, const char *src, size_t size);
size_t strlcat(char *dest, const char *src, size_t count);
int printk(const char *fmt, ...);
unsigned long __read_cr4(void);
unsigned long min(unsigned long a, unsigned long b);

static inline void set_bit(int nr, volatile void *addr) {}
static inline int efi_enabled(int feature) { return 0; }