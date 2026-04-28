#include <assert.h>
#include <stdlib.h>

typedef struct GF_Filter {
    void *tasks_mx;
} GF_Filter;

typedef struct GF_FilterPid {
    GF_Filter *filter;
    void *properties;
} GF_FilterPid;

typedef struct GF_PropertyStore {
    int reference_count;
} GF_PropertyStore;

typedef struct GF_FilterPidInst {
    void *packets;
    void *pck_mx;
    void *pck_reassembly;
    GF_PropertyStore *props;
    GF_FilterPid *pid;
} GF_FilterPidInst;

typedef void (*gf_destruct_fun)(void *);

void gf_filter_pid_inst_reset(GF_FilterPidInst *pidinst);
void gf_fq_del(void *fq, gf_destruct_fun del_fun);
void gf_mx_del(void *mx);
void gf_list_del(void *list);
int safe_int_dec(int *val);
void gf_mx_p(void *mx);
void gf_mx_v(void *mx);
void gf_list_del_item(void *list, void *item);
void gf_props_del(GF_PropertyStore *props);
void gf_free(void *ptr);
void pcki_del(void *pck);