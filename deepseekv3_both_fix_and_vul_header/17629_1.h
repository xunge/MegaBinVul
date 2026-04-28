#include <stdint.h>

struct device;
typedef uint32_t u32_t;

#define Z_OOPS(expr)
#define Z_SYSCALL_DRIVER_GPIO(port, op)

int z_impl_gpio_disable_callback(struct device *port, int access_op, u32_t pin);