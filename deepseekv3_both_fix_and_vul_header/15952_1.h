#include <string.h>
#include <stdio.h>

#define MAX_OPT_ARGS 3

enum {
    Opt_gid,
    Opt_hidepid,
};

typedef struct {
    char *from;
    char *to;
} substring_t;

typedef struct {
    int token;
    char *pattern;
} match_entry_t;

typedef match_entry_t match_table_t[];

struct pid_namespace {
    int pid_gid;
    int hide_pid;
};

static const match_table_t tokens = {
    {Opt_gid, "gid"},
    {Opt_hidepid, "hidepid"},
    {0, NULL},
};

extern char *strsep(char **, const char *);
extern int match_token(char *, const match_table_t *, substring_t *);
extern int match_int(substring_t *, int *);