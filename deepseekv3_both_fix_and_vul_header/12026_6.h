#include <stdint.h>
#include <string.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint8_t u8;

#define GF_EXPORT
#define GF_ISOM_OPEN_WRITE 0
#define GF_BAD_PARAM 0
#define GF_ISOM_INVALID_FILE 0
#define GF_OUT_OF_MEM 0
#define GF_OK 0
#define GF_ISOM_BOX_TYPE_MLPA 0
#define GF_ISOM_BOX_TYPE_CHNL 0
#define GF_ISOM_SAMPLE_ENTRY_AUDIO 0
#define GF_IMPORT_AUDIO_SAMPLE_ENTRY_v1_MPEG 0

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_SampleEntryBox GF_SampleEntryBox;
typedef struct GF_AudioSampleEntryBox GF_AudioSampleEntryBox;
typedef struct GF_SampleDescriptionBox GF_SampleDescriptionBox;
typedef struct GF_ChannelLayoutBox GF_ChannelLayoutBox;
typedef struct GF_AudioChannelLayout GF_AudioChannelLayout;
typedef struct GF_MediaHeaderBox GF_MediaHeaderBox;
typedef struct GF_MediaInformationBox GF_MediaInformationBox;
typedef struct GF_SampleTableBox GF_SampleTableBox;
typedef struct GF_MediaBox GF_MediaBox;

struct GF_AudioChannelLayout {
    u32 stream_structure;
    u32 definedLayout;
    u32 channels_count;
};

struct GF_ChannelLayoutBox {
    GF_AudioChannelLayout layout;
};

struct GF_SampleEntryBox {
    u32 internal_type;
    void* child_boxes;
};

struct GF_AudioSampleEntryBox {
    u32 type;
    u32 qtff_mode;
    u32 samplerate_hi;
    u32 samplerate_lo;
    u32 channel_count;
    u32 bitspersample;
    void* child_boxes;
};

struct GF_SampleDescriptionBox {
    void* child_boxes;
};

struct GF_MediaHeaderBox {
    u32 modificationTime;
};

struct GF_SampleTableBox {
    GF_SampleDescriptionBox* SampleDescription;
};

struct GF_MediaInformationBox {
    GF_SampleTableBox* sampleTable;
    GF_MediaHeaderBox* mediaHeader;
};

struct GF_MediaBox {
    GF_MediaInformationBox* information;
    GF_MediaHeaderBox* mediaHeader;
};

struct GF_TrackBox {
    GF_MediaBox* Media;
};

struct GF_ISOFile {
    GF_Err LastError;
    u32 keep_utc;
};

GF_Err CanAccessMovie(GF_ISOFile *movie, u32 mode);
GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile *movie, u32 trackNumber);
u32 gf_isom_get_mp4time();
GF_Err gf_isom_set_audio_info(GF_ISOFile *movie, u32 trackNumber, u32 sampleDescriptionIndex, u32 sr, u32 channel_count, u8 bitspersample, u32 mode);
void* gf_list_get(void* list, u32 index);
u32 gf_list_count(void* list);
void* gf_isom_box_find_child(void* child_boxes, u32 type);
void* gf_isom_box_new_parent(void** child_boxes, u32 type);