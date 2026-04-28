#include <stddef.h>
#include <string.h>
#include <stdlib.h>

struct config_item {
    // minimal definition to make it complete type
    char dummy;
};

struct acpi_table_header {
    char signature[4];
    unsigned int length;
    // other minimal required fields
    char dummy[16];
};

struct acpi_table {
    struct config_item cfg;
    struct acpi_table_header *header;
    unsigned int index;
};

#define ACPI_SIG_SSDT "SSDT"
#define LOCKDOWN_ACPI_TABLES 0
#define GFP_KERNEL 0
#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

void *kmemdup(const void *src, size_t len, int gfp);
void kfree(const void *objp);
int security_locked_down(int what);
int acpi_load_table(struct acpi_table_header *header, unsigned int *index);
void pr_err(const char *fmt, ...);

#define EBUSY 16
#define EINVAL 22
#define ENOMEM 12