#include <stdio.h>
#include <stdlib.h>

#define WQ_MEM_RECLAIM 0
#define ENOMEM 12
#define __init
#define pr_info printf

static const char fm10k_driver_string[] = "fm10k";
static const char fm10k_driver_version[] = "0.0.1";
static const char fm10k_copyright[] = "Copyright";
static const char fm10k_driver_name[] = "fm10k";
static void *fm10k_workqueue;

struct workqueue_struct;
void *alloc_workqueue(const char *fmt, unsigned int flags, int max_active, const char *name);

int fm10k_dbg_init(void);
int fm10k_register_pci_driver(void);