#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

typedef uint32_t u32;
typedef uint8_t u8;

typedef enum {
    GF_FALSE = 0,
    GF_TRUE = 1
} Bool;

typedef struct GF_Box {
    // base box fields
} GF_Box;

typedef struct GF_List {
    // list implementation
} GF_List;

typedef struct GF_MovieFragmentBox {
    GF_List *TrackList;
} GF_MovieFragmentBox;

typedef struct GF_TrackFragmentHeaderBox {
    u32 trackID;
} GF_TrackFragmentHeaderBox;

typedef struct GF_SampleDependencyTypeBox {
    u32 sampleCount;
    u8 *sample_info;
} GF_SampleDependencyTypeBox;

typedef struct GF_TrunEntry {
    u32 flags;
} GF_TrunEntry;

typedef struct GF_TrackFragmentRunBox {
    u32 flags;
    u32 nb_samples;
    GF_TrunEntry *samples;
} GF_TrackFragmentRunBox;

typedef struct GF_TrackFragmentBox {
    GF_SampleDependencyTypeBox *sdtp;
    GF_List *TrackRuns;
    GF_TrackFragmentHeaderBox *tfhd;
    GF_List child_boxes;
} GF_TrackFragmentBox;

#define GF_LOG_WARNING 1
#define GF_LOG_ERROR 2
#define GF_LOG_CONTAINER 3
#define GF_ISOM_TRUN_FLAGS 0x000100
#define GF_ISOM_TRUN_FIRST_FLAG 0x020000
#define GF_ISOM_GET_FRAG_DEPEND_FLAGS(a,b,c,d) (((a)&0x3)<<24)|(((b)&0x3)<<16)|(((c)&0x3)<<8)|((d)&0x3)

void GF_LOG(int level, int category, const char *format, ...);
u32 gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);
void *gf_list_enum(GF_List *list, u32 *index);
void gf_isom_box_del_parent(GF_List *parent, GF_Box *child);