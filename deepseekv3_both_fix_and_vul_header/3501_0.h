#include <stdint.h>

struct libxenvchan;

void request_notify(struct libxenvchan *ctrl, int type);
uint32_t wr_ring_size(struct libxenvchan *ctrl);
uint32_t wr_prod(struct libxenvchan *ctrl);
uint32_t wr_cons(struct libxenvchan *ctrl);

#define VCHAN_NOTIFY_READ 0