#include <stdint.h>

typedef uint32_t u32;
typedef int32_t GF_Err;

#define GF_OK 0
#define GF_ISOM_BOX_TYPE_VWID 0x76776964
#define GF_ISOM_BOX_TYPE_ST3D 0x73743364
#define GF_ISOM_BOX_TYPE_SV3D 0x73763364

typedef struct GF_Box GF_Box;
typedef struct GF_VisualSampleEntryBox GF_VisualSampleEntryBox;
typedef struct GF_MPEGVisualSampleEntryBox GF_MPEGVisualSampleEntryBox;

struct GF_Box {
    GF_Box *child_boxes;
};

struct GF_VisualSampleEntryBox {
    GF_Box box;
};

struct GF_MPEGVisualSampleEntryBox {
    GF_VisualSampleEntryBox vse;
    void *esd;
    void *cfg_3gpp;
    void *avc_config;
    void *svc_config;
    void *mvc_config;
    void *hevc_config;
    void *lhvc_config;
    void *vvc_config;
    void *av1_config;
    void *vp_config;
    void *jp2h;
    void *dovi_config;
    GF_Box *child_boxes;
};

extern GF_Err gf_isom_video_sample_entry_size(GF_VisualSampleEntryBox *s);
extern GF_Err gf_isom_check_position(GF_Box *s, GF_Box *box, u32 *pos);
extern GF_Box *gf_isom_box_find_child(GF_Box *child_boxes, u32 box_type);