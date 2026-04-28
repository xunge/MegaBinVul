#include <time.h>

struct timer_list {
    int dummy;
};

struct saa7134_dev {
    struct {
        struct timer_list timeout;
    } vbi_q;
};