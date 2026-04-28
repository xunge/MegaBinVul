#include <stdlib.h>

struct tree {
    char *label;
    struct tree *next;
};

extern void unload_all_mibs(void);
extern void SNMP_FREE(void *);

extern struct tree *tree_top;
extern struct tree *tree_head;
extern void *Mib;
extern char **_mibindexes;
extern int _mibindex;
extern int _mibindex_max;
extern char *Prefix;
extern char Standard_Prefix[];
extern char *confmibs;
extern char *confmibdir;