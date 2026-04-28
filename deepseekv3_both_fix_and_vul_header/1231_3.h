#include <stdint.h>
#include <string.h>

typedef struct {
    int dv_mode;
    int nb_dv_rpu;
    int nb_dv_el;
    int width;
    int height;
    struct {
        int num;
        int den;
    } cur_fps;
    int codecid;
    int dv_profile;
    int dv_compatid;
    char *log_name;
    void *opid;
} GF_NALUDmxCtx;

typedef struct GF_BitStream GF_BitStream;

#define DVMODE_NONE 0
#define DVMODE_CLEAN 1
#define DVMODE_AUTO 2

#define GF_LOG_WARNING 1
#define GF_LOG_MEDIA 2
#define GF_BITSTREAM_WRITE 0
#define GF_PROP_PID_DOLBY_VISION 0

typedef uint8_t u8;
typedef uint32_t u32;

typedef struct {
    void *data;
    int size;
} GF_PropertyValue;

#define PROP_DATA(data, size) (GF_PropertyValue){(data), (size)}

void GF_LOG(int level, int category, const char *format, ...);
GF_BitStream *gf_bs_new(void *data, int size, int mode);
void gf_bs_write_u8(GF_BitStream *bs, u8 value);
void gf_bs_write_int(GF_BitStream *bs, int value, int bits);
void gf_bs_write_u32(GF_BitStream *bs, u32 value);
void gf_bs_del(GF_BitStream *bs);
void gf_filter_pid_set_property(void *pid, int property, const GF_PropertyValue *value);
int gf_dolby_vision_level(int width, int height, int num, int den, int codecid);