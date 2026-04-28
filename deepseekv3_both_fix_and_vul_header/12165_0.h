#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_ISOSample GF_ISOSample;

struct GF_TrackBox {
    struct {
        struct {
            struct {
                u32 handlerType;
            } *handler;
            struct {
                struct {
                    struct {
                        u32 sampleCount;
                    } *SampleSize;
                } *sampleTable;
            } *information;
        } *Media;
        struct {
            u32 trackID;
        } *Header;
    };
};

struct GF_ISOFile {
    struct {
        void* trackList;
    } *moov;
};

u32 gf_isom_get_track_from_file(GF_ISOFile *file, u32 track);
GF_TrackBox* gf_list_enum(void* list, u32* index);
GF_ISOSample* gf_isom_get_sample(GF_ISOFile *file, u32 track, u32 sample, u32* di);
void gf_isom_sample_del(GF_ISOSample **samp);
u32 Media_FindOD_ID(void* Media, GF_ISOSample* samp, u32 trackID);

#define GF_EXPORT
#define GF_ISOM_MEDIA_OD 0x6F646D