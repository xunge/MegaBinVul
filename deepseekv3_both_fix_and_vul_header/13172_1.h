#include <stddef.h>

struct net;
struct sctp_bind_addr {
    int port;
    struct {
        struct sctp_sockaddr_entry *next;
    } address_list;
};
struct sctp_sockaddr_entry {
    struct sctp_sockaddr_entry *list;
    int a;
};
enum sctp_scope {
    SCTP_SCOPE_GLOBAL,
    SCTP_SCOPE_LINK
};
typedef int gfp_t;

#define ENETUNREACH 101

#define list_for_each_entry(pos, head, member) \
    for (pos = (head)->next; pos != NULL; pos = pos->member)
#define list_empty(head) ((head)->next == NULL)

int sctp_copy_one_addr(struct net *net, struct sctp_bind_addr *dest,
                      const struct sctp_sockaddr_entry *addr,
                      enum sctp_scope scope, gfp_t gfp, int flags);
void sctp_bind_addr_clean(struct sctp_bind_addr *addr);