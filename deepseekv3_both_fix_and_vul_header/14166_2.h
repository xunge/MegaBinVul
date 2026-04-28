#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define CAPI_MAXCONTR 32
#define CAPI_CTR_DETACHED 0
#define EINVAL 22
#define KERN_NOTICE "<5>"

struct capi_ctr {
    int cnr;
    char *name;
    char *procfn;
    void *procent;
};

extern pthread_mutex_t capi_controller_lock;
extern struct capi_ctr *capi_controller[CAPI_MAXCONTR];
extern int ncontrollers;

void ctr_down(struct capi_ctr *ctr, int state);
void mutex_lock(pthread_mutex_t *mutex);
void mutex_unlock(pthread_mutex_t *mutex);
int remove_proc_entry(const char *name, void *parent);
int printk(const char *fmt, ...);