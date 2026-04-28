#include <stdio.h>
#include <stdint.h>
#include <errno.h>

struct snd_hwdep {
    void *private_data;
};

struct file;

struct hdsp {
    unsigned int state;
    int io_type;
    unsigned int system_sample_rate;
    unsigned int ss_in_channels;
    unsigned int ss_out_channels;
    unsigned int firmware_rev;
    void *card;
    void *lock;
    void *firmware_cache;
    void *mixer_matrix;
};

struct hdsp_peak_rms {
    int dummy;
};

struct hdsp_config_info {
    unsigned char pref_sync_ref;
    unsigned char wordclock_sync_check;
    unsigned char adatsync_sync_check;
    unsigned char spdif_sync_check;
    unsigned char adat_sync_check[3];
    unsigned char spdif_in;
    unsigned char spdif_out;
    unsigned char spdif_professional;
    unsigned char spdif_emphasis;
    unsigned char spdif_nonaudio;
    unsigned int spdif_sample_rate;
    unsigned int system_sample_rate;
    unsigned int autosync_sample_rate;
    unsigned char system_clock_mode;
    unsigned char clock_source;
    unsigned char autosync_ref;
    unsigned char line_out;
    unsigned char da_gain;
    unsigned char ad_gain;
    unsigned char phone_gain;
    unsigned char xlr_breakout_cable;
    unsigned char analog_extension_board;
};

struct hdsp_9632_aeb {
    int aebi;
    int aebo;
};

struct hdsp_version {
    int io_type;
    unsigned int firmware_rev;
};

struct hdsp_firmware {
    uint32_t *firmware_data;
};

struct hdsp_mixer {
    unsigned short matrix[1024];
};

#define SNDRV_HDSP_IOCTL_GET_PEAK_RMS 0
#define SNDRV_HDSP_IOCTL_GET_CONFIG_INFO 1
#define SNDRV_HDSP_IOCTL_GET_9632_AEB 2
#define SNDRV_HDSP_IOCTL_GET_VERSION 3
#define SNDRV_HDSP_IOCTL_UPLOAD_FIRMWARE 4
#define SNDRV_HDSP_IOCTL_GET_MIXER 5

#define HDSP_FirmwareLoaded 0x01
#define HDSP_FirmwareCached 0x02
#define HDSP_InitializationComplete 0x04

#define H9652 0
#define H9632 1
#define Multiface 2
#define Undefined 3

#define HDSP_MATRIX_MIXER_SIZE 1024
#define H9632_SS_CHANNELS 8

#define KERN_ERR ""
#define KERN_INFO ""

#define snd_printk printf
#define spin_lock_irqsave(lock, flags) ((void)0)
#define spin_unlock_irqrestore(lock, flags) ((void)0)
#define copy_to_user(to, from, size) (0)
#define copy_from_user(to, from, size) (0)
#define get_user(x, ptr) (*(x) = *(ptr), 0)
#define __user

typedef uint32_t u32;