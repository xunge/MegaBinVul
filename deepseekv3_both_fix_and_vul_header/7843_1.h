#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

typedef uint32_t u32;
typedef int32_t GF_Err;
typedef int32_t Bool;
#define GF_TRUE 1
#define GF_FALSE 0
#define GF_OK 0
#define GF_EOS 1
#define GF_ISOM_INCOMPLETE_FILE 2
#define GF_ISOM_INVALID_FILE 3

typedef enum {
    GF_LOG_ERROR,
    GF_LOG_DEBUG,
    GF_LOG_WARNING,
    GF_LOG_CONTAINER,
    GF_LOG_DASH
} GF_LogLevel;

typedef enum {
    GF_ISOM_SEARCH_FORWARD,
    GF_ISOM_SEARCH_SYNC_BACKWARD
} GF_ISOMSearchMode;

typedef enum {
    RAP_REDUNDANT
} RAPType;

typedef enum {
    GF_ISOSampleRollType_NONE
} GF_ISOSampleRollType;

typedef struct {
    u32 DTS;
    u32 CTS_Offset;
    u32 IsRAP;
    u32 nb_pack;
    void* data;
} GF_ISOSample;

typedef struct {
    u32 track;
    u32 next_track;
    u32 sample_num;
    u32 last_sample_desc_index;
    u32 sample_data_offset;
    u32 edit_sync_frame;
    u32 sap_only;
    u32 sap_4_type;
    u32 roll;
    u32 set_disc;
    u32 isLeading;
    u32 dependsOn;
    u32 dependedOn;
    u32 redundant;
    u32 pck_encrypted;
    u32 has_edit_list;
    u32 has_rap;
    u32 to_init;
    u32 speed;
    u32 last_state;
    u32 playing;
    u32 seek_flag;
    u32 au_duration;
    u32 sap_3;
    u32 is_encrypted;
    u32 last_rap_sample_time;
    u32 sample_time;
    u32 start;
    u32 end;
    u32 dts;
    u32 cts;
    u32 sender_ntp;
    u32 ntp_at_server_ntp;
    u32 needs_pid_reconfig;
    GF_ISOSample* sample;
    GF_ISOSample* static_sample;
    struct {
        void* mov;
        u32 frag_type;
        u32 mem_load_mode;
        u32 force_fetch;
        u32 input_loaded;
        u32 stsd;
        u32 clock_discontinuity;
        u32 last_sender_ntp;
        u32 cts_for_last_sender_ntp;
        u32 ntp_at_last_sender_ntp;
        u32 nodata;
    } *owner;
} ISOMChannel;

void init_reader(ISOMChannel* ch);
GF_Err gf_isom_get_sample_for_movie_time(void* mov, u32 track, u32 time, u32* sample_desc_index, GF_ISOMSearchMode mode, GF_ISOSample** sample, u32* sample_num, u32* offset);
GF_ISOSample* gf_isom_get_sample_ex(void* mov, u32 track, u32 sample_num, u32* sample_desc_index, GF_ISOSample* static_sample, u32* offset);
GF_ISOSample* gf_isom_get_sample_info_ex(void* mov, u32 track, u32 sample_num, u32* sample_desc_index, u32* offset, GF_ISOSample* static_sample);
Bool gf_isom_get_sample_sync(void* mov, u32 track, u32 sample_num);
void gf_isom_get_sample_rap_roll_info(void* mov, u32 track, u32 sample_num, Bool* is_rap, GF_ISOSampleRollType* roll_type, u32* roll);
u32 gf_isom_get_sample_count(void* mov, u32 track);
u32 gf_isom_get_sample_duration(void* mov, u32 track, u32 sample_num);
u32 gf_isom_get_current_tfdt(void* mov, u32 track);
u32 gf_isom_get_missing_bytes(void* mov, u32 track);
GF_Err gf_isom_last_error(void* mov);
void gf_isom_get_sample_flags(void* mov, u32 track, u32 sample_num, u32* isLeading, u32* dependsOn, u32* dependedOn, u32* redundant);
Bool gf_isom_is_cenc_media(void* mov, u32 track, u32 sample_desc_index);
Bool gf_isom_is_media_encrypted(void* mov, u32 track, u32 sample_desc_index);
void isor_update_cenc_info(ISOMChannel* ch, Bool flag);
void GF_LOG(GF_LogLevel level1, GF_LogLevel level2, const char* fmt, ...);
const char* gf_error_to_string(GF_Err e);

#define LLD "%lld"