#include <stdint.h>
#include <stdbool.h>

typedef uint64_t hwaddr;
typedef struct MemoryRegion MemoryRegion;
typedef struct DeviceState DeviceState;

typedef enum {
    MEMTX_OK,
    MEMTX_ERROR,
    MEMTX_ACCESS_ERROR
} MemTxResult;

typedef struct {
    bool engaged_in_io;
} MemReentrancyGuard;

typedef struct {
    int dummy;
} MemTxAttrs;

struct MemoryRegion {
    const char *name;
    DeviceState *dev;
    bool disable_reentrancy_guard;
    bool ram_device;
    bool ram;
    bool rom_device;
    bool readonly;
};

struct DeviceState {
    MemReentrancyGuard mem_reentrancy_guard;
};

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAKE_64BIT_MASK(shift, length) (((~0ULL) >> (64 - (length))) << (shift))
#define HWADDR_PRIx "lx"
#define HWADDR_PRIX "lX"

static const char *memory_region_name(const MemoryRegion *mr);
static bool memory_region_big_endian(const MemoryRegion *mr);
static void warn_report_once(const char *fmt, ...);