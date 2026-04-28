#include <stdbool.h>

struct sunkbd {
    void *serio;
    bool enabled;
    void *wait;
    void *tq;
};