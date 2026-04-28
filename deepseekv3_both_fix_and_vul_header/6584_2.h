#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

#define SETWA_FLAGS_APICID 0x1
#define SETWA_FLAGS_MEM 0x2
#define SETWA_FLAGS_PCIE_SBDF 0x4
#define ACPI5_VENDOR_BIT 0x80000000
#define MEM_ERROR_MASK 0xF
#define PAGE_MASK (~(0xFFF))
#define REGION_INTERSECTS 1
#define IORESOURCE_SYSTEM_RAM 0x00000000
#define IORESOURCE_MEM 0x00000200
#define IORES_DESC_NONE 0
#define IORES_DESC_PERSISTENT_MEMORY 0x00100000

typedef uint32_t u32;
typedef uint64_t u64;

static bool param_extension;
static bool acpi5;
static unsigned int vendor_flags;
static int einj_mutex;

int region_intersects(u64 base, u64 size, unsigned long flags, unsigned long desc);
void mutex_lock(int *mutex);
void mutex_unlock(int *mutex);
int __einj_error_inject(u32 type, u32 flags, u64 param1, u64 param2, u64 param3, u64 param4);