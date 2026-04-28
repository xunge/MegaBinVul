#include <sys/socket.h>
#include <linux/tipc.h>

struct tipc_msg;
struct msghdr;

static inline unsigned int msg_origport(struct tipc_msg *m) { return 0; }
static inline unsigned int msg_orignode(struct tipc_msg *m) { return 0; }