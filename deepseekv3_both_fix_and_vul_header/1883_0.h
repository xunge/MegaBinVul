#include <errno.h>
#include <string.h>

struct connection;
struct buffered_data;
struct node;

#define XS_PERM_WRITE 0
#define XS_RM 0
#define ENOENT 2
#define ENOMEM 12
#define EINVAL 22

static struct node *get_node_canonicalized(struct connection *conn, const void *ctx, const char *arg, char **name, int perm);
static char *get_parent(const void *ctx, const char *name);
static struct node *read_node(struct connection *conn, const void *ctx, const char *name);
static void send_ack(struct connection *conn, int type);
static int _rm(struct connection *conn, const void *ctx, const char *name);
static int streq(const char *a, const char *b);
static int read_node_can_propagate_errno(void);
static const char *onearg(struct buffered_data *in);