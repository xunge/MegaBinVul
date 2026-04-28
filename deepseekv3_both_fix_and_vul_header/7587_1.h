#include <stdlib.h>

struct rtrs_clt_sess {
    struct {
        int dummy;  // Placeholder for device structure
    } dev;
    struct {
        int dummy;  // Placeholder for mutex structure
    } paths_ev_mutex;
    struct {
        int dummy;  // Placeholder for mutex structure
    } paths_mutex;
    void *pcpu_path;
};

void free_permits(struct rtrs_clt_sess *clt);
void free_percpu(void *ptr);
void device_unregister(void *dev);