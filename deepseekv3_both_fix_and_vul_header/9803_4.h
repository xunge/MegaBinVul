#include <stddef.h>

struct file;

struct snd_hwdep {
    void *private_data;
};

struct hdspm {
    void *iobase;
    void *lock;
    unsigned int system_sample_rate;
    unsigned int firmware_rev;
    void *mixer;
};

struct hdspm_mixer_ioctl {
    void *mixer;
};

struct hdspm_config_info {
    int pref_sync_ref;
    int wordclock_sync_check;
    unsigned int system_sample_rate;
    unsigned int autosync_sample_rate;
    int system_clock_mode;
    int clock_source;
    int autosync_ref;
    int line_out;
    int passthru;
};

struct hdspm_version {
    unsigned int firmware_rev;
};

struct hdspm_peak_rms_ioctl {
    void *peak;
};

struct hdspm_peak_rms {
    int dummy;
};

struct hdspm_mixer {
    int dummy;
};

#define SNDRV_HDSPM_IOCTL_GET_PEAK_RMS 1
#define SNDRV_HDSPM_IOCTL_GET_CONFIG_INFO 2
#define SNDRV_HDSPM_IOCTL_GET_VERSION 3
#define SNDRV_HDSPM_IOCTL_GET_MIXER 4

#define HDSPM_MADI_peakrmsbase 0
#define EFAULT 1
#define EINVAL 2

#define __user

static inline int copy_from_user(void *to, const void *from, size_t n) { return 0; }
static inline int copy_to_user(void *to, const void *from, size_t n) { return 0; }
static inline int copy_to_user_fromio(void *to, const void *from, size_t n) { return 0; }

static inline void spin_lock_irq(void *lock) {}
static inline void spin_unlock_irq(void *lock) {}

static inline int hdspm_pref_sync_ref(struct hdspm *hdspm) { return 0; }
static inline int hdspm_wc_sync_check(struct hdspm *hdspm) { return 0; }
static inline int hdspm_external_sample_rate(struct hdspm *hdspm) { return 0; }
static inline int hdspm_system_clock_mode(struct hdspm *hdspm) { return 0; }
static inline int hdspm_clock_source(struct hdspm *hdspm) { return 0; }
static inline int hdspm_autosync_ref(struct hdspm *hdspm) { return 0; }
static inline int hdspm_line_out(struct hdspm *hdspm) { return 0; }