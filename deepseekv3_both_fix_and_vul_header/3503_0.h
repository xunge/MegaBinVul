#include <stddef.h>

struct libxenvchan;
int wr_ring_size(struct libxenvchan *ctrl);
int wr_prod(struct libxenvchan *ctrl);
int wr_cons(struct libxenvchan *ctrl);
void request_notify(struct libxenvchan *ctrl, int notify_type);

#define VCHAN_NOTIFY_READ 0