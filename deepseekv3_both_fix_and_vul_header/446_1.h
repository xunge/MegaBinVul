#include <stddef.h>

struct phy;
struct device;
struct of_phandle_args {
    int args_count;
    unsigned int args[2];
};
struct serdes_ctrl {
    struct phy **phys;
};
struct serdes_macro {
    int idx;
    int port;
};

#define SERDES_MAX 0
#define SERDES6G(x) (x)
#define EINVAL 1
#define EBUSY 2
#define ENODEV 3
#define ERR_PTR(x) ((void*)(long)(x))