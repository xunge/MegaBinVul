#include <stdint.h>

struct libxenvchan;
void request_notify(struct libxenvchan *ctrl, int type);
uint32_t rd_prod(struct libxenvchan *ctrl);
uint32_t rd_cons(struct libxenvchan *ctrl);

#define VCHAN_NOTIFY_WRITE 0