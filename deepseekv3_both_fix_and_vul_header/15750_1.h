#include <stdint.h>
#include <stdio.h>

#define METHOD_NAME__ADR "_ADR"
#define SDW_LINK_TYPE 4

typedef uint32_t u32;
typedef uint64_t u64;
typedef int acpi_status;
typedef void* acpi_handle;

#define ACPI_FAILURE(status) (status != 0)
#define AE_OK 0
#define AE_NOT_FOUND 5
#define AE_CTRL_TERMINATE 0x10

#define GENMASK(h, l) (((~0UL) << (l)) & (~0UL >> (63 - (h))))
#define FIELD_GET(mask, reg) (((reg) & (mask)) >> __builtin_ctz(mask))

struct acpi_device;
struct sdw_intel_acpi_info {
    acpi_handle handle;
};

int acpi_bus_get_device(acpi_handle handle, struct acpi_device **adev);
acpi_status acpi_evaluate_integer(acpi_handle handle, const char *pathname, void *args, u64 *data);