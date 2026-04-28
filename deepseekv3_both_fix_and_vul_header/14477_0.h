#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef int GF_Err;
#define GF_OK 0
#define GF_BAD_PARAM -1
#define GF_ISOM_INVALID_FILE -2
#define GF_ISOM_OPEN_WRITE 1

#define GF_EXPORT

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_3GPConfig GF_3GPConfig;
typedef struct GF_MPEGAudioSampleEntryBox GF_MPEGAudioSampleEntryBox;
typedef struct GF_MPEGVisualSampleEntryBox GF_MPEGVisualSampleEntryBox;

struct GF_3GPConfig {
    u32 type;
};

struct GF_MPEGAudioSampleEntryBox {
    u32 type;
    u32 internal_type;
    struct {
        GF_3GPConfig cfg;
    } *cfg_3gpp;
};

struct GF_MPEGVisualSampleEntryBox {
    u32 internal_type;
    struct {
        GF_3GPConfig cfg;
    } *cfg_3gpp;
};

struct GF_TrackBox {
    struct {
        struct {
            struct {
                struct {
                    void **child_boxes;
                } *SampleDescription;
            } *sampleTable;
        } *information;
    } *Media;
};

#define GF_ISOM_SUBTYPE_3GP_AMR 0
#define GF_ISOM_SUBTYPE_3GP_AMR_WB 1
#define GF_ISOM_SUBTYPE_3GP_EVRC 2
#define GF_ISOM_SUBTYPE_3GP_QCELP 3
#define GF_ISOM_SUBTYPE_3GP_SMV 4
#define GF_ISOM_SUBTYPE_3GP_H263 5
#define GF_ISOM_SAMPLE_ENTRY_AUDIO 0
#define GF_ISOM_SAMPLE_ENTRY_VIDEO 1

GF_Err CanAccessMovie(GF_ISOFile *the_file, u32 mode);
GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);