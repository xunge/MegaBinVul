#include <errno.h>
#include <stdint.h>

struct i2c_client {
    char *name;
};

struct v4l2_queryctrl {
    int id;
};

struct v4l2_routing {
    int input;
    int output;
};

struct v4l2_tuner {
    int audmode;
    int rxsubchans;
    int capability;
};

#define AUDC_SET_RADIO 0
#define VIDIOC_QUERYCTRL 1
#define VIDIOC_S_CTRL 2
#define VIDIOC_G_CTRL 3
#define VIDIOC_INT_G_AUDIO_ROUTING 4
#define VIDIOC_INT_S_AUDIO_ROUTING 5
#define VIDIOC_S_TUNER 6
#define VIDIOC_G_TUNER 7
#define VIDIOC_S_STD 8
#define VIDIOC_S_FREQUENCY 9
#define VIDIOC_G_CHIP_IDENT 10

#define V4L2_CID_AUDIO_MUTE 0
#define V4L2_CID_AUDIO_VOLUME 1
#define V4L2_CID_AUDIO_BALANCE 2
#define V4L2_CID_AUDIO_BASS 3
#define V4L2_CID_AUDIO_TREBLE 4

#define V4L2_TUNER_MODE_MONO 0
#define V4L2_TUNER_MODE_STEREO 1
#define V4L2_TUNER_MODE_LANG1 2
#define V4L2_TUNER_MODE_LANG2 3
#define V4L2_TUNER_MODE_LANG1_LANG2 4

#define V4L2_TUNER_SUB_MONO 0x01
#define V4L2_TUNER_SUB_STEREO 0x02
#define V4L2_TUNER_SUB_LANG1 0x04
#define V4L2_TUNER_SUB_LANG2 0x08

#define V4L2_TUNER_CAP_STEREO 0x01
#define V4L2_TUNER_CAP_LANG1 0x02
#define V4L2_TUNER_CAP_LANG2 0x04

#define V4L2_IDENT_TVAUDIO 0
#define CHIP_HAS_VOLUME 0x01
#define CHIP_HAS_BASSTREBLE 0x02
#define CHIP_HAS_INPUTSEL 0x04

struct CHIPSTATE;
struct CHIPDESC;

struct CHIPSTATE {
    int type;
    int radio;
    int watch_stereo;
    int input;
    int muted;
    int audmode;
    int mode;
    int prevmode;
    struct i2c_client *c;
    void *wt;
};

struct CHIPDESC {
    unsigned int flags;
    int inputreg;
    int inputmap[4];
    int inputmask;
    void (*setmode)(struct CHIPSTATE *chip, int mode);
    int (*getmode)(struct CHIPSTATE *chip);
    int (*checkmode)(struct CHIPSTATE *chip);
};

extern struct CHIPDESC chiplist[];
extern int debug;

static inline struct CHIPSTATE *i2c_get_clientdata(struct i2c_client *client) { return 0; }
static inline void v4l_dbg(int level, int debug, struct i2c_client *client, const char *fmt, ...) {}
static inline int v4l2_ctrl_query_fill_std(struct v4l2_queryctrl *qc) { return 0; }
static inline int tvaudio_set_ctrl(struct CHIPSTATE *chip, void *arg) { return 0; }
static inline int tvaudio_get_ctrl(struct CHIPSTATE *chip, void *arg) { return 0; }
static inline int v4l2_chip_ident_i2c_client(struct i2c_client *client, void *arg, int ident, int revision) { return 0; }
static inline void chip_write_masked(struct CHIPSTATE *chip, int reg, int val, int mask) {}
static inline void mod_timer(void *timer, unsigned long expires) {}
static inline unsigned long msecs_to_jiffies(unsigned int msecs) { return 0; }
extern unsigned long jiffies;