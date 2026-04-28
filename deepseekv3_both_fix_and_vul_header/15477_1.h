#include <sys/queue.h>
#include <pwd.h>

#define UNSPEC -1
#define SUDOERS_DEBUG_MATCH 0

struct sudoers_parse_tree;
struct member;

struct member_list {
    struct member *tqh_first;
    struct member **tqh_last;
};

struct member {
    TAILQ_ENTRY(member) entries;
};

void debug_decl(const char *, int);
int debug_return_int(int);
int user_matches(const struct sudoers_parse_tree *, const struct passwd *, const struct member *);