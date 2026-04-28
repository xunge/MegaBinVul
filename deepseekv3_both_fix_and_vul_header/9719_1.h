#include <stdlib.h>
#include <errno.h>

#define SNDRV_SEQ_OSS_MAX_CLIENTS 16
#define SNDRV_SEQ_OSS_MODE_MUSIC 0
#define GFP_KERNEL 0
#define KERN_ERR 0

struct file {
    void *private_data;
};

struct snd_seq_addr {
    int client;
    int port;
};

struct seq_oss_devinfo {
    int cseq;
    int port;
    int queue;
    int index;
    int synth_opened;
    int max_mididev;
    struct snd_seq_addr addr;
    int seq_mode;
    int file_mode;
    void *readq;
    void *writeq;
    void *timer;
};

static struct seq_oss_devinfo *client_table[SNDRV_SEQ_OSS_MAX_CLIENTS];
static int num_clients;
static int system_client;
static int maxqlen;

#define debug_printk(args)
#define snd_printk(fmt, ...)
#define kzalloc(size, flags) calloc(1, size)
#define kfree(ptr) free(ptr)

#define snd_seq_oss_synth_setup(dp)
#define snd_seq_oss_midi_setup(dp)
#define create_port(dp) 0
#define alloc_seq_queue(dp) 0
#define translate_mode(file) 0
#define is_read_mode(mode) 0
#define is_write_mode(mode) 0
#define snd_seq_oss_readq_new(dp, len) NULL
#define snd_seq_oss_writeq_new(dp, len) NULL
#define snd_seq_oss_timer_new(dp) NULL
#define snd_seq_oss_synth_setup_midi(dp)
#define snd_seq_oss_midi_open_all(dp, mode)
#define snd_seq_oss_writeq_delete(wq)
#define snd_seq_oss_readq_delete(rq)
#define snd_seq_oss_synth_cleanup(dp)
#define snd_seq_oss_midi_cleanup(dp)
#define delete_port(dp)
#define delete_seq_queue(q)