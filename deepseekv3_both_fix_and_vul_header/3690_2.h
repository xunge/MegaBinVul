#include <stdlib.h>
#include <string.h>

#define MAX_USER_CONTROLS 32
#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22
#define EBUSY 16
#define ENOENT 2

#define SNDRV_CTL_ELEM_ACCESS_READWRITE 0x0003
#define SNDRV_CTL_ELEM_ACCESS_INACTIVE 0x0008
#define SNDRV_CTL_ELEM_ACCESS_TLV_READWRITE 0x0006
#define SNDRV_CTL_ELEM_ACCESS_USER 0x0010
#define SNDRV_CTL_ELEM_ACCESS_READ 0x0001
#define SNDRV_CTL_ELEM_ACCESS_WRITE 0x0002
#define SNDRV_CTL_ELEM_ACCESS_TLV_CALLBACK 0x0020

enum {
    SNDRV_CTL_ELEM_TYPE_BOOLEAN,
    SNDRV_CTL_ELEM_TYPE_INTEGER,
    SNDRV_CTL_ELEM_TYPE_INTEGER64,
    SNDRV_CTL_ELEM_TYPE_ENUMERATED,
    SNDRV_CTL_ELEM_TYPE_BYTES,
    SNDRV_CTL_ELEM_TYPE_IEC958
};

struct snd_ctl_elem_id {
    int numid;
};

struct snd_ctl_elem_value {
    int dummy;
};

struct snd_ctl_elem_info {
    struct snd_ctl_elem_id id;
    unsigned int access;
    unsigned int count;
    unsigned int owner;
    unsigned int type;
    union {
        struct {
            unsigned int items;
        } enumerated;
    } value;
};

struct snd_kcontrol_volatile {
    struct snd_ctl_file *owner;
};

struct snd_kcontrol {
    struct snd_ctl_elem_id id;
    unsigned int count;
    int (*info)(struct snd_kcontrol *, struct snd_ctl_elem_info *);
    int (*get)(struct snd_kcontrol *, struct snd_ctl_elem_value *);
    int (*put)(struct snd_kcontrol *, struct snd_ctl_elem_value *);
    struct {
        int (*c)(struct snd_kcontrol *, int, unsigned int, unsigned int *);
    } tlv;
    void (*private_free)(struct snd_kcontrol *);
    void *private_data;
    struct snd_kcontrol_volatile *vd;
};

struct rw_semaphore {
    int dummy;
};

struct snd_card {
    unsigned int user_ctl_count;
    struct rw_semaphore controls_rwsem;
};

struct snd_ctl_file {
    struct snd_card *card;
};

struct user_element {
    struct snd_card *card;
    struct snd_ctl_elem_info info;
    char *elem_data;
    size_t elem_data_size;
    void *priv_data;
};

struct snd_aes_iec958 {
    unsigned char status[24];
    unsigned char subcode[147];
    unsigned char pad;
    unsigned char dig_subframe[4];
};

static inline void down_write(struct rw_semaphore *sem) {}
static inline void up_write(struct rw_semaphore *sem) {}

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void kfree(void *ptr) { free(ptr); }

static int snd_ctl_elem_init_enum_names(struct user_element *ue) { return 0; }
static void snd_ctl_elem_user_free(struct snd_kcontrol *kcontrol) {}
static int snd_ctl_elem_user_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol) { return 0; }
static int snd_ctl_elem_user_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol) { return 0; }
static int snd_ctl_elem_user_tlv(struct snd_kcontrol *kcontrol, int op_flag, unsigned int size, unsigned int *tlv) { return 0; }
static int snd_ctl_elem_user_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo) { return 0; }
static int snd_ctl_elem_user_enum_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo) { return 0; }
static struct snd_kcontrol *snd_ctl_find_id(struct snd_card *card, struct snd_ctl_elem_id *id) { return NULL; }
static int snd_ctl_remove(struct snd_card *card, struct snd_kcontrol *kcontrol) { return 0; }
static struct snd_kcontrol *snd_ctl_new(struct snd_kcontrol *kcontrol, unsigned int access) { return NULL; }
static int snd_ctl_add(struct snd_card *card, struct snd_kcontrol *kcontrol) { return 0; }