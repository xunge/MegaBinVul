#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef uint64_t u64;
typedef uint16_t u16;
typedef int32_t GF_ISOTrackID;
typedef int32_t GF_Err;
typedef bool Bool;

#define GF_ISOM_OPEN_WRITE 1
#define GF_ISOM_OPEN_EDIT 2
#define GF_ISOM_MEDIA_HINT 0x68696E74
#define GF_ISOM_MEDIA_VISUAL 0x76696465
#define GF_ISOM_MEDIA_AUXV 0x61757876
#define GF_ISOM_MEDIA_PICT 0x70696374
#define GF_ISOM_MEDIA_SCENE 0x7363656E
#define GF_ISOM_MEDIA_TEXT 0x74657874
#define GF_ISOM_MEDIA_SUBT 0x73756274
#define GF_ISOM_MEDIA_AUDIO 0x736F756E
#define GF_BAD_PARAM 1
#define GF_OUT_OF_MEM 2
#define GF_ISOM_BOX_TYPE_MOOV 0x6D6F6F76
#define GF_ISOM_BOX_TYPE_TRAK 0x7472616B
#define GF_ISOM_BOX_TYPE_TKHD 0x746B6864
#define GF_TRUE true
#define GF_FALSE false
#define GF_ISOM_BS_COOKIE_NO_LOGS 1
#define GF_ISOM_BS_COOKIE_CLONE_TRACK 2
#define GF_BITSTREAM_READ 0

typedef struct GF_ISOFile {
    struct {
        struct {
            u32 nextTrackID;
        } *mvhd;
        struct GF_List *child_boxes;
    } *moov;
    u32 last_created_track_id;
    Bool keep_utc;
} GF_ISOFile;

typedef struct GF_Box GF_Box;
typedef struct GF_List GF_List;

typedef struct GF_TrackBox {
    struct GF_TrackHeaderBox *Header;
    struct GF_MediaBox *Media;
    struct GF_UserDataBox *udta;
    struct GF_List *child_boxes;
} GF_TrackBox;

typedef struct GF_TrackHeaderBox {
    u32 trackID;
    u64 creationTime;
    u64 modificationTime;
    u32 width;
    u32 height;
    u16 volume;
    u64 duration;
} GF_TrackHeaderBox;

typedef struct GF_MediaBox {
    struct {
        u64 creationTime;
        u64 modificationTime;
        u32 timeScale;
        u64 duration;
    } *mediaHeader;
    struct {
        u32 handlerType;
    } *handler;
    void *information;
    struct GF_TrackBox *mediaTrack;
} GF_MediaBox;

typedef struct GF_UserDataBox GF_UserDataBox;
typedef struct GF_BitStream GF_BitStream;

GF_Err CanAccessMovie(GF_ISOFile *movie, int mode);
void gf_isom_set_last_error(GF_ISOFile *movie, GF_Err e);
GF_Err gf_isom_insert_moov(GF_ISOFile *movie);
Bool RequestTrack(void *moov, GF_ISOTrackID trakID);
GF_BitStream *gf_bs_new(u8 *data, u32 size, int mode);
void gf_bs_set_cookie(GF_BitStream *bs, int flags);
GF_Err gf_isom_box_parse_ex(GF_Box **box, GF_BitStream *bs, int type, Bool skip, u64 parent_size);
void gf_bs_del(GF_BitStream *bs);
void gf_list_del_item(GF_List *list, void *item);
void gf_isom_box_del(GF_Box *box);
GF_Err NewMedia(GF_MediaBox **mdia, u32 MediaType, u32 TimeScale);
u64 gf_isom_get_mp4time();
GF_Box *gf_isom_box_new_parent(GF_List **parent, int type);
GF_Err trak_on_child_box(GF_Box *trak, GF_Box *child, Bool is_rem);
Bool gf_sys_is_test_mode();
GF_Err moov_on_child_box(GF_Box *moov, GF_Box *child, Bool is_rem);
u32 gf_isom_get_track_by_id(GF_ISOFile *movie, GF_ISOTrackID trakID);
GF_List *gf_list_new();
void gf_list_add(GF_List *list, void *item);

#define GF_EXPORT