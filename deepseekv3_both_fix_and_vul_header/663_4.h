#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EINVAL 22
#define ENOMEM 12
#define GFP_KERNEL 0

#define UAC_VERSION_1 0x00
#define UAC_VERSION_2 0x20
#define UAC_VERSION_3 0x30

#define UAC_PROCESS_UP_DOWNMIX 0x0305
#define USB_XU_CLOCK_RATE 0x01
#define UAC_UD_MODE_SELECT 0x01
#define UAC3_UD_MODE_SELECT 0x01
#define USB_MIXER_BOOLEAN 1

typedef uint8_t __u8;
typedef uint16_t __le16;

struct mixer_build {
    void *chip;
    void *map;
    struct {
        int protocol;
    } *mixer;
};

struct procunit_info {
    int type;
    char *name;
    struct procunit_value_info *values;
};

struct procunit_value_info {
    int control;
    char *suffix;
    int val_type;
    int min_value;
};

struct usb_mixer_elem_info {
    struct {
        int id;
    } head;
    int control;
    int val_type;
    int channels;
    int master_readonly;
    int min;
    int max;
    int res;
    int initialized;
};

struct snd_kcontrol {
    struct {
        char name[64];
    } id;
    void (*private_free)(void *);
};

struct snd_kcontrol_new {
    const char *name;
    void *private_data;
};

struct uac_processing_unit_descriptor {
    uint8_t bLength;
    uint8_t bNrInPins;
    __le16 wProcessType;
    uint8_t baSourceID[0];
};

struct usbmix_name_map;

struct snd_kcontrol_new mixer_procunit_ctl = {0};

static inline int le16_to_cpu(__le16 val) { return val; }
static inline int uac_processing_unit_bControlSize(void *desc, int protocol) { return 0; }
static inline __u8 *uac_processing_unit_bmControls(void *desc, int protocol) { return NULL; }
static inline int uac_v2v3_control_is_readable(__u8 controls, int control) { return 0; }
static inline int uac_v2v3_control_is_writeable(__u8 controls, int control) { return 0; }
static inline __u8 *uac_processing_unit_specific(void *desc, int protocol) { return NULL; }
static inline int uac_processing_unit_iProcessing(void *desc, int protocol) { return 0; }
static inline void *kzalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void snd_usb_mixer_elem_free(void *elem) {}
static inline int snd_usb_mixer_add_control(void *head, void *kctl) { return 0; }
static inline void usb_audio_err(void *chip, const char *fmt, ...) {}
static inline void usb_audio_dbg(void *chip, const char *fmt, ...) {}
static inline int parse_audio_unit(void *state, int source) { return 0; }
static inline const struct usbmix_name_map *find_map(void *map, int unitid, int control) { return NULL; }
static inline int check_ignored_ctl(const struct usbmix_name_map *map) { return 0; }
static inline void snd_usb_mixer_elem_init_std(void *head, void *mixer, int unitid) {}
static inline void get_min_max(struct usb_mixer_elem_info *cval, int min_value) {}
static inline void *snd_ctl_new1(struct snd_kcontrol_new *knew, void *private_data) { return NULL; }
static inline int check_mapped_name(const struct usbmix_name_map *map, char *name, size_t len) { return 0; }
static inline size_t strlcpy(char *dest, const char *src, size_t size) { return strncpy(dest, src, size), strlen(src); }
static inline int snd_usb_copy_string_desc(void *chip, int index, char *name, int size) { return 0; }
static inline void append_ctl_name(struct snd_kcontrol *kctl, const char *str) {}