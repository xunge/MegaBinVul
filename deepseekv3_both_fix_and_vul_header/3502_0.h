#include <stddef.h>

struct libxenvchan;
int rd_prod(struct libxenvchan *ctrl);
int rd_cons(struct libxenvchan *ctrl);
void request_notify(struct libxenvchan *ctrl, int notify_type);

#define VCHAN_NOTIFY_WRITE 0