#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

struct vm_area_struct {
    void *vma;
    unsigned long vm_page_prot;
};

struct gru_thread_state {
    pthread_mutex_t ts_ctxlock;
    void *ts_gru;
    unsigned long ts_steal_jiffies;
    int ts_ctxnum;
};

struct vm_fault {
    struct vm_area_struct *vma;
    unsigned long address;
};

#define VM_FAULT_SIGBUS 0
#define VM_FAULT_NOPAGE 0
#define PAGE_SHIFT 12
#define GRU_GSEG_PAGESIZE 4096
#define GRU_ASSIGN_DELAY 1
#define GRU_STEAL_DELAY 1
#define TASK_INTERRUPTIBLE 0

#define STAT(x)
#define gru_dbg(x, ...)
#define GSEG_BASE(x) (x)
#define TSID(x, y) 0

typedef int vm_fault_t;

#define mutex_lock pthread_mutex_lock
#define mutex_unlock pthread_mutex_unlock
#define preempt_disable()
#define preempt_enable()
#define set_current_state(x)
#define schedule_timeout(x) usleep(x*1000)
#define time_before(a,b) ((a)<(b))
#define jiffies (time(NULL)*1000)
#define remap_pfn_range(a,b,c,d,e) (0)

struct gru_thread_state *gru_find_thread_state(struct vm_area_struct *vma, int tsid);
int gru_check_context_placement(struct gru_thread_state *gts);
void gru_unload_context(struct gru_thread_state *gts, int flag);
int gru_assign_gru_context(struct gru_thread_state *gts);
void gru_load_context(struct gru_thread_state *gts);
unsigned long gseg_physical_address(void *gru, int ctxnum);
void gru_steal_context(struct gru_thread_state *gts);