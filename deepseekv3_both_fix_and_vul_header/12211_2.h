#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <inttypes.h>

typedef uint32_t u32;
#define LLD PRId64

typedef enum {
    GF_OK,
    GF_EOS,
    GF_ISOM_INCOMPLETE_FILE,
    GF_ISOM_INVALID_FILE
} GF_Err;

typedef enum {
    GF_ISOM_SEARCH_FORWARD,
    GF_ISOM_SEARCH_SYNC_BACKWARD
} GF_ISOM_SearchMode;

typedef enum {
    GF_FALSE,
    GF_TRUE
} Bool;

typedef enum {
    RAP_REDUNDANT
} RAPType;

typedef enum {
    GF_LOG_ERROR,
    GF_LOG_DEBUG,
    GF_LOG_WARNING,
    GF_LOG_CONTAINER
} GF_LogLevel;

typedef struct GF_ISOSample {
    uint32_t alloc_size;
    uint32_t dataLength;
    uint8_t IsRAP;
    int64_t DTS;
    int64_t CTS_Offset;
    uint32_t duration;
    uint32_t nb_pack;
    uint8_t *data;
} GF_ISOSample;

typedef enum {
    GF_ISOSampleRollType_None
} GF_ISOSampleRollType;

typedef struct ISOMOwner {
    void *mov;
    uint32_t nodata;
    uint32_t frag_type;
    uint32_t mem_load_mode;
    uint32_t input_loaded;
    uint32_t stsd;
    uint32_t force_fetch;
    int64_t last_sender_ntp;
    int64_t cts_for_last_sender_ntp;
    int64_t ntp_at_last_sender_ntp;
} ISOMOwner;

typedef struct ISOMChannel {
    GF_ISOSample *sample;
    GF_ISOSample *static_sample;
    uint32_t track;
    uint32_t next_track;
    uint32_t sample_num;
    uint32_t sample_last;
    uint32_t last_sample_desc_index;
    uint32_t sample_data_offset;
    uint32_t edit_sync_frame;
    uint32_t sap_only;
    uint32_t sap_4_type;
    uint32_t roll;
    uint32_t isLeading;
    uint32_t dependsOn;
    uint32_t dependedOn;
    uint32_t redundant;
    uint32_t to_init;
    uint32_t has_edit_list;
    uint32_t has_rap;
    uint32_t hint_first_tfdt;
    uint32_t needs_pid_reconfig;
    uint32_t is_encrypted;
    uint32_t pck_encrypted;
    uint32_t playing;
    uint32_t seek_flag;
    uint32_t eos_sent;
    uint32_t last_state;
    int32_t speed;
    int64_t sample_time;
    int64_t last_rap_sample_time;
    int64_t start;
    int64_t end;
    int64_t dts;
    int64_t cts;
    int64_t sender_ntp;
    int64_t ntp_at_server_ntp;
    ISOMOwner *owner;
    void *pck;
    Bool sap_3;
} ISOMChannel;

void gf_isom_set_sample_alloc(void *mov, uint32_t track, void *alloc, ISOMChannel *ch);
void init_reader(ISOMChannel *ch);
GF_Err gf_isom_get_sample_for_movie_time(void *mov, uint32_t track, int64_t time, uint32_t *desc_index, GF_ISOM_SearchMode mode, GF_ISOSample **sample, uint32_t *sample_num, uint32_t *offset);
GF_ISOSample *gf_isom_get_sample_ex(void *mov, uint32_t track, uint32_t sample_num, uint32_t *desc_index, GF_ISOSample *sample, uint32_t *offset);
GF_ISOSample *gf_isom_get_sample_info_ex(void *mov, uint32_t track, uint32_t sample_num, uint32_t *desc_index, uint32_t *offset, GF_ISOSample *sample);
uint32_t gf_isom_get_sample_count(void *mov, uint32_t track);
uint32_t gf_isom_get_sample_duration(void *mov, uint32_t track, uint32_t sample_num);
Bool gf_isom_get_sample_sync(void *mov, uint32_t track, uint32_t sample_num);
void gf_isom_get_sample_rap_roll_info(void *mov, uint32_t track, uint32_t sample_num, Bool *sap_3, uint32_t *sap_4_type, uint32_t *roll);
void gf_isom_get_sample_flags(void *mov, uint32_t track, uint32_t sample_num, uint32_t *isLeading, uint32_t *dependsOn, uint32_t *dependedOn, uint32_t *redundant);
Bool gf_isom_is_cenc_media(void *mov, uint32_t track, uint32_t desc_index);
Bool gf_isom_is_media_encrypted(void *mov, uint32_t track, uint32_t desc_index);
void isor_update_cenc_info(ISOMChannel *ch, Bool flag);
void gf_filter_pck_discard(void *pck);
uint32_t gf_isom_get_missing_bytes(void *mov, uint32_t track);
int64_t gf_isom_get_current_tfdt(void *mov, uint32_t track);
GF_Err gf_isom_last_error(void *mov);
const char *gf_error_to_string(GF_Err e);
void GF_LOG(GF_LogLevel level, GF_LogLevel domain, const char *format, ...);
void isor_sample_alloc(void *mov, uint32_t track, GF_ISOSample *sample, void *udta);