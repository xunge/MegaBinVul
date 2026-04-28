#include <sys/queue.h>
#include <stddef.h>

#define UNSPEC (-1)

struct sudoers_parse_tree;
struct member_list;
struct cmnd_info;
struct member {
    TAILQ_ENTRY(member) entries;
};

TAILQ_HEAD(member_list, member);

#define debug_decl(func, flag)
#define debug_return_int(val) return (val)