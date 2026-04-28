#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef int GF_Err;
typedef bool Bool;

#define GF_OK 0
#define GF_BAD_PARAM 1
#define GF_NOT_SUPPORTED 2

#define GF_ISOM_MEDIA_AUDIO 1
#define GF_ISOM_MEDIA_VISUAL 2
#define GF_ISOM_MEDIA_TEXT 3
#define GF_ISOM_MEDIA_SUBT 4
#define GF_ISOM_MEDIA_MPEG_SUBT 5
#define GF_ISOM_MEDIA_CLOSED_CAPTION 6
#define GF_ISOM_MEDIA_AUXV 7
#define GF_ISOM_MEDIA_PICT 8
#define GF_ISOM_MEDIA_QTVR 9
#define GF_ISOM_MEDIA_FLASH 10
#define GF_ISOM_MEDIA_DIMS 11
#define GF_ISOM_MEDIA_SCENE 12
#define GF_ISOM_MEDIA_OD 13
#define GF_ISOM_MEDIA_META 14
#define GF_ISOM_MEDIA_TIMECODE 15
#define GF_ISOM_MEDIA_HINT 16
#define GF_ISOM_MEDIA_SUBPIC 17
#define GF_ISOM_SUBTYPE_TEXT 18
#define GF_ISOM_SUBTYPE_HVT1 19

#define GF_STREAM_AUDIO 1
#define GF_STREAM_VISUAL 2
#define GF_STREAM_TEXT 3
#define GF_STREAM_SCENE 4
#define GF_STREAM_OD 5
#define GF_STREAM_METADATA 6
#define GF_STREAM_UNKNOWN 7
#define GF_STREAM_FILE 8

#define GF_ISOM_REF_SCAL 1
#define GF_ISOM_REF_BASE 2
#define GF_ISOM_REF_CHAP 3

#define GF_ISOM_ITUNE_COVER_ART 1

#define MP4DMX_SINGLE 1

#define GF_LOG_ERROR 1
#define GF_LOG_WARNING 2
#define GF_LOG_CONTAINER 3

#define GF_PROP_PID_STREAM_TYPE 1

#define GF_TRUE true
#define GF_FALSE false

typedef struct GF_Descriptor GF_Descriptor;
typedef struct GF_ObjectDescriptor GF_ObjectDescriptor;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_FilterPacket GF_FilterPacket;
typedef struct GF_List GF_List;

struct GF_ObjectDescriptor {
    GF_List *ESDescriptors;
};

typedef struct {
    u32 stsd;
    char *tkid;
    Bool allt;
    Bool alltk;
    u32 smode;
    u32 play_only_track_id;
    u32 play_only_first_media;
    Bool expart;
    Bool itt;
    GF_List *channels;
    void *mov;
    void *filter;
} ISOMReader;

typedef struct {
    u32 uint;
} GF_PropertyValue;

#define GF_4CC(a,b,c,d) ((a)<<24 | (b)<<16 | (c)<<8 | (d))
#define PROP_UINT(x) ((GF_PropertyValue){.uint = x})

void GF_LOG(int level, int category, const char *fmt, ...);
u32 gf_list_count(GF_List *list);
void gf_odf_desc_del(GF_Descriptor *desc);
u32 gf_isom_get_track_count(void *mov);
u32 gf_isom_get_media_type(void *mov, u32 track);
u32 gf_isom_get_track_id(void *mov, u32 track);
const char *gf_4cc_to_str(u32 type);
Bool gf_isom_is_track_enabled(void *mov, u32 track);
Bool gf_isom_is_track_referenced(void *mov, u32 track, u32 ref_type);
u32 gf_isom_get_media_subtype(void *mov, u32 track, u32 stsd_idx);
Bool gf_isom_has_track_reference(void *mov, u32 track, u32 ref_type, u32 ref_track_id);
GF_Descriptor *gf_isom_get_root_od(void *mov);
u32 gf_isom_get_meta_item_count(void *mov, Bool root, u32 item_id);
GF_Err gf_isom_apple_get_tag(void *mov, u32 tag_type, const u8 **tag, u32 *tlen);
GF_Err gf_filter_pid_raw_new(void *filter, void *pid1, void *pid2, void *pid3, void *pid4, char *data, u32 size, Bool copy, GF_FilterPid **out_pid);
void gf_filter_pid_set_property(GF_FilterPid *pid, u32 prop, GF_PropertyValue *value);
void gf_filter_pid_set_name(GF_FilterPid *pid, const char *name);
GF_FilterPacket *gf_filter_pck_new_alloc(GF_FilterPid *pid, u32 size, u8 **out_buffer);
void gf_filter_pck_set_framing(GF_FilterPacket *pck, Bool start, Bool end);
void gf_filter_pck_send(GF_FilterPacket *pck);
void gf_filter_pid_set_eos(GF_FilterPid *pid);
const char *gf_error_to_string(GF_Err e);

GF_Err isor_declare_track(ISOMReader *read, void *arg, u32 track, u32 stsd_idx, u32 streamtype, Bool use_iod);
Bool isor_declare_item_properties(ISOMReader *read, void *arg, u32 item_id);