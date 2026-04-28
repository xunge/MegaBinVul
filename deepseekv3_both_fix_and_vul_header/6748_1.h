#include <limits.h>

#define MAX_INDENT_LEVEL 10
#define INDENT_INCR 4
#define HTML_DT 1

struct table {
    int indent;
};

struct table_mode {
    int indent_level;
};

void setwidth(struct table *tbl, struct table_mode *mode);
void feed_table_inline_tag(struct table *tbl, char *line, struct table_mode *mode, int indent);
void clearcontentssize(struct table *tbl, struct table_mode *mode);
void check_minimum0(struct table *tbl, int val);
void addcontentssize(struct table *tbl, int offset);