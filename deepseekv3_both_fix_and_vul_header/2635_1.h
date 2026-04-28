#include <stddef.h>

struct efi_info {
    unsigned long efi_loader_signature;
    unsigned long efi_systab;
    unsigned long efi_systab_hi;
    unsigned int efi_memdesc_version;
    unsigned int efi_memdesc_size;
    unsigned int efi_memmap_size;
};

struct boot_params {
    struct efi_info efi_info;
    int secure_boot;
};

extern struct boot_params boot_params;
extern int efi_enabled(int);
extern unsigned int efi_get_runtime_map_desc_size(void);
extern void setup_efi_info_memmap(struct boot_params *, unsigned long, unsigned int, unsigned int);
extern void prepare_add_efi_setup_data(struct boot_params *, unsigned long, unsigned int);

#define EFI_OLD_MEMMAP 1