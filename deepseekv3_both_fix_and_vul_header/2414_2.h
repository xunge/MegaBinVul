#include <stdlib.h>

struct device {
    // minimal device structure definition
    int dummy;
};

struct snd_seq_device {
    struct device dev;
};

struct snd_device {
    void *device_data;
};

void put_device(struct device *dev);