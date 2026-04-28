#include <sys/queue.h>
#include <pwd.h>

#define UNSPEC -1

struct member;
struct member_list;
struct sudoers_parse_tree;

struct member {
    TAILQ_ENTRY(member) entries;
};

TAILQ_HEAD(member_list, member);

int host_matches(const struct sudoers_parse_tree *parse_tree,
    const struct passwd *pw, const char *lhost, const char *shost,
    const struct member *m);

#define debug_decl(func, sub) 
#define debug_return_int(ret) return (ret)