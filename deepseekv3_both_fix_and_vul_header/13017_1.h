#include <linux/types.h>
#include <linux/errno.h>

struct gru_tlb_fault_handle {
    // placeholder for struct members
};

struct gru_state {
    int gs_gid;
    void *gs_gru_base_vaddr;
    // placeholder for other struct members
};

struct gru_thread_state {
    struct gru_state *ts_gru;
    int ts_force_cch_reload;
    int ts_cbr_au_count;
    int ts_ctxnum;
    // placeholder for other struct members
};

#define GRU_HANDLE_STRIDE 1
#define GRU_NUM_CB 1
#define GRU_CBR_AU_SIZE 1

#define STAT(x)
#define gru_dbg(dev, fmt, ...)

extern struct gru_device *grudev;
extern int get_cb_number(void *cb);
extern struct gru_thread_state *gru_find_lock_gts(unsigned long cb);
extern void gru_unlock_gts(struct gru_thread_state *gts);
extern void gru_unload_context(struct gru_thread_state *gts, int flag);
extern int gru_check_context_placement(struct gru_thread_state *gts);
extern void gru_update_cch(struct gru_thread_state *gts);
extern int thread_cbr_number(struct gru_thread_state *gts, int ucbnum);
extern struct gru_tlb_fault_handle *get_tfh_by_index(struct gru_state *gru, int cbrnum);
extern void *get_gseg_base_address_cb(void *base, int ctxnum, int ucbnum);
extern int gru_user_dropin(struct gru_thread_state *gts, struct gru_tlb_fault_handle *tfh, void *cbk);