#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>

typedef enum {
    GF_FALSE = 0,
    GF_TRUE = 1
} GF_Bool;

typedef enum {
    MEDIA_TYPE_UNKNOWN = 0,
    MEDIA_TYPE_AUDIO = 1,
    MEDIA_TYPE_VIDEO = 2,
    MEDIA_TYPE_SUBTITLES = 3,
    MEDIA_TYPE_CLOSED_CAPTIONS = 4
} MediaType;

typedef enum {
    DRM_NONE = 0,
    DRM_AES_128,
    DRM_CENC
} DRMMethod;

typedef enum {
    GF_LOG_ERROR = 1,
    GF_LOG_INFO,
    GF_LOG_WARNING,
    GF_LOG_DASH
} GF_LogLevel;

typedef int32_t s32;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int64_t s64;
typedef uint8_t u8;

#define LLU "%" PRIu64
#define GROUP_ID_TO_PROGRAM_ID(type, group_id) (type << 24 | (u32)gf_crc_32(group_id))

#define AUDIO MEDIA_TYPE_AUDIO
#define VIDEO MEDIA_TYPE_VIDEO
#define SUBTITLES MEDIA_TYPE_SUBTITLES
#define CLOSED_CAPTIONS MEDIA_TYPE_CLOSED_CAPTIONS

typedef struct {
    char *audio;
    char *video;
    char *subtitle;
    char *closed_captions;
} s_group_ids;

typedef struct s_accumulated_attributes {
    MediaType type;
    GF_Bool is_playlist_ended;
    u32 target_duration_in_seconds;
    u32 min_media_sequence;
    u32 current_media_seq;
    u32 version;
    GF_Bool is_media_segment;
    double duration_in_seconds;
    char *title;
    DRMMethod key_method;
    char *key_url;
    GF_Bool has_iv;
    u8 key_iv[16];
    u64 playlist_utc_timestamp;
    GF_Bool is_master_playlist;
    u32 bandwidth;
    u32 stream_id;
    char *codecs;
    u32 width;
    u32 height;
    s_group_ids group;
    char *mediaURL;
    char *language;
    char *name;
    GF_Bool is_default;
    GF_Bool is_autoselect;
    u32 channels;
    u32 discontinuity;
    u64 byte_range_start;
    u64 byte_range_end;
    char *init_url;
    u64 init_byte_range_start;
    u64 init_byte_range_end;
    GF_Bool independent_segments;
    GF_Bool low_latency;
} s_accumulated_attributes;

#define M3U8_COMPATIBILITY_VERSION(ver) do {} while(0)

static GF_Bool safe_start_equals(const char *prefix, const char *str);
static char **extract_attributes(const char *prefix, const char *line, int max_attrs);
static char *gf_strdup(const char *str);
static void gf_free(void *ptr);
static u32 gf_crc_32(const char *str);
static u64 gf_net_parse_date(const char *date_str);
static void GF_LOG(GF_LogLevel level, GF_LogLevel module, const char *fmt, ...);