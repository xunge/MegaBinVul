#include <stdlib.h>
#include <string.h>

struct Scsi_Host {
    void *hostdata[1];
};

struct fc_host_statistics {
    unsigned int seconds_since_last_reset;
    unsigned int tx_frames;
    unsigned int tx_words;
    unsigned int rx_frames;
    unsigned int rx_words;
    unsigned int lip_count;
    unsigned int nos_count;
    unsigned int error_frames;
    unsigned int dumped_frames;
    unsigned int link_failure_count;
    unsigned int loss_of_sync_count;
    unsigned int loss_of_signal_count;
    unsigned int prim_seq_protocol_err_count;
    unsigned int invalid_crc_count;
};

struct bfad_im_port_s {
    struct bfad_s *bfad;
};

struct bfad_s {
    struct fc_host_statistics link_stats;
    void *bfa;
    int bfad_lock;
};

struct bfad_hal_comp {
    int comp;
};

union bfa_port_stats_u {
    struct {
        unsigned int secs_reset;
        unsigned int tx_frames;
        unsigned int tx_words;
        unsigned int rx_frames;
        unsigned int rx_words;
        unsigned int lip_count;
        unsigned int nos_count;
        unsigned int error_frames;
        unsigned int dropped_frames;
        unsigned int link_failures;
        unsigned int loss_of_syncs;
        unsigned int loss_of_signals;
        unsigned int primseq_errs;
        unsigned int invalid_crcs;
    } fc;
};

typedef unsigned int bfa_status_t;
#define BFA_STATUS_OK 0
#define GFP_KERNEL 0

void *bfad_hcb_comp;

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void kfree(void *ptr) { free(ptr); }
static void init_completion(int *comp) { *comp = 0; }
static void wait_for_completion(int *comp) { (void)comp; }
static void spin_lock_irqsave(int *lock, unsigned long flags) { (void)lock; (void)flags; }
static void spin_unlock_irqrestore(int *lock, unsigned long flags) { (void)lock; (void)flags; }
static bfa_status_t bfa_port_get_stats(void *port, union bfa_port_stats_u *stats, void *cb, struct bfad_hal_comp *comp) { 
    (void)port; (void)stats; (void)cb; (void)comp; return BFA_STATUS_OK; 
}
#define BFA_FCPORT(bfa) ((void*)(bfa))