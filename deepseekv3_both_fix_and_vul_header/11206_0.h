#include <string.h>
#include <stdbool.h>

#define STRING 1024
#define _ 
#define mutt_error(...)
#define mutt_buffer_addstr(...)
#define mutt_buffer_addch(...)
#define SKIPWS(...)
#define imap_quote_string(...)
#define mutt_bit_isset(...) 0
#define X_GM_EXT1 0

struct Pattern {
    bool not;
    int op;
    union {
        char *str;
    } p;
    struct Pattern *child;
    struct Pattern *next;
};

struct Buffer {
    // buffer implementation
};

struct Context {
    struct ImapData *data;
};

struct ImapData {
    unsigned long capabilities;
};

enum {
    MUTT_OR,
    MUTT_HEADER,
    MUTT_BODY,
    MUTT_WHOLE_MSG,
    MUTT_SERVERSEARCH
};

static int do_search(const struct Pattern *pat, int flag);