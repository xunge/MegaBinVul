#include <stddef.h>

#define OPENERS_CHAIN_FIRST 0
#define OPENERS_CHAIN_LAST 4

typedef struct MD_MARK {
    int flags;
    int prev;
    int next;
    char ch;
} MD_MARK;

typedef struct MD_MARKCHAIN {
    int head;
    int tail;
} MD_MARKCHAIN;

typedef struct MD_CTX {
    MD_MARK* marks;
    MD_MARKCHAIN* mark_chains;
} MD_CTX;

#define MD_MARK_OPENER (1 << 0)
#define MD_MARK_CLOSER (1 << 1)
#define MD_MARK_RESOLVED (1 << 2)

#define MD_ROLLBACK_ALL 0
#define MD_ROLLBACK_CROSSING 1

#define MD_UNREACHABLE() ((void)0)

extern MD_MARKCHAIN ASTERISK_OPENERS;
extern MD_MARKCHAIN UNDERSCORE_OPENERS;
extern MD_MARKCHAIN BACKTICK_OPENERS;
extern MD_MARKCHAIN LOWERTHEN_OPENERS;
extern MD_MARKCHAIN TILDE_OPENERS;

void md_mark_chain_append(MD_CTX* ctx, MD_MARKCHAIN* chain, int mark_index);