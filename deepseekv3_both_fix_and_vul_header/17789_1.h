#include <stddef.h>

struct tty_struct {
    void *disc_data;
};

struct slip {
    void *tx_work;
};

void schedule_work(void *work);