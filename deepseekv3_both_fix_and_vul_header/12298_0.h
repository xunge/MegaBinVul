#include <stdio.h>

typedef unsigned char char_u;
typedef int idx_T;
typedef unsigned long long_u;

#define TRUE 1
#define SP_TRUNCERROR -1
#define SP_FORMERROR -2
#define SP_OTHERERROR -3

extern char_u *lalloc(long_u len, int flag);
extern void *lalloc_clear(long_u len, int flag);
extern int get4c(FILE *fd);
extern int read_tree_node(FILE *fd, char_u *bp, idx_T *ip, int len, int startidx, int prefixtree, int prefixcnt);