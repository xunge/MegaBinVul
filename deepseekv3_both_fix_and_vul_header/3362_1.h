#include <stdint.h>
#include <stddef.h>

typedef uint64_t uleb128_t;
typedef uint8_t u8;

enum item_location {
    ITEM_LOCATION_UNKNOWN
};

struct unwind_state {
    struct {
        enum item_location where;
        const u8 *expr;
    } regs[16]; // Assuming reasonable array size
};

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

extern struct unwind_state REG_STATE;
extern uleb128_t get_uleb128(const u8 **expr, const u8 *end);
extern void dbug_unwind(int level, const char *fmt, ...);