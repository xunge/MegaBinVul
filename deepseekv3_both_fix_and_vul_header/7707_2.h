#include <stdlib.h>
#include <stdbool.h>

struct tcf_exts {
    // 最小化定义以满足编译
    int dummy;
};

struct tc_u_knode {
    struct tc_u_hnode *ht_down;
    struct tcf_exts exts;
#ifdef CONFIG_CLS_U32_PERF
    void *pf;
#endif
#ifdef CONFIG_CLS_U32_MARK
    void *pcpu_success;
#endif
};

struct tc_u_hnode {
    int refcnt;
};

#define rtnl_dereference(p) (p)
#define tcf_exts_destroy(exts) 
#define tcf_exts_put_net(exts) 
#define kfree(p) free(p)
#define free_percpu(p) free(p)