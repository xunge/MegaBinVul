#include <stdio.h>
#include <stdlib.h>

typedef struct int_node {
    int i;
    struct int_node *link;
} int_node;

typedef struct attr_val {
    int attr;
    union {
        int i;
        char *s;
    } value;
    struct attr_val *link;
} attr_val;

typedef struct filegen_node {
    int filegen_token;
    struct attr_val *options;
    struct filegen_node *link;
} filegen_node;

typedef struct FILEGEN {
    const char *prefix;
    const char *basename;
    int flag;
    int type;
} FILEGEN;

typedef struct config_tree {
    const char *stats_dir;
    struct int_node *stats_list;
    struct filegen_node *filegen_opts;
} config_tree;

#define HEAD_PFIFO(x) (x)
#define DPRINTF(level, args)
#define NTP_INSIST(expr)
#define LOG_ERR 0

enum {
    T_File,
    T_Type,
    T_Flag,
    T_None,
    T_Pid,
    T_Day,
    T_Week,
    T_Month,
    T_Year,
    T_Age,
    T_Link,
    T_Nolink,
    T_Enable,
    T_Disable
};

enum {
    FILEGEN_NONE,
    FILEGEN_PID,
    FILEGEN_DAY,
    FILEGEN_WEEK,
    FILEGEN_MONTH,
    FILEGEN_YEAR,
    FILEGEN_AGE
};

enum {
    FGEN_FLAG_ENABLED = (1 << 0),
    FGEN_FLAG_LINK = (1 << 1)
};

enum {
    STATS_STATSDIR
};

void stats_config(int type, const char *path);
const char *keyword(int token);
FILEGEN *filegen_get(const char *name);
void filegen_config(FILEGEN *filegen, const char *filename, int type, int flag);
void msyslog(int priority, const char *format, ...);